#pragma once

#include "GLAHGame.h"
#include "Tank.h"
#include "TankEnemy.h"
#include "TankObserver.h"
#include "TankShell.h"
#include <vector>
#include "GLAHInput.h"

using namespace std;


class TankGame : public GLAH, public TankObserver //implements GLAH interface
{
public:
	virtual void Update(float delta);
	virtual void Draw();
	TankGame();
	~TankGame();

	virtual void OnShoot(Vector3 pos_, float dir_);
	//virtual void OnEnemyShoot(Vector3 pos_, float dir_);

private:

	Tank tank;
	TankEnemy tankEnemy;
	vector<TankShell> shells;
	GLAHInput* inpt;
};