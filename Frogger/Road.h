#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"
#include "GameObject.h"

class Road : public GameObject
{
	//GLuint vaoTri;
	GLuint vaoRoad;

public:
	void draw();

	Road(VSMathLib *vsml, VSShaderLib * shader, float x, float y, float z);
	~Road();

};