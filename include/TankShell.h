#pragma once

#include "GLAHEntity.h"
#include "GLAHGraphics.h"
#include "Vector.h"


class TankShell : public GLAHEntity
{
public:
	TankShell(Vector3 pos_, float dir_);
	~TankShell(void);

	void Update(float delta_);
	void Draw();

private:
	GLAHGraphics* gfx;
	Vector3 velocity;
	Vector3 position;
};

