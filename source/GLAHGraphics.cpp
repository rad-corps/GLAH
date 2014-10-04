#include "GLAHGraphics.h"
#include <GL/glew.h>
#include <GL/wglew.h>
#include <iostream>
//glfw include
#include <GLFW/glfw3.h>
#include "SOIL.h"
#include "Vertex.h"

//initialise static member variables
GLAHGraphics* GLAHGraphics::instance = nullptr;


GLAHGraphics::GLAHGraphics(void)
{
}


GLAHGraphics::~GLAHGraphics(void)
{
}



GLAHGraphics*
GLAHGraphics::Instance()
{
	if ( instance == nullptr )
	{
		instance = new GLAHGraphics();    
	}
	return instance;
}

void			
GLAHGraphics::ScaleSprite( unsigned int spriteID_, float scalar_ )
{
	spriteList[spriteID_].scale = scalar_;
}


//unsigned int	GLAH::CreateSprite	
// a_pTextureName	: filename/path of the texture to load
// a_iWidth			: width of texture
// a_iHeight		: height of texture
// int x_			: initial x position of texture
// int y_			: initial y position of texture
// parentSpriteID_	: sprite ID of sprite to parent to (0 if no parent)
// originOffset_	: the point of rotation, this is relative to the sprites own space. 
//						Default value is Vector3
// a_sColour		: not implemented
unsigned int GLAHGraphics::CreateSprite	( const char* textureName_, 
									 int width_, int height_, 
									 int x_, int y_, 
									 unsigned int parentSpriteID_, 
									 Vector3 originOffset_, 
									 SColour colour_ )
 {
	//Create the texture and get the handle. 
	GLuint texture_handle = SOIL_load_OGL_texture(textureName_, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, NULL);

	//Setup the translation matrix for the sprite
	Matrix3x3 translation;
	translation.SetupTranslation(Vector3(x_, y_, 0.0));

	//add the sprite info to the spriteList (std::map<unsigned int, GLAHSprite>)
	GLAHEntity glahEntity;
	glahEntity.size.x = width_;
	glahEntity.size.y = height_;
	glahEntity.parentSpriteID = parentSpriteID_;
	glahEntity.spriteID = texture_handle;
	glahEntity.translation = translation;	
	glahEntity.origin = originOffset_;
	spriteList[texture_handle] = glahEntity;
	
	//return the sprites ID/Handle
	return texture_handle;
 }

//GLAH::DrawSprite ( unsigned int spriteID_)
void GLAHGraphics::DrawSprite(unsigned int spriteID_)
{
	//get width and height variables
	GLAHEntity entity = spriteList[spriteID_];

	float width = entity.size.x;
	float height = entity.size.y;

	//get parent translation (already populated with rotation/position)
	Matrix3x3 parentTrans;
	if ( spriteList[spriteID_].parentSpriteID != 0 )
	{
		parentTrans = spriteList[entity.parentSpriteID].translation;
	}
	else //if no parent, use an identity matrix for simplicity
	{
		parentTrans.SetupIdentity();
	}
	
	//get the offset from parent and add it to the translatedPosition Vector3
	Vector3 offset = entity.translation.GetPosition();
	Vector3 translatedPosition = parentTrans * offset;
	
	//translation matrix
	Matrix3x3 translationMat;
	translationMat.SetupTranslation(Vector3(translatedPosition.x, translatedPosition.y, 0.0));
	
	//add the child and parent rotations together
	Matrix3x3 rotationMat;
	float rotation = spriteList[spriteList[spriteID_].parentSpriteID].rotation + spriteList[spriteID_].rotation;
	rotationMat.SetupRotation(rotation);

	//Scale Matric
	Matrix3x3 scaleMatrix;
	scaleMatrix.SetupScale(entity.scale);
	
	//create the final transform
	Matrix3x3 transform = scaleMatrix * rotationMat * translationMat;

	//get the locations of the 4 corners of the sprite considering x, y, width, height and rotation
	Vector3 bl = transform * Vector3(0 - spriteList[spriteID_].origin.x, 0 - spriteList[spriteID_].origin.y, 1);
	Vector3 br = transform * Vector3(width - spriteList[spriteID_].origin.x, 0 - spriteList[spriteID_].origin.y, 1);
	Vector3 tl = transform * Vector3(0 - spriteList[spriteID_].origin.x, height - spriteList[spriteID_].origin.y, 1);
	Vector3 tr = transform * Vector3(width - spriteList[spriteID_].origin.x, height - spriteList[spriteID_].origin.y, 1);

	//create the Vertices and send to the GPU
	Vertex vertices[4];
	CreateSpriteVertexData(vertices, tl, tr, bl, br);
	glBindTexture(GL_TEXTURE_2D, spriteID_);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Vertex)*4, vertices);                                          //Updates VBO's data on the fly 
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

//GLAH::DrawSprite
//spriteID_		: The ID of the sprite to draw
//x_			: the absolute (world space) x coordinate to draw 
//y_			: the absolute (world space) y coordinate to draw 
//rotation_		: rotation expressed as radians
void GLAHGraphics::MoveSprite(unsigned int spriteID_, float x_, float y_)
{
	//translation/position matrix
	Matrix3x3 translationMat;
	translationMat.SetupTranslation(Vector3(x_, y_, 0.0));

	//rotation matrix
	Matrix3x3 rotationMat;
	rotationMat.SetupRotation(spriteList[spriteID_].rotation);	

	//scale matrix
	Matrix3x3 scaleMatrix;
	scaleMatrix.SetupScale(spriteList[spriteID_].scale);	

	//transform
	Matrix3x3 transform = scaleMatrix * rotationMat * translationMat;

	//set the transform of the sprite
	spriteList[spriteID_].translation = transform;
}

//GLAH::DrawSpriteRelative
//spriteID_		: The ID of the sprite to draw
//xMovement_	: The Relative x movement (current x position + xMovement_)
//yMovement_	: The Relative y movement (current y position + yMovement_)
//rotation_		: Amount to rotate sprite by expressed as radians (current rotation + rotation_)
void GLAHGraphics::MoveSpriteRelative(unsigned int spriteID_, float xMovement_, float yMovement_, float rotation_)
{		
	//position
	Vector3 pos = spriteList[spriteID_].translation.GetPosition();
	
	//modify rotation
	spriteList[spriteID_].rotation += rotation_;
	
	//create translation/position matrix
	Matrix3x3 translationMat;
	translationMat.SetupTranslation(Vector3(pos.x, pos.y, 0.0));

	//create rotation matrix
	Matrix3x3 rotationMat;
	rotationMat.SetupRotation(spriteList[spriteID_].rotation);

	//create transform matrix
	Matrix3x3 transform = rotationMat * translationMat;
	spriteList[spriteID_].translation = transform;

	//add the x and y movement to the sprite
	Vector3 movement(xMovement_, yMovement_, 0.0);	
	movement = spriteList[spriteID_].translation * movement;
	spriteList[spriteID_].translation.Move(movement);

	return;
}

void GLAHGraphics::RotateSpriteRelative(unsigned int spriteID_, float rotation_ )
{
	spriteList[spriteID_].rotation += rotation_;
}

void GLAHGraphics::RotateSprite(unsigned int spriteID_, float rotation_ )
{
	spriteList[spriteID_].rotation = rotation_;
}



GLAHEntity GLAHGraphics::GetGLAHEntity(unsigned int spriteID_)
{
	return spriteList[spriteID_];
}


//GLAH::CreateSpriteVertexData(Vertex* verticesOut_, Vector3 tl, Vector3 tr, Vector3 bl, Vector3 br)
//verticesOut_	: a pointer to the vertex array to write to (must have space for 4 vertices)
//tl			: top left position
//tr			: top right position
//bl			: bottom left position
//br			: bottom right position
void GLAHGraphics::CreateSpriteVertexData(Vertex* verticesOut_, Vector3 tl, Vector3 tr, Vector3 bl, Vector3 br)
{
	const int VERTICES = 4;
	
	//find the vertices (draw from center)
	verticesOut_[0].position.x = bl.x;              //x - vert0
	verticesOut_[0].position.y = bl.y;             //y - vert0
	verticesOut_[1].position.x = br.x;              //x - vert1
	verticesOut_[1].position.y = br.y;             //y - vert1
	verticesOut_[2].position.x = tr.x;               //x
	verticesOut_[2].position.y = tr.y;             //y
	verticesOut_[3].position.x = tl.x;              //x
	verticesOut_[3].position.y = tl.y;             //y
    for(int i = 0; i < VERTICES; i++)
    {
            verticesOut_[i].position.z = 0.0f;                          //z
			verticesOut_[i].position.w = 1.0f;                          //w
			verticesOut_[i].colour.x = 1.0f;                            //R
            verticesOut_[i].colour.y = 1.0f;                            //G
			verticesOut_[i].colour.z = 1.0f;                            //B
			verticesOut_[i].colour.w = 1.0f;                            //A
    }

	verticesOut_[0].textureCoordinate = Vector2(0.0, 0.0);
	verticesOut_[1].textureCoordinate = Vector2(0.0, 1.0);
	verticesOut_[2].textureCoordinate = Vector2(1.0, 1.0);
	verticesOut_[3].textureCoordinate = Vector2(1.0, 0.0);
}