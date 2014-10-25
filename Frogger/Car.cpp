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
	this->setSpeed(0.1f);
	this->setStep(1.4f);
	this->setRotation(0.0f, 1.0f, 0.0f);
	this->setRotationAngle(90.0f);
	this->setScale(0.7f, 0.8f, 0.8f);
	this->setShader(shader);
	this->setVSML(vsml);
	// create wheel
	surfRev.createCylinder(0.5f, 0.3f, 50);
	this->setResSurfRev(surfRev);
	this->setBoundaries(-8.2f, 6.7f);
	this->setDirection(LEFT);
	
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
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	getVSML()->rotate(rotAngle, rotation->getX(), rotation->getY(), rotation->getZ());
	getVSML()->scale(scale->getX(), scale->getY(), scale->getZ());

	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->scale(1.0, 0.5, 2.0);
	glUseProgram((*getShader()).getProgramIndex());
	// send matrices to uniform buffer
	getVSML()->matricesToGL();
	glBindVertexArray(vaoCar);
	glDrawElements(GL_TRIANGLES, faceCountCar * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);

	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.0, 0.5, 0.6);
	getVSML()->scale(1.0, 0.3, 1.0);
	glUseProgram((*getShader()).getProgramIndex());
	// send matrices to uniform buffer
	getVSML()->matricesToGL();
	glBindVertexArray(vaoCar);
	glDrawElements(GL_TRIANGLES, faceCountCar * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);

	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.5, 0.0, 0.5);
	getVSML()->rotate(90.0, 0.0, 0.0, 1.0);
	getVSML()->scale(1.0f, 2.3f, 1.0f);
	glUseProgram((*getShader()).getProgramIndex());
	// send matrices to uniform buffer
	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);

	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.5, 0.0, 1.5);
	getVSML()->rotate(90.0, 0.0, 0.0, 1.0);
	getVSML()->scale(1.0f, 2.3f, 1.0f);
	glUseProgram((*getShader()).getProgramIndex());
	// send matrices to uniform buffer
	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);
	getVSML()->popMatrix(VSMathLib::MODEL);
}


