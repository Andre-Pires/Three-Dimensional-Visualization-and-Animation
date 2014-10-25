#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"
#include "DynamicObject.h"

class Car : public DynamicObject
{
	#define LEFT 0
	#define RIGHT 1

	//GLuint vaoTri;
	GLuint vaoCar;

public:
	void draw();
	Car(VSMathLib *vsml, VSShaderLib * shader, float x, float y, float z);
	~Car();

};


