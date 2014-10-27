#include "Bus.h"

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






Bus::Bus(VSMathLib *vsml, VSShaderLib *shader, float x, float y, float z) : DynamicObject(x, y, z, 0.05f)
{

	VSResSurfRevLib surfRev;

	this->setPosition(x, y, z);
	this->setSpeed(0.05f);
	this->setStep(1.4f);
	this->setRotation(0.0f, 0.0f, 0.0f);
	this->setRotationAngle(0.0f);
	this->setScale(1.0f, 1.0f, 1.0f);
	this->setShader(shader);
	this->setVSML(vsml);
	// create wheel
	surfRev.createCylinder(1.0f, 0.3f, 50);
	this->setResSurfRev(surfRev);
	this->setMoveBoundaries(-11.5f, 11.5f);
	this->setDirection(RIGHT);
	this->setCharBoundaries(1.5f, 0.5f);

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

	// Bus
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	//getVSML()->rotate(rotAngle, rotation->getX(), rotation->getY(), rotation->getZ());
	//getVSML()->scale(scale->getX(), scale->getY(), scale->getZ());


	// body
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->scale(3.0f, 0.8f, 1.4f);

	// cube
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.5f, -0.5f, -0.5f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	glBindVertexArray(vaoBus);
	glDrawElements(GL_TRIANGLES, faceCountBus * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);
	// cube

	getVSML()->popMatrix(VSMathLib::MODEL);
	// body


	// window
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.2f, 0.0f, 0.35f);
	getVSML()->scale(2.6004f, 0.8006f, 0.5f);

	// cube
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.5f, -0.5f, -0.5f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	glBindVertexArray(vaoBus2);
	glDrawElements(GL_TRIANGLES, faceCountBus * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);
	// cube
	
	getVSML()->popMatrix(VSMathLib::MODEL);
	// window


	// back wheels
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-1.0f, 0.0f, -0.7f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);

	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.3f, 0.0f, -0.7f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);
	// back wheels

	// front wheels
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(1.0f, 0.0f, -0.7f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);
	// front wheels

	getVSML()->popMatrix(VSMathLib::MODEL);
	// Bus

}