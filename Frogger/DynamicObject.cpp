#include "stdafx.h"
#include "DynamicObject.h"


DynamicObject::DynamicObject()
{
	alive = false;
}


DynamicObject::~DynamicObject()
{
}

float DynamicObject::getSpeed()
{
	return speed;
}

void DynamicObject::setSpeed(float newSpeed)
{
	speed = newSpeed;
}

float DynamicObject::getStep()
{
	return step;
}

void DynamicObject::setStep(float newStep)
{
	step = newStep;
}

bool DynamicObject::isAlive()
{
	return alive;
}

void DynamicObject::setAlive(bool state)
{
	alive = state;
}

void DynamicObject::setDirection(int dir)
{
	direction = dir;
}

void DynamicObject::setBoundaries(float leftMoveBound, float rightMoveBound)
{
	left = leftMoveBound;
	right = rightMoveBound;
}

void DynamicObject::move()
{
	float posX = getPosition()->getX();
	float speed = getSpeed();

	if (direction == LEFT)
	{
		if (posX <= left)
		{
			setPosition(right, getPosition()->getY(), getPosition()->getZ());
			setAlive(false);
		}
		else setPosition(getPosition()->getX() - getSpeed(), getPosition()->getY(), getPosition()->getZ());
	}
	else if (direction == RIGHT)
	{
		if (posX >= right)
		{
			setPosition(left, getPosition()->getY(), getPosition()->getZ());
			setAlive(false);
		}
		else setPosition(getPosition()->getX() + getSpeed(), getPosition()->getY(), getPosition()->getZ());
	}
}

void DynamicObject::speedUp()
{
	setSpeed(getSpeed() * getStep());
}

void DynamicObject::hasCollided(Vector3D pos)
{
	setSpeed(getSpeed() * getStep());
}