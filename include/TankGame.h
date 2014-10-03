#pragma once

#include "GLAHGame.h"
#include "Tank.h"
#include "GLAHGraphics.h"
#include "GLAHInput.h"
#include "TankObserver.h"


class TankGame : public GLAH, public TankObserver //implements GLAH interface
{
public:
	virtual void Update(float delta);
	virtual void Draw();
	TankGame();
	~TankGame();

	virtual void OnShoot();

private:
	unsigned int tankSprite;
	unsigned int turretSprite;

	//must be a pointer to be classwide (private ctor)
	GLAHGraphics* gfx;
	GLAHInput* inpt;

	Tank tank;
};