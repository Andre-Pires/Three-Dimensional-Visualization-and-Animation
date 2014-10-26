#include "stdafx.h"
#include "StaticObject.h"


StaticObject::StaticObject()
{
}


StaticObject::~StaticObject()
{
}

void StaticObject::setSceneryBoundaries(float length, float width)
{
	lengthBound = length;
	widthBound = width;
}

vector<float> StaticObject::getSceneryBoundaries()
{
	float upperBoundX = getPosition()->getX() + lengthBound;
	float lowerBoundX = getPosition()->getX() - lengthBound;
	float upperBoundY = getPosition()->getY() + widthBound;
	float lowerBoundY = getPosition()->getY() - widthBound;

	vector<float> bounds = { upperBoundX, lowerBoundX, upperBoundY, lowerBoundY };

	return bounds;
}