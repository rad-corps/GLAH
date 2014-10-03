#pragma once

#include <map>
#include "Vertex.h"
#include "GLAHEntity.h"
#include "GLAHColour.h"

using namespace std;


class GLAHGraphics
{
public:
	static GLAHGraphics* Instance();
	~GLAHGraphics();

	void			ClearScreen();

	unsigned int	CreateSprite			( const char* a_pTextureName, 
										 int a_iWidth, int a_iHeight, 
										 int x, int y, 
										 unsigned int parentSpriteID = 0, 
										 Vector3 originOffset_ = Vector3(0.f,0.f,0.f), 
										 SColour a_sColour = SColour(0xFF,0xFF,0xFF,0xFF) );
	GLAHEntity*		CreateEntity		( const char* a_pTextureName, 
										 int a_iWidth, int a_iHeight, 
										 int x, int y, 
										 unsigned int parentSpriteID = 0, 
										 Vector3 originOffset_ = Vector3(0.f,0.f,0.f), 
										 SColour a_sColour = SColour(0xFF,0xFF,0xFF,0xFF) );

	void			MoveSprite				( unsigned int a_uiSpriteID, float a_fXPos, float a_fYPos );
	void			MoveSprite				( unsigned int a_uiSpriteID, float* a_vFloatVec );
	void			MoveSpriteRelative		( unsigned int spriteID_, float xMovement_, float yMovement_, float rotation_);

	void			DrawEntity				( GLAHEntity* entity_);
	void			DrawSprite				( unsigned int a_uiSpriteID);
	
	//draw and move all in one
	void			DrawSprite				( unsigned int a_uiSpriteID, float x_, float y_, float rotation_);

	GLAHEntity		GetGLAHEntity			(unsigned int spriteID_);

	void			RotateSpriteRelative			( unsigned int a_uiSpriteID, float a_fRotation );
	void			RotateSprite					( unsigned int a_uiSpriteID, float a_fRotation );

	void			ScaleSprite				( unsigned int spriteID_, float scalar_ );

	unsigned int	DuplicateSprite			( unsigned int a_uiSpriteID );
	void			DestroySprite			( unsigned int a_uiSpriteID );
	void			SetSpriteColour			( unsigned int a_uiSpriteID, SColour& a_sColour );
	void			GetSpriteColour			( unsigned int a_uiSpriteID, SColour& a_sColour );

	void			SetSpriteMatrix			( unsigned int a_uiSpriteID, float* a_fm4 );
	void			GetSpriteMatrix			( unsigned int a_uiSpriteID, float* a_fm4 );

	//////////////////////////////////////////////////////////////////////////

// Basic Line Drawing Functionality

//////////////////////////////////////////////////////////////////////////

 void			DrawLine( int a_iStartX, int a_iStartY, int a_iEndX, int a_iEndY );

 void			DrawLine( int a_iStartX, int a_iStartY, int a_iEndX, int a_iEndY, SColour a_sColour );

 void			DrawLine( int a_iStartX, int a_iStartY, int a_iEndX, int a_iEndY, SColour a_sStartColour, SColour a_sEndColour );



//////////////////////////////////////////////////////////////////////////

// Draws a String to the screen

//////////////////////////////////////////////////////////////////////////

 void			DrawString( const char* a_pText, int a_iXPos, int a_iYPos, float fSize = 1.f, SColour a_sColour = SColour(0xFF,0xFF,0xFF,0xFF));
 void			AddFont( const char* a_pFontName );
 void			SetFont( const char* a_pFontName );
 void			RemoveFont( const char* a_pFontName );

private:
	void CreateSpriteVertexData(Vertex* verticesOut_, Vector3 tl, Vector3 tr, Vector3 bl, Vector3 br);
	std::map<unsigned int, GLAHEntity> spriteList;

	//private constructor for singleton pattern... ewwww
	GLAHGraphics();
	

	static GLAHGraphics* instance;
};

