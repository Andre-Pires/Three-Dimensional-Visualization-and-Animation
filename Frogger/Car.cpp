#include "Car.h"

int verticeCountCar = 24;
int faceCountCar = 12;

float verticesCar[] = {
	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f,

	1.0f, 1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,

	1.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f, 1.0f,

	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 0.0f, 1.0f,

	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,

	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f, 1.0f
};

float normalsCar[] = {
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	0.0f, 0.0f, -1.0f,
	0.0f, 0.0f, -1.0f,
	0.0f, 0.0f, -1.0f,
	0.0f, 0.0f, -1.0f,

	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	-1.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f,

	0.0f, -1.0f, 0.0f,
	0.0f, -1.0f, 0.0f,
	0.0f, -1.0f, 0.0f,
	0.0f, -1.0f, 0.0f
};

float colorsCar[] = {
	0.8f, 0.0f, 0.0f, 1.0f,
	0.8f, 0.0f, 0.0f, 1.0f,
	0.8f, 0.0f, 0.0f, 1.0f,
	0.8f, 0.0f, 0.0f, 1.0f,

	0.8f, 0.0f, 0.0f, 1.0f,
	0.8f, 0.0f, 0.0f, 1.0f,
	0.8f, 0.0f, 0.0f, 1.0f,
	0.8f, 0.0f, 0.0f, 1.0f,

	0.8f, 0.0f, 0.0f, 1.0f,
	0.8f, 0.0f, 0.0f, 1.0f,
	0.8f, 0.0f, 0.0f, 1.0f,
	0.8f, 0.0f, 0.0f, 1.0f,

	0.8f, 0.0f, 0.0f, 1.0f,
	0.8f, 0.0f, 0.0f, 1.0f,
	0.8f, 0.0f, 0.0f, 1.0f,
	0.8f, 0.0f, 0.0f, 1.0f,

	0.8f, 0.0f, 0.0f, 1.0f,
	0.8f, 0.0f, 0.0f, 1.0f,
	0.8f, 0.0f, 0.0f, 1.0f,
	0.8f, 0.0f, 0.0f, 1.0f,

	0.8f, 0.0f, 0.0f, 1.0f,
	0.8f, 0.0f, 0.0f, 1.0f,
	0.8f, 0.0f, 0.0f, 1.0f,
	0.8f, 0.0f, 0.0f, 1.0f


};

float texCoordsCar[] = {
	0.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 1.0f,

	0.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 1.0f,

	0.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 1.0f,

	0.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 1.0f,

	0.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 1.0f,

	0.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 1.0f,
};

unsigned int faceIndexCar[] = {
	0, 1, 2,
	0, 2, 3,
	4, 5, 6,
	4, 6, 7,
	8, 9, 10,
	8, 10, 11,
	12, 13, 14,
	12, 14, 15,
	16, 17, 18,
	16, 18, 19,
	20, 21, 22,
	20, 22, 23
};

Car::Car(VSMathLib *vsml, VSShaderLib *shader, float x, float y, float z)
{
	VSResSurfRevLib surfRev;

	this->setPosition(x, y, z);
	this->setSpeed(0.10f);
	this->setStep(1.4f);
	this->setRotation(0.0f, 0.0f, 1.0f);
	this->setRotationAngle(180.0f);
	this->setScale(1.0f, 1.0f, 1.0f);
	this->setShader(shader);
	this->setVSML(vsml);
	// create wheel
	surfRev.createCylinder(1.0f, 0.2f, 50);
	this->setResSurfRev(surfRev);
	this->setMoveBoundaries(-12.25f, 12.25f);
	this->setDirection(LEFT);
	this->setCharBoundaries(0.8f, 0.5f);
	
	glGenVertexArrays(1, &vaoCar);
	glBindVertexArray(vaoCar);

	// create buffers for our vertex data
	GLuint buffersCar[4];
	glGenBuffers(4, buffersCar);

	//vertex coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCar[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesCar), verticesCar, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::VERTEX_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::VERTEX_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);


	//color coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCar[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorsCar), colorsCar, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	//normals buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCar[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normalsCar), normalsCar, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::NORMAL_ATTRIB);
	glVertexAttribPointer(VSShaderLib::NORMAL_ATTRIB, 3, GL_FLOAT, 0, 0, 0);

	//index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffersCar[3]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(faceIndexCar), faceIndexCar, GL_STATIC_DRAW);

	// unbind the VAO
	glBindVertexArray(0);


}


Car::~Car()
{
}

void Car::draw()
{
	float rotAngle = getRotationAngle();
	Vector3D * rotation = getRotation();
	Vector3D * scale = getScale();

	getVSML()->loadIdentity(VSMathLib::MODEL);

	// Car
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	getVSML()->rotate(rotAngle, rotation->getX(), rotation->getY(), rotation->getZ());
	getVSML()->scale(scale->getX(), scale->getY(), scale->getZ());

	// body
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.0f, 0.0f, -0.15);
	getVSML()->scale(1.6f, 0.8f, 0.4f);

	// cube
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.5f, -0.5f, -0.5f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	glBindVertexArray(vaoCar);
	glDrawElements(GL_TRIANGLES, faceCountCar * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);
	// cube

	getVSML()->popMatrix(VSMathLib::MODEL);
	// body


	// top
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.1f, 0.0f, 0.2f);
	getVSML()->scale(0.8f, 0.8f, 0.3f);

	// cube
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.5f, -0.5f, -0.5f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	glBindVertexArray(vaoCar);
	glDrawElements(GL_TRIANGLES, faceCountCar * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);
	// cube

	getVSML()->popMatrix(VSMathLib::MODEL);
	// top


	// back wheels
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.4f, 0.0f, -0.35f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);
	// back wheels


	// front wheels
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.3f, 0.0f, -0.35f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);
	// front wheels

	getVSML()->popMatrix(VSMathLib::MODEL);
	// Car
}


