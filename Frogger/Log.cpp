#include "Log.h"

int verticeCountLog = 24;
int faceCountLog = 12;


Log::Log(VSMathLib *vsml, VSShaderLib *shader, float x, float y, float z) : DynamicObject(x, y, z, 0.07f)
{
	VSResSurfRevLib surfRev;

	this->setPosition(x, y, z);
	this->setSpeed(0.07f);
	this->setStep(1.4f);
	this->setRotation(0.0f, 0.0f, 1.0f);
	this->setRotationAngle(90.0f);
	this->setScale(1.0f, 1.0f, 1.0f);
	this->setShader(shader);
	this->setVSML(vsml);
	// create wheel
	surfRev.createCylinder(1.0f, 0.5f, 6);
	this->setResSurfRev(surfRev);
	this->setMoveBoundaries(-12.0f, 12.0f);
	this->setDirection(LEFT);
	this->setCharBoundaries(0.75f, 0.5f);

	// unbind the VAO
	glBindVertexArray(0);


}


Log::~Log()
{
}

void Log::draw()
{
	float rotAngle = getRotationAngle();
	Vector3D * rotation = getRotation();
	Vector3D * scale = getScale();

	getVSML()->loadIdentity(VSMathLib::MODEL);

	// Log
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	getVSML()->rotate(rotAngle, rotation->getX(), rotation->getY(), rotation->getZ());
	getVSML()->scale(scale->getX(), scale->getY(), scale->getZ());
	
	// body
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->scale(1.0f, 2.0f, 1.0f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);
	// body

	// detail
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.3f, 0.5f, 0.3f);
	getVSML()->rotate(90.0f, 1.0f, 0.0f, 0.0f);
	getVSML()->scale(0.25f, 0.6f, 0.25f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);
	// detail

	getVSML()->popMatrix(VSMathLib::MODEL);
	// Log

}
