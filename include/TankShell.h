#pragma once

#include "GLAHEntity.h"
#include "GLAHGraphics.h"
#include "Vector.h"


class TankShell
{
public:
	void Shoot(Vector3 pos_, float dir_);
	TankShell();
	~TankShell(void);

	void Update(float delta_);
	void Draw();
	bool Active();
	void Reset();

private:
	GLAHGraphics* gfx;
	Vector3 velocity;
	Vector3 position;
	bool active;
	float activeFor;

	unsigned int spriteID;
};

