#pragma once

#include "GLAHEntity.h"
#include "GLAHGame.h"
#include "GLAHGraphics.h"
#include "GLAHInput.h"
#include "Vector.h"
#include "TankObserver.h"



class Tank
{
public:
	Tank();
	~Tank(void);

	void Accellerate();
	void Reverse();

	void Rotate(bool positive_);

	void Update(float delta_);
	void Draw();

	void AddObserver(TankObserver* observer_);

private:
	TankObserver* observer;
	Vector2 velocity;
	Vector2 direction;

	GLAHGraphics* gfx;
	GLAHInput* inpt;

	unsigned int turretSprite;
	unsigned int tankSprite;

	float timeSinceReload;
};

