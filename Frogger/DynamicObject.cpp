#include "stdafx.h"
#include "DynamicObject.h"



DynamicObject::DynamicObject(float x, float y, float z)
{
	alive = false;
	initialPosition = new Vector3D(x,y,z);
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

void DynamicObject::setMoveBoundaries(float leftMoveBound, float rightMoveBound)
{
	this->leftMoveBound = leftMoveBound;
	this->rightMoveBound = rightMoveBound;
}

void DynamicObject::move()
{
	float posX = getPosition()->getX();
	float speed = getSpeed();

	if (direction == LEFT)
	{
		if (posX <= leftMoveBound)
		{
			setPosition(rightMoveBound, getPosition()->getY(), getPosition()->getZ());
			setAlive(false);
		}
		else setPosition(getPosition()->getX() - getSpeed(), getPosition()->getY(), getPosition()->getZ());
	}
	else if (direction == RIGHT)
	{
		if (posX >= rightMoveBound)
		{
			setPosition(leftMoveBound, getPosition()->getY(), getPosition()->getZ());
			setAlive(false);
		}
		else setPosition(getPosition()->getX() + getSpeed(), getPosition()->getY(), getPosition()->getZ());
	}
}

void DynamicObject::speedUp()
{
	setSpeed(getSpeed() * getStep());
}

void DynamicObject::setCharBoundaries(float length, float width)
{
	lengthCharBound = length;
	widthCharBound = width;
}

vector<float> DynamicObject::getCharBoundaries()
{
	float upperBoundX = getPosition()->getX() + lengthCharBound;
	float lowerBoundX = getPosition()->getX() - lengthCharBound;
	float upperBoundY = getPosition()->getY() + widthCharBound;
	float lowerBoundY = getPosition()->getY() - widthCharBound;

	vector<float> bounds = { upperBoundX, lowerBoundX, upperBoundY, lowerBoundY};

	return bounds;
}

void DynamicObject::resetCharacter()
{
	setAlive(false);
	setPosition(initialPosition->getX(), initialPosition->getY(), initialPosition->getZ());
}