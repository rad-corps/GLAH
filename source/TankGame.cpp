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
	for ( int i = 0; i < shells.size(); ++i )
	{
		shells[i].Draw();
	}
}

void
TankGame::OnShoot(Vector3 pos_, float dir_)
{
	shells.push_back(TankShell(pos_, dir_));
}

void 
TankGame::Update(float delta_)
{	
	tank.Update(delta_);	
	
	//update shells
	for ( int i = 0; i < shells.size(); ++i )
	{
		shells[i].Update(delta_);
	}
}