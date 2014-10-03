#define _USE_MATH_DEFINES

#include "TankGame.h"
#include <math.h>
#include "GLAHGraphics.h"
#include "CONSTS.h"

TankGame::TankGame() : GLAH(SCREEN_WIDTH, SCREEN_HEIGHT, true, "GLAH Test Tanks")
{
	tank.AddObserver(this);
	gfx = GLAHGraphics::Instance();
	inpt = GLAHInput::Instance();	
}

TankGame::~TankGame()
{
	//NOT IMPLEMENTED YET
	//DeleteSprite(tankSprite);
	//DeleteSprite(turretSprite);
}

void 
TankGame::Draw()
{
	tank.Draw();
}

void
TankGame::OnShoot()
{
	cout << "OnShoot" << endl;
}

void 
TankGame::Update(float delta_)
{	
	tank.Update(delta_);	
}