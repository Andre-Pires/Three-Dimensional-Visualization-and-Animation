#pragma once
#include "Vector3D.h"
#include "Frog.h"
#define ORTHO 1
#define PERSP 2
#define FIRSTPERS 3
class Camera : public Entity
{
	Vector3D * upCam;
	Vector3D * atCam;
	double nearCam;
	double farCam;
	float ratio;
	VSMathLib *vsml;
	Frog * frogger;

public:
	Camera(VSMathLib *vsml, Frog * frogger);
	~Camera();
	void update(int camState, int mouseState);
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
	void setRatio(double ratio);
	void setAt(float x, float y, float z);
};

