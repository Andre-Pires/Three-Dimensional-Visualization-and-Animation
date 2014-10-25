#pragma once
#include "Vector3D.h"

class Entity
{
public:
	Vector3D * position;

	Entity();
	~Entity();
	Vector3D * getPosition();
	void setPosition(float x, float y, float z);
	void setPosition(Vector3D * vector);
};

