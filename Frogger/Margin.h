#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"
#include "StaticObject.h"

class Margin : public StaticObject
{

	//GLuint vaoTri;
	GLuint vaoMargin;

public:
	void draw();

	Margin(VSMathLib *vsml, VSShaderLib * shader, float x, float y, float z);
	~Margin();

};
