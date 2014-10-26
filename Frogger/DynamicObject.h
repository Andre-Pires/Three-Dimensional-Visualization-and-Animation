#pragma once
#include "GameObject.h"

using namespace std;

class DynamicObject : public GameObject
{
#define LEFT 0
#define RIGHT 1

	int direction;
	float speed;
	float step;
	float leftMoveBound, rightMoveBound;
	float lengthCharBound, widthCharBound;
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
	void setMoveBoundaries(float leftBound, float rightBound);
	void setCharBoundaries(float lengthBound, float widthBound);
	void speedUp();
	vector<float> getCharBoundaries();
};

