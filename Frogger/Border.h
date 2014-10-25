#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"
#include "StaticObject.h"

class Border : public StaticObject
{

	//GLuint vaoTri;
	GLuint vaoBorder;
	
public:
	void draw();

	Border(VSMathLib *vsml, VSShaderLib * shader, float x, float y, float z);
	~Border();

};


