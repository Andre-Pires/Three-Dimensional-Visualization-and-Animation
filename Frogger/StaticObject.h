#pragma once
#include "GameObject.h"

using namespace std;

class StaticObject : public GameObject
{
	float lengthBound, widthBound;

public:
	StaticObject();
	~StaticObject();
	vector<float> getSceneryBoundaries();
	void setSceneryBoundaries(float lengthBound, float widthBound);

};

