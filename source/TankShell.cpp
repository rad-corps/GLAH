#include "TankShell.h"
#include "CONSTS.h"


bool 
TankShell::Active()
{
	return active;
	activeFor = 0.0f;
}

void
TankShell::Shoot(Vector3 pos_, float dir_)
{
	gfx->RotateSprite(spriteID, dir_);
	gfx->MoveSprite(spriteID, pos_.x, pos_.y);
	//gfx->RotateSprite(spriteID, PI);
	velocity = Vector3(1.0f, 1.0f, 0.0f);
	velocity.SetAngle(dir_);	
	velocity.Normalise();
	position = pos_;
	activeFor = 0.0f;

	active = true;
}

//dont want to use this constructor, but the vector may need it to reserve space
TankShell::TankShell(){
	gfx = GLAHGraphics::Instance();

	spriteID = gfx->CreateSprite(
		"resources/TankShell1.png",					//the PNG to load
		SHELL_W, SHELL_H,							//width and height of sprite
		0, 0,								//initial x/y position (relative to parent)
		0,											//no parent
		//Vector3(SHELL_W/2, SHELL_H/2, 0)//rotation origin offset
		Vector3(250, SHELL_H/2, 0)//rotation origin offset
		);
	
	active = false;
}


TankShell::~TankShell(void)
{
}

void
TankShell::Draw()
{
	if ( active )
		gfx->DrawSprite(spriteID);
}

void 
TankShell::Update(float delta_)
{
	if ( active )
	{
		gfx->MoveSpriteRelative(spriteID, -SHELL_VELOCITY*delta_, 0, 0);

		activeFor += delta_;

		if ( activeFor > MAX_BULLET_TIME )
		{
 			active = false;
			velocity = Vector3(1,1,0);
		}
	}
}