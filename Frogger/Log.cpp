#include "Log.h"

int verticeCountLog = 24;
int faceCountLog = 12;


Log::Log(VSMathLib *vsml, VSShaderLib *shader, float x, float y, float z)
{
	VSResSurfRevLib surfRev;

	this->setPosition(x, y, z);
	this->setSpeed(0.03f);
	this->setStep(1.4f);
	this->setRotation(0.0f, 0.0f, 0.1f);
	this->setRotationAngle(90.0f);
	this->setScale(1.0f, 1.0f, 1.0f);
	this->setShader(shader);
	this->setVSML(vsml);
	// create wheel
	surfRev.createCylinder(0.5f, 8.0f, 50);
	this->setResSurfRev(surfRev);
	this->setBoundaries(-6.8f, 6.7f);
	this->setDirection(LEFT);

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

	getVSML()->translate(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	getVSML()->rotate(rotAngle, rotation->getX(), rotation->getY(), rotation->getZ());
	getVSML()->scale(scale->getX(), scale->getY(), scale->getZ());

	glUseProgram((*getShader()).getProgramIndex());
	// send matrices to uniform buffer

	getVSML()->matricesToGL();
	getResSurfRev().render();

}
