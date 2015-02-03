
#include <cmath>

////GLEW includes must precede anything else
#include <GL/glew.h>
#include <GL/wglew.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include "TankGame.h"
#include "Matrix.h"
#include "CONSTS.h"
#include "bass.h"
#include "UVTranslator.h"
#include <vector>
#include <array>

//uncomment below to run tests
//#define MATRIX_TESTS

#ifdef MATRIX_TESTS
#include "TestMatrix.h"
#endif

//#define VECTOR_ANGLE_TESTS
#ifdef VECTOR_ANGLE_TESTS
#include "TestVectorAngle.h"
#endif

using namespace std;

int main()
{
#ifdef MATRIX_TESTS
	RunMatrixTests();
#endif

#ifdef VECTOR_ANGLE_TESTS
	RunVectorAngleTests();
#endif

	//BASS_Init(-1,44100,0,0,0);
	//HSTREAM myStream = BASS_StreamCreateFile(false,"resources/EnemyLaser.mp3",0,0,0);
	//BASS_ChannelSetAttribute(myStream, BASS_ATTRIB_VOL, 0.2f);
	//BASS_ChannelPlay(myStream,false);
	
	cout << "WASD       \tManoeuvre Tank" << endl; 
	cout << "Left/Right \tRotate Turret" << endl;
	cout << "Space      \tFire" << endl;

	//GL Adam Hulbert Library (Gullah)
	//TankGame game;
	//game.Run();

	Initialise(1920, 1080, true, "GLAH Test Tanks");

	unsigned int sprite = CreateSprite("resources/simples_pimples.png", 128, 128, 0, 0);
	//unsigned int sprite = CreateSprite("resources/test.png", 16, 16, 0, 0);

	//get UV
	
	vector<std::array<float, 4>> spriteUVs;
	UVTranslator trans(800,1280,16,16);
	//UVTranslator trans(32,32,16,16);
	for (int row = 0; row < 80; ++row)
	//for (int row = 0; row < 2; ++row)
	{
		for (int col = 0; col < 50; ++col)
		//for (int col = 0; col < 2; ++col)
		{
			std::array<float, 4> uv;
			trans.GetUV(uv.data(), row, col);
			spriteUVs.push_back(uv);
		}
	}
	//trans.GetUV(UV1, 4, 27);
	//trans.GetUV(UV2, 4, 1);
	//trans.GetUV(UV3, 4, 28);

	do
	{
		int x = 0;
		int y = 100;
		for ( auto &UV : spriteUVs )
		{
			SetSpriteUVCoordinates(sprite, UV.data());
			MoveSprite(sprite, x,y);
			DrawSprite(sprite, true);	
			x+=96;
			if ( x >= 1800)
			{
				x = 0;
				y += 96;
			}
		}

		//SetSpriteUVCoordinates(sprite, UV1);
		//MoveSprite(sprite, 100,150);
		//DrawSprite(sprite);	
		//
		//SetSpriteUVCoordinates(sprite, UV2);
		//MoveSprite(sprite, 100,200);
		//DrawSprite(sprite);	

		//SetSpriteUVCoordinates(sprite, UV1);
		//MoveSprite(sprite, 100,250);
		//DrawSprite(sprite, true);	
	}while(FrameworkUpdate());

	BASS_Free();
	return 0;
}