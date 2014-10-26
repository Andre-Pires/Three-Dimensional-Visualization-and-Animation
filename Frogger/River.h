#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"
#include "StaticObject.h"

using namespace std;

class River : public StaticObject
{
	//GLuint vaoTri;
	GLuint vaoRiver;
	float lengthBound;
	float widthBound;

public:
	void draw();

	River(VSMathLib *vsml, VSShaderLib * shader, float x, float y, float z);
	~River();
	vector<float> getCharBoundaries();
};