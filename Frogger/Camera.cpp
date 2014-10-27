#include "stdafx.h"
#include "Camera.h"
#include <GL\freeglut_std.h>
#include "vsMathLib.h"


Camera::Camera(VSMathLib *vsml, Frog * frogger)
{
	this->upCam = new Vector3D(0,0,0);
	this->atCam = new Vector3D(0,0,0);
	this->vsml = vsml;
	this->frogger = frogger;
}


Camera::~Camera()
{
}

void Camera::update(int camState, int mouseState)
{
	if (camState == 1){
		vsml->loadIdentity(VSMathLib::PROJECTION);
		vsml->ortho(-8.0f*ratio, 8.0f*ratio, -8.0f, 8.0f, -6.0f, 6.0f);
		vsml->loadIdentity(VSMathLib::VIEW);
		vsml->loadIdentity(VSMathLib::MODEL);
	}
	else if (camState == 2){
		vsml->loadIdentity(VSMathLib::PROJECTION);
		vsml->perspective(45.0f, ratio, 0.1f, 100.0f);
		vsml->loadIdentity(VSMathLib::VIEW);
		vsml->loadIdentity(VSMathLib::MODEL);
		// set the camState using a function similar to gluLookAt
		vsml->lookAt(0.0f, -16.0f, 16.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	}
	else if (camState == 3){
		vsml->loadIdentity(VSMathLib::PROJECTION);
		vsml->perspective(45.0f, ratio, 0.1f, 100.0f);
		vsml->loadIdentity(VSMathLib::VIEW);
		vsml->loadIdentity(VSMathLib::MODEL);
		// set the camState using a function similar to gluLookAt

		float frogX = frogger->getPosition()->getX();
		float frogY = frogger->getPosition()->getY();
		float frogZ = frogger->getPosition()->getZ();

		if (mouseState == 1) //testing to see if user is looking around
		{
			vsml->lookAt(frogX, frogY - 0.85f, frogZ + 0.4f,
				atCam->getX(), atCam->getY(), atCam->getZ(),
				0.0f, 0.0f, 1.0f);
		}
		else{
			vsml->lookAt(frogX, frogY - 0.85f, frogZ + 0.4f,
				frogX, frogY + 5.0f, frogZ + 0.2f,
				0.0f, 0.0f, 1.0f);
		}
	}

	glutPostRedisplay();
}

void Camera::setRatio(double ratio)
{
	this->ratio = (float) ratio;
}

void Camera::setAt(float x, float y, float z)
{
	atCam->set(x, y, z);
}
