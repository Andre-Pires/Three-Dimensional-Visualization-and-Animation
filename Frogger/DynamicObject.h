#pragma once
#include "GameObject.h"
class DynamicObject : public GameObject
{
#define LEFT 0
#define RIGHT 1

	int direction;
	float speed;
	float step;
	float left, right;
	bool alive;

public:
	

	DynamicObject();
	~DynamicObject();
	float getSpeed();
	void setSpeed(float speed);
	void setStep(float newStep);
	float getStep();
	void setAlive(bool state);
	bool isAlive();
	void setDirection(int dir);
	void move();
	void setBoundaries(float leftBound, float rightBound);
	void speedUp();
};

