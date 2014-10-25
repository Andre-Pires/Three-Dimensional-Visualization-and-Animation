#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
	rotation = new Vector3D();
	scale = new Vector3D();
}


GameObject::~GameObject()
{
}

void GameObject::setRotation(float x, float y, float z)
{
	rotation->set(x, y, z);
}


Vector3D * GameObject::getRotation()
{
	return rotation;
}

void GameObject::setScale(float x, float y, float z)
{
	scale->set(x, y, z);
}


Vector3D * GameObject::getScale()
{
	return scale;
}

void GameObject::setRotationAngle(float angle)
{
	rotationAngle = angle;
}

float GameObject::getRotationAngle()
{
	return rotationAngle;
}

void GameObject::setVSML(VSMathLib *vsml)
{
	this->vsml = vsml;
}

VSMathLib * GameObject::getVSML()
{
	return vsml;
}

void GameObject::setShader(VSShaderLib *shader)
{
	this->shader = shader;
}

VSShaderLib * GameObject::getShader()
{
	return shader;
}

VSResSurfRevLib GameObject::getResSurfRev()
{
	return surfRev;
}

void GameObject::setResSurfRev(VSResSurfRevLib resSurfRev)
{
	surfRev = resSurfRev;
}
