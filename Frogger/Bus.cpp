#include "Bus.h"
#include "DynamicObject.h"
#include <iostream>

int verticeCountBus = 24;
int faceCountBus = 12;

float verticesBus[] = {
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

float normalsBus[] = {
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

float colorsBus[] = {
	1.0f, 0.85f, 0.0f, 1.0f,
	1.0f, 0.85f, 0.0f, 1.0f,
	1.0f, 0.85f, 0.0f, 1.0f,
	1.0f, 0.85f, 0.0f, 1.0f,

	1.0f, 0.85f, 0.0f, 1.0f,
	1.0f, 0.85f, 0.0f, 1.0f,
	1.0f, 0.85f, 0.0f, 1.0f,
	1.0f, 0.85f, 0.0f, 1.0f,

	1.0f, 0.85f, 0.0f, 1.0f,
	1.0f, 0.85f, 0.0f, 1.0f,
	1.0f, 0.85f, 0.0f, 1.0f,
	1.0f, 0.85f, 0.0f, 1.0f,

	1.0f, 0.85f, 0.0f, 1.0f,
	1.0f, 0.85f, 0.0f, 1.0f,
	1.0f, 0.85f, 0.0f, 1.0f,
	1.0f, 0.85f, 0.0f, 1.0f,

	1.0f, 0.85f, 0.0f, 1.0f,
	1.0f, 0.85f, 0.0f, 1.0f,
	1.0f, 0.85f, 0.0f, 1.0f,
	1.0f, 0.85f, 0.0f, 1.0f,

	1.0f, 0.85f, 0.0f, 1.0f,
	1.0f, 0.85f, 0.0f, 1.0f,
	1.0f, 0.85f, 0.0f, 1.0f,
	1.0f, 0.85f, 0.0f, 1.0f,


};

float colorsBus2[] = {
	0.64f, 0.87f, 1.0f, 1.0f,
	0.64f, 0.87f, 1.0f, 1.0f,
	0.64f, 0.87f, 1.0f, 1.0f,
	0.64f, 0.87f, 1.0f, 1.0f,

	0.64f, 0.87f, 1.0f, 1.0f,
	0.64f, 0.87f, 1.0f, 1.0f,
	0.64f, 0.87f, 1.0f, 1.0f,
	0.64f, 0.87f, 1.0f, 1.0f,

	0.64f, 0.87f, 1.0f, 1.0f,
	0.64f, 0.87f, 1.0f, 1.0f,
	0.64f, 0.87f, 1.0f, 1.0f,
	0.64f, 0.87f, 1.0f, 1.0f,

	0.64f, 0.87f, 1.0f, 1.0f,
	0.64f, 0.87f, 1.0f, 1.0f,
	0.64f, 0.87f, 1.0f, 1.0f,
	0.64f, 0.87f, 1.0f, 1.0f,

	0.64f, 0.87f, 1.0f, 1.0f,
	0.64f, 0.87f, 1.0f, 1.0f,
	0.64f, 0.87f, 1.0f, 1.0f,
	0.64f, 0.87f, 1.0f, 1.0f,

	0.64f, 0.87f, 1.0f, 1.0f,
	0.64f, 0.87f, 1.0f, 1.0f,
	0.64f, 0.87f, 1.0f, 1.0f,
	0.64f, 0.87f, 1.0f, 1.0f

};


float texCoordsBus[] = {
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

unsigned int faceIndexBus[] = {
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






Bus::Bus(VSMathLib *vsml, VSShaderLib *shader, float x, float y, float z)
{

	VSResSurfRevLib surfRev;

	this->setPosition(x, y, z);
	this->setSpeed(0.05f);
	this->setStep(1.4f);
	this->setRotation(0.0f, 1.0f, 0.0f);
	this->setRotationAngle(0.0f);
	this->setScale(0.8f, 0.8f, 0.8f);
	this->setShader(shader);
	this->setVSML(vsml);
	// create wheel
	surfRev.createCylinder(0.5f, 0.3f, 50);
	this->setResSurfRev(surfRev);
	this->setBoundaries(-8.2f, 5.8f);
	this->setDirection(RIGHT);

	glGenVertexArrays(1, &vaoBus);
	glBindVertexArray(vaoBus);

	// create buffers for our vertex data
	GLuint buffersCube[4];
	GLuint buffersCube2[4];
	glGenBuffers(4, buffersCube);
	glGenBuffers(4, buffersCube2);


	//vertex coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesBus), verticesBus, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::VERTEX_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::VERTEX_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	// 	//texture coordinates buffer
	// 	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[1]);
	// 	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoordsCube), texCoordsCube, GL_STATIC_DRAW);
	// 	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	// 	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 2, GL_FLOAT, 0, 0, 0);

	//color coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorsBus), colorsBus, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	//normals buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normalsBus), normalsBus, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::NORMAL_ATTRIB);
	glVertexAttribPointer(VSShaderLib::NORMAL_ATTRIB, 3, GL_FLOAT, 0, 0, 0);

	//index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffersCube[3]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(faceIndexBus), faceIndexBus, GL_STATIC_DRAW);

	// unbind the VAO
	glBindVertexArray(0);

	glGenVertexArrays(1, &vaoBus2);
	glBindVertexArray(vaoBus2);


	//vertex coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCube2[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesBus), verticesBus, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::VERTEX_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::VERTEX_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	// 	//texture coordinates buffer
	// 	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[1]);
	// 	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoordsCube), texCoordsCube, GL_STATIC_DRAW);
	// 	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	// 	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 2, GL_FLOAT, 0, 0, 0);

	//color coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCube2[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorsBus2), colorsBus2, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	//normals buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCube2[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normalsBus), normalsBus, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::NORMAL_ATTRIB);
	glVertexAttribPointer(VSShaderLib::NORMAL_ATTRIB, 3, GL_FLOAT, 0, 0, 0);

	//index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffersCube2[3]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(faceIndexBus), faceIndexBus, GL_STATIC_DRAW);

	// unbind the VAO
	glBindVertexArray(0);


}


Bus::~Bus()
{
}

void Bus::draw()
{
	float rotAngle = getRotationAngle();
	Vector3D * rotation = getRotation();
	Vector3D * scale = getScale();

	getVSML()->loadIdentity(VSMathLib::MODEL);
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	getVSML()->rotate(rotAngle, rotation->getX(), rotation->getY(), rotation->getZ());
	getVSML()->scale(scale->getX(), scale->getY(), scale->getZ());

	// base do autocarro
	getVSML()->pushMatrix(VSMathLib::MODEL);
	//getVSML()->loadIdentity(VSMathLib::MODEL);
	getVSML()->scale(3.0f, 1.5f, 1.0f);

	glUseProgram((*getShader()).getProgramIndex());
	// send matrices to uniform buffer

	getVSML()->matricesToGL();
	glBindVertexArray(vaoBus);
	glDrawElements(GL_TRIANGLES, faceCountBus * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);
	// base do autocarro

	// vidros do autocarro
	getVSML()->pushMatrix(VSMathLib::MODEL);
	//getVSML()->loadIdentity(VSMathLib::MODEL);
	getVSML()->translate(0.5, 0.7, -0.0001);
	getVSML()->scale(2.5001f, 0.5f, 1.0002f);
	glUseProgram((*getShader()).getProgramIndex());
	// send matrices to uniform buffer

	getVSML()->matricesToGL();
	glBindVertexArray(vaoBus2);
	glDrawElements(GL_TRIANGLES, faceCountBus * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);
	// vidros do autocarro

	//rodas de trás do autocarro
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.5, 0, 0.5);
	getVSML()->rotate(-90.0f, 1.0f, 0.0f, 0.0f);
	getVSML()->scale(1.0f, 2.5f, 1.0f);

	glUseProgram((*getShader()).getProgramIndex());
	// send matrices to uniform buffer
	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);

	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(1.2, 0, 0.5);
	getVSML()->rotate(-90.0f, 1.0f, 0.0f, 0.0f);
	getVSML()->scale(1.0f, 2.5f, 1.0f);

	glUseProgram((*getShader()).getProgramIndex());
	// send matrices to uniform buffer
	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);

	//rodas de trás do autocarro

	//rodas da frente do autocarro
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(2.5, 0, 0.5);
	getVSML()->rotate(-90.0f, 1.0f, 0.0f, 0.0f);
	getVSML()->scale(1.0f, 2.5f, 1.0f);

	glUseProgram((*getShader()).getProgramIndex());
	// send matrices to uniform buffer
	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);

	//rodas da frente do autocarro

	getVSML()->translate(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	getVSML()->popMatrix(VSMathLib::MODEL);


}