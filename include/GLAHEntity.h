#pragma once

#include "Matrix.h"

struct GLAHEntity
{
	unsigned int spriteID;
	Matrix3x3 translation;
	unsigned int parentSpriteID; //if null, no parent. 
	Vector2 size; //x=width,y=height
	Vector3 origin;
	float rotation;
	float scale;

	GLAHEntity() : rotation(0.0f), scale(1.0f) {}
};