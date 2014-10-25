#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"
#include "DynamicObject.h"

class Truck : public DynamicObject
{
#define LEFT 0
#define RIGHT 1

	int direction;

	//GLuint vaoTri;
	GLuint vaoTruck;

public:
	void draw();
	Truck(VSMathLib *vsml, VSShaderLib * shader, float x, float y, float z);
	~Truck();

};


