
#include <cmath>

////GLEW includes must precede anything else
#include <GL/glew.h>
#include <GL/wglew.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include "TankGame.h"
#include "Matrix.h"
#include "CONSTS.h"

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
	

	//GL Adam Hulbert Library (Gullah)
	TankGame game;
	game.Run();

	return 0;
}