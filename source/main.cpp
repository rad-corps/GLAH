
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

//uncomment below to run tests
//#define MATRIX_TESTS
#ifdef MATRIX_TESTS
#include "Tests.h"
#endif

using namespace std;

int main()
{
#ifdef MATRIX_TESTS
	RunTests();
	return 0; 
#endif

	BASS_Init(-1,44100,0,0,0);
	HSTREAM myStream = BASS_StreamCreateFile(false,"resources/EnemyLaser.mp3",0,0,0);
	BASS_ChannelSetAttribute(myStream, BASS_ATTRIB_VOL, 0.2f);
	BASS_ChannelPlay(myStream,false);
	
	cout << "WASD       \tManoeuvre Tank" << endl; 
	cout << "Left/Right \tRotate Turret" << endl;
	cout << "Space      \tFire" << endl;

	//GL Adam Hulbert Library (Gullah)
	TankGame game;
	game.Run();

	BASS_Free();
	return 0;
}