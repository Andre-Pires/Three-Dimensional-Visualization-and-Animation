#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"
#include "DynamicObject.h"

class Frog : public DynamicObject
{

	//GLuint vaoTri;
	GLuint vaoHead, vaoBody;
	

public:
	void draw();
	void move(float x, float z);

	
	Frog(VSMathLib *vsml, VSShaderLib * shader, float x, float y, float z);
	~Frog();
};
