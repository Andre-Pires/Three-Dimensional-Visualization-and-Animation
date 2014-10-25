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
			vsml->lookAt(frogX + 0.25f, 0.5f, frogZ + 1,
				atCam->getX(), atCam->getY(), frogZ - 5,
				0, 1, 0);
		}
		else{
			vsml->lookAt(frogX + 0.25f, 0.5f, frogZ + 1,
				frogX + 0.25f, frogY + 0.25f, frogZ - 5,
				0, 1, 0);
		}
	}

	glutPostRedisplay();
}

void Camera::setRatio(float ratio)
{
	this->ratio = ratio;
}

void Camera::setAt(float x, float y, float z)
{
	atCam->set(x, y, z);
}
