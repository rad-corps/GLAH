#include "TankEnemy.h"
#include "CONSTS.h"


TankEnemy::TankEnemy(void)
{
	gfx = GLAHGraphics::Instance();
	inpt = GLAHInput::Instance();

	tankSprite = gfx->CreateSprite(
		"resources/enemy2_base.png",					//the PNG to load
		TANK_SPRITE_W, TANK_SPRITE_H,				//width and height of sprite
		SCREEN_WIDTH/2 -200, SCREEN_HEIGHT/2-200,	//initial x/y position (relative to parent)
		0,											//no parent
		Vector3(TANK_SPRITE_W/2, TANK_SPRITE_H/2, 0)//rotation origin offset
		);

	turretSprite = gfx->CreateSprite(
		"resources/enemy2_turret.png",				//the PNG to load
		TANK_SPRITE_W, TANK_SPRITE_H,				//width and height of sprite
		-0, 0,										//initial x/y position (relative to parent)
		tankSprite,									//the parent object to bind to
		Vector3(150,64,0)							//rotation origin offset
		); 

	timeSinceReload = RELOAD_TIME;
}


TankEnemy::~TankEnemy(void)
{
}


void TankEnemy::Update(float delta_)
{}

void TankEnemy::Draw()
{
	gfx->DrawSprite(tankSprite);
	gfx->DrawSprite(turretSprite);
}

void 
TankEnemy::AddObserver(TankObserver* observer_)
{
	observer = observer_;
}

Vector3
TankEnemy::Position()
{
	return gfx->GetGLAHEntity(tankSprite).position;
}