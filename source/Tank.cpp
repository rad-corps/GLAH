#include "Tank.h"
#include "CONSTS.h"


Tank::Tank(void)
{
	gfx = GLAHGraphics::Instance();
	inpt = GLAHInput::Instance();

	tankSprite = gfx->CreateSprite(
		"resources/tank_base.png",					//the PNG to load
		TANK_SPRITE_W, TANK_SPRITE_H,				//width and height of sprite
		SCREEN_WIDTH/2, SCREEN_HEIGHT/2,			//initial x/y position (relative to parent)
		0,											//no parent
		Vector3(TANK_SPRITE_W/2, TANK_SPRITE_H/2, 0)//rotation origin offset
		);

	turretSprite = gfx->CreateSprite(
		"resources/tank_turret.png",				//the PNG to load
		TANK_SPRITE_W, TANK_SPRITE_H,				//width and height of sprite
		-0, 0,										//initial x/y position (relative to parent)
		tankSprite,									//the parent object to bind to
		Vector3(150,64,0)							//rotation origin offset
		); 

	//gfx->RotateSprite(turretSprite, PI);

	timeSinceReload = RELOAD_TIME;
}


Tank::~Tank(void)
{
}

void
Tank::Update(float delta_)
{
	float rot = 0.00f;
	float tankX = 0.0f;
	float tankY = 0.0f;
	float turret_rot = 0.f;

	if ( inpt->IsKeyDown(KEY_W) )
	{
		tankX += -FWD_SPEED;
	}
	if ( inpt->IsKeyDown(KEY_S))
	{
		tankX += BKWD_SPEED;
	}
	if ( inpt->IsKeyDown(KEY_A))
	{
		rot += -ROT_SPEED;
	}
	if ( inpt->IsKeyDown(KEY_D))
	{
		rot += ROT_SPEED;
	}
	if ( inpt->IsKeyDown(KEY_LEFT))
	{
		turret_rot += -TURRET_ROT_SPEED;
	}
	if ( inpt->IsKeyDown(KEY_RIGHT))
	{
		turret_rot += TURRET_ROT_SPEED;
	}
	if ( inpt->IsKeyDown(KEY_SPACE) )
	{
		//logic : can we shoot? ammo, reload time
		if ( timeSinceReload > RELOAD_TIME )
		{
			observer->OnShoot(gfx->GetGLAHEntity(tankSprite).translation.getPosition(), gfx->GetGLAHEntity(turretSprite).rotation + gfx->GetGLAHEntity(tankSprite).rotation);
			timeSinceReload = 0.0f;
		}
	}
		
	turret_rot *= delta_;
	tankX *= delta_;
	tankY *= delta_;
	rot *= delta_;

	gfx->MoveSpriteRelative(tankSprite, tankX , tankY, rot );
	gfx->RotateSpriteRelative(turretSprite, turret_rot);

	timeSinceReload += delta_;
}

void 
Tank::Draw()
{
	gfx->DrawSprite(tankSprite);
	gfx->DrawSprite(turretSprite);
}

void 
Tank::AddObserver(TankObserver* observer_)
{
	observer = observer_;
}