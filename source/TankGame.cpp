#define _USE_MATH_DEFINES

#include "TankGame.h"
#include <math.h>
#include "CONSTS.h"

TankGame::TankGame() : GLAH(SCREEN_WIDTH, SCREEN_HEIGHT, true, "GLAH Test Tanks")
{
	tank.AddObserver(this);

	for ( int i = 0; i < SHELLS_IN_MEMORY; ++i )
	{
		shells.push_back(TankShell());
	}
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
	int shellNum = 0;
	while (shells[shellNum].Active())
	{
		++shellNum;
	}
	shells[shellNum].Shoot(pos_, dir_);
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