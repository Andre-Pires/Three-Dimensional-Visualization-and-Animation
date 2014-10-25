#include "Truck.h"

int verticeCountTruck = 24;
int faceCountTruck = 12;

float verticesTruck[] = {
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

float normalsTruck[] = {
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

float colorsTruck[] = {
	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,

	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,

	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,

	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,

	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,

	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,
};

float texCoordsTruck[] = {
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

unsigned int faceIndexTruck[] = {
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




Truck::Truck(VSMathLib *vsml, VSShaderLib *shader, float x, float y, float z)
{
	VSResSurfRevLib surfRev;

	this->setPosition(x, y, z);
	this->setSpeed(0.075f);
	this->setStep(1.4f);
	this->setRotation(0.0f, 1.0f, 0.0f);
	this->setRotationAngle(180.0f);
	this->setScale(1.0f, 1.0f, 1.0f);
	this->setShader(shader);
	this->setVSML(vsml);
	// create wheel
	surfRev.createCylinder(1.0f, 0.3f, 50);
	this->setResSurfRev(surfRev);
	this->setBoundaries(-12.0f, 12.0f);
	this->setDirection(RIGHT);

	glGenVertexArrays(1, &vaoTruck);
	glBindVertexArray(vaoTruck);

	// create buffers for our vertex data
	GLuint buffersCube[4];
	glGenBuffers(4, buffersCube);

	//vertex coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesTruck), verticesTruck, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::VERTEX_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::VERTEX_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	// 	//texture coordinates buffer
	// 	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[1]);
	// 	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoordsCube), texCoordsCube, GL_STATIC_DRAW);
	// 	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	// 	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 2, GL_FLOAT, 0, 0, 0);

	//color coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorsTruck), colorsTruck, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	//normals buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normalsTruck), normalsTruck, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::NORMAL_ATTRIB);
	glVertexAttribPointer(VSShaderLib::NORMAL_ATTRIB, 3, GL_FLOAT, 0, 0, 0);

	//index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffersCube[3]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(faceIndexTruck), faceIndexTruck, GL_STATIC_DRAW);

	// unbind the VAO
	glBindVertexArray(0);


}


Truck::~Truck()
{
}

void Truck::draw()
{
	getVSML()->loadIdentity(VSMathLib::MODEL);
	
	// Truck
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());


	// body
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.0f, 0.0f, -0.3f);
	getVSML()->scale(2.0f, 0.8f, 0.6f);

	// cube
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.5f, -0.5f, -0.5f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	glBindVertexArray(vaoTruck);
	glDrawElements(GL_TRIANGLES, faceCountTruck * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);
	// cube

	getVSML()->popMatrix(VSMathLib::MODEL);
	// body


	// top
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.25f, 0.0f, 0.3f);
	getVSML()->scale(1.5f, 0.8f, 0.6f);

	// cube
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.5f, -0.5f, -0.5f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	glBindVertexArray(vaoTruck);
	glDrawElements(GL_TRIANGLES, faceCountTruck * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);
	// cube

	getVSML()->popMatrix(VSMathLib::MODEL);
	// top


	// back wheels
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.5f, 0.0f, -0.6f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);
	// back wheels


	// front wheels
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.5f, 0.0f, -0.6f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);
	// front wheels

	getVSML()->popMatrix(VSMathLib::MODEL);
	// Truck
}




