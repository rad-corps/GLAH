#pragma once

#include "GLAHGame.h"
#include "Tank.h"
#include "GLAHGraphics.h"
#include "GLAHInput.h"
#include "TankObserver.h"
#include "TankShell.h"
#include <vector>

using namespace std;


class TankGame : public GLAH, public TankObserver //implements GLAH interface
{
public:
	virtual void Update(float delta);
	virtual void Draw();
	TankGame();
	~TankGame();

	virtual void OnShoot(Vector3 pos_, float dir_);

private:

	//must be a pointer to be classwide (private ctor)
	GLAHGraphics* gfx;
	GLAHInput* inpt;

	Tank tank;
	vector<TankShell> shells;
};