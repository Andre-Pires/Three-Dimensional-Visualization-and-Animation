#include "stdafx.h"
#include "Turtle.h"

int verticeCountTurtle = 24;
int faceCountTurtle = 12;

float verticesTurtle[] = {
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

float normalsTurtle[] = {
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

float colorsTurtle[] = {
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,

	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,

	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,

	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,

	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,

	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,

	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,

	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,

	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,

	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f,
	0.0f, 0.6f, 0.0f, 1.0f

};

float texCoordsTurtle[] = {
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

unsigned int faceIndexTurtle[] = {
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


Turtle::Turtle(VSMathLib *vsml, VSShaderLib * shader, float x, float y, float z)
{
	VSResSurfRevLib surfRev;

	this->setPosition(x, y, z);
	this->setSpeed(0.03f);
	this->setStep(1.4f);
	this->setRotation(0.0f, 1.0f, 0.0f);
	this->setRotationAngle(-90.0f);
	this->setScale(0.4f, 0.4f, 0.4f);
	this->setShader(shader);
	this->setVSML(vsml);
	// create sphere
	surfRev.createSphere(1.0f, 3);
	this->setResSurfRev(surfRev);
	this->setDirection(LEFT);
	this->setBoundaries(-7.8f, 7.4f);


	// create body
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// create buffers for our vertex data
	GLuint buffersBody[4];
	glGenBuffers(4, buffersBody);

	//vertex coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersBody[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesTurtle), verticesTurtle, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::VERTEX_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::VERTEX_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	// 	//texture coordinates buffer
	// 	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[1]);
	// 	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoordsCube), texCoordsCube, GL_STATIC_DRAW);
	// 	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	// 	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 2, GL_FLOAT, 0, 0, 0);

	//color coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersBody[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorsTurtle), colorsTurtle, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	//normals buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersBody[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normalsTurtle), normalsTurtle, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::NORMAL_ATTRIB);
	glVertexAttribPointer(VSShaderLib::NORMAL_ATTRIB, 3, GL_FLOAT, 0, 0, 0);

	//index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffersBody[3]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(faceIndexTurtle), faceIndexTurtle, GL_STATIC_DRAW);

	// unbind the VAO
	glBindVertexArray(0);
}


Turtle::~Turtle()
{
}



void Turtle::draw()
{
	float rotAngle = getRotationAngle();
	Vector3D * rotation = getRotation();
	Vector3D * scale = getScale();

	getVSML()->loadIdentity(VSMathLib::MODEL);
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	getVSML()->rotate(rotAngle, rotation->getX(), rotation->getY(), rotation->getZ());
	getVSML()->scale(scale->getX(), scale->getY(), scale->getZ());
	// head
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.0f, 0.0f, 1.25f);
	getVSML()->scale(0.4f, 0.25f, 0.5f);

	glUseProgram((*getShader()).getProgramIndex());
	// send matrices to uniform buffer
	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);
	// head

	//eyes
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.25, 0.2, 1.3);
	getVSML()->scale(0.1f, 0.1f, 0.1f);

	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);

	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.25, 0.2, 1.3);
	getVSML()->scale(0.1f, 0.1f, 0.1f);

	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);
	//eyes

	// body
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0, 0, 0);
	getVSML()->scale(1.0f, 0.5f, 1.25f);

	glUseProgram((*getShader()).getProgramIndex());
	// send matrices to uniform buffer
	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);
	// body

	// front left paw
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.7f, 0.0f, 1.0f);
	getVSML()->scale(0.3f, 0.15f, 0.3f);

	glUseProgram((*getShader()).getProgramIndex());
	// send matrices to uniform buffer
	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);
	// front left paw

	// front right paw
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.7f, 0.0f, 1.0f);
	getVSML()->scale(0.3f, 0.15f, 0.3f);

	glUseProgram((*getShader()).getProgramIndex());
	// send matrices to uniform buffer
	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);
	// front right paw

	// back right paw
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.7f, 0.0f, -1.0f);
	getVSML()->scale(0.3f, 0.15f, 0.3f);

	glUseProgram((*getShader()).getProgramIndex());
	// send matrices to uniform buffer
	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);
	// back right paw

	// back left paw
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.7f, 0.0f, -1.0f);
	getVSML()->scale(0.3f, 0.15f, 0.3f);

	glUseProgram((*getShader()).getProgramIndex());
	// send matrices to uniform buffer
	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);
	// back left paw

	getVSML()->popMatrix(VSMathLib::MODEL);


}