#include "TankShell.h"
#include "CONSTS.h"


TankShell::TankShell(Vector3 pos_, float dir_)
{
	gfx = GLAHGraphics::Instance();

	spriteID = gfx->CreateSprite(
		"resources/TankShell1.png",					//the PNG to load
		SHELL_W, SHELL_H,							//width and height of sprite
		pos_.x, pos_.y,								//initial x/y position (relative to parent)
		0,											//no parent
		//Vector3(SHELL_W/2, SHELL_H/2, 0)//rotation origin offset
		Vector3(250, SHELL_H/2, 0)//rotation origin offset
		);

	gfx->RotateSprite(spriteID, dir_);
	//gfx->RotateSprite(spriteID, PI);
	velocity = Vector3(1.0f, 1.0f, 0.0f);
	velocity.SetAngle(dir_);	
	velocity.Normalise();
	position = pos_;
}


TankShell::~TankShell(void)
{
}

void
TankShell::Draw()
{
	gfx->DrawSprite(spriteID);
}

void 
TankShell::Update(float delta_)
{
	gfx->MoveSpriteRelative(spriteID, -SHELL_VELOCITY*delta_, 0, 0);
}