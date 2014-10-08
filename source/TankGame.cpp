#define _USE_MATH_DEFINES

#include "TankGame.h"
#include <math.h>
#include "CONSTS.h"

TankGame::TankGame() : GLAH(SCREEN_WIDTH, SCREEN_HEIGHT, true, "GLAH Test Tanks")
{
	//register ourselves as an observer (OnShoot event)
	tank.AddObserver(this);
	tankEnemy.AddObserver(this);

	inpt = GLAHInput::Instance();

	//create the TankShell vector
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

//draw all the Game Objects
void 
TankGame::Draw()
{
	tank.Draw();
	tankEnemy.Draw();
	for ( int i = 0; i < shells.size(); ++i )
	{
		shells[i].Draw();
	}
}

//TankGame implements the TankObserver interface, this event is fired from Tank.
//Enemy tank and player tank to use the same OnShoot function
void
TankGame::OnShoot(Vector3 pos_, float dir_)
{
	//lets find a shell that we aren't currently using
	int shellNum = 0;
	while (shells[shellNum].Active())
	{
		++shellNum;
	}

	//and shoot it!
	shells[shellNum].Shoot(pos_, dir_);
}


//
////TankGame implements the TankObserver interface, this event is fired from Tank.
//void
//TankGame::OnEnemyShoot(Vector3 pos_, float dir_)
//{
//	//NOT YET IMPLEMENTED
//}

void 
TankGame::Update(float delta_)
{	
	//if holding P pause game
	if ( inpt->IsKeyDown(KEY_P) ) 
		return;

	//respond to user input
	tank.Update(delta_);	
	tankEnemy.Update(delta_);
	
	//update shells
	for ( int i = 0; i < shells.size(); ++i )
	{
		shells[i].Update(delta_);
	}

	//check for collisions
	
	//shell colliding with enemy tank
	for ( int i = 0; i < shells.size(); ++i )
	{
		if ( shells[i].Active() )
		{
			//get shell x/y
			Vector3 shellPos = shells[i].Position();
			Vector3 enemyTankPos = tankEnemy.Position();

			if ( (shellPos - enemyTankPos).GetMagnitude() < TANK_RADIUS + SHELL_RADIUS ) 
			{
				shells[i].Hit();
			}
		}
	}
}