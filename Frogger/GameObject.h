#pragma once
#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "Entity.h"
#include "vsResSurfRevLib.h"
class GameObject : public Entity
{
	VSMathLib *vsml;
	VSShaderLib *shader;
	VSResSurfRevLib surfRev;
	Vector3D* rotation;
	Vector3D* scale;
	float rotationAngle;

public:
	GameObject();
	~GameObject();
	virtual void draw() = 0;
	void setRotation(float x, float y, float z);
	Vector3D * getRotation();
	void setRotationAngle(float angle);
	float getRotationAngle();
	void setVSML(VSMathLib *vsml);
	VSMathLib * getVSML();
	VSShaderLib * getShader();
	void setShader(VSShaderLib *shader);
	VSResSurfRevLib getResSurfRev();
	void setResSurfRev(VSResSurfRevLib surfRev);
	void setScale(float x, float y, float z);
	Vector3D * getScale();
};

