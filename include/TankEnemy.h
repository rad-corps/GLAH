#pragma once

#include "GLAHEntity.h"
#include "GLAHGame.h"
#include "GLAHGraphics.h"
#include "GLAHInput.h"
#include "Vector.h"
#include "TankObserver.h"

class TankEnemy
{
public:
	TankEnemy(void);
	~TankEnemy(void);

	void AddObserver(TankObserver* observer_);
	void Update(float delta_);
	void Draw();

	Vector3 Position();

private:
	
	TankObserver* observer;
	Vector2 velocity;
	Vector2 direction;

//	GLAHGraphics* gfx;
	GLAHInput* inpt;

	unsigned int turretSprite;
	unsigned int tankSprite;

	float timeSinceReload;
};

