#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"
#include "DynamicObject.h"

class Turtle : public DynamicObject
{
	#define LEFT 0
	#define RIGHT 1

	//GLuint vaoTri;
	GLuint vao;

public:
	void draw();
	Turtle(VSMathLib *vsml, VSShaderLib * shader, float x, float y, float z);
	~Turtle();
};

