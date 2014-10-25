#include "Frog.h"

int verticeCountHead = 15;
int faceCountHead = 10;

float verticesHead[] = {
	0.0f, 0.0f, 0.0f, 1.0f,
	0.5f, 1.0f, 0.5f, 1.0f, // face vermelha
	0.0f, 0.0f, 1.0f, 1.0f,

	0.0f, 0.0f, 1.0f, 1.0f,
	0.5f, 1.0f, 0.5f, 1.0f, // face azul
	1.0f, 0.0f, 1.0f, 1.0f,

	1.0f, 0.0f, 1.0f, 1.0f,
	0.5f, 1.0f, 0.5f, 1.0f, // face amarela
	1.0f, 0.0f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 1.0f,
	0.5f, 1.0f, 0.5f, 1.0f, // face roxa
	0.0f, 0.0f, 0.0f, 1.0f,

	0.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f, // base
	1.0f, 0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f
};

float normalsHead[] = {
	-0.5f, 0.5f, 0.0f,
	-0.5f, 0.5f, 0.0f,
	-0.5f, 0.5f, 0.0f,

	0.0f, 0.5f, 0.5f,
	0.0f, 0.5f, 0.5f,
	0.0f, 0.5f, 0.5f,

	0.5f, 0.5f, 0.0f,
	0.5f, 0.5f, 0.0f,
	0.5f, 0.5f, 0.0f,

	0.0f, 0.5f, -0.5f,
	0.0f, 0.5f, -0.5f,
	0.0f, 0.5f, -0.5f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f
};

float colorsHead[] = {
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


};

float texCoordsHead[] = {
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.5f, 1.0f,

	0.0f, 0.0f,
	1.0f, 0.0f,
	0.5f, 1.0f,

	0.0f, 0.0f,
	1.0f, 0.0f,
	0.5f, 1.0f,

	0.0f, 0.0f,
	1.0f, 0.0f,
	0.5f, 1.0f,

	0.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 1.0f,
};

unsigned int faceIndexHead[] = {
	2, 1, 0,
	5, 4, 3,
	8, 7, 6,
	11, 10, 9,
	14, 13, 12,
	14, 12, 15
};

int verticeCountBody = 24;
int faceCountBody = 12;

float verticesBody[] = {
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

float normalsBody[] = {
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

float colorsBody[] = {
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

float texCoordsBody[] = {
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

unsigned int faceIndexBody[] = {
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


Frog::Frog(VSMathLib *vsml, VSShaderLib *shader, float x, float y, float z)
{
	VSResSurfRevLib surfRev;

	this->setPosition(x, y, z);
	this->setSpeed(0.1f);
	this->setStep(1.4f);
	this->setRotation(0.0f, 1.0f, 0.0f);
	this->setRotationAngle(90.0f);
	this->setScale(0.5f, 0.5f, 0.5f);
	this->setShader(shader);
	this->setVSML(vsml);
	// create eye
	surfRev.createSphere(0.2f, 50);
	this->setResSurfRev(surfRev);


	// create head
	glGenVertexArrays(1, &vaoHead);
	glBindVertexArray(vaoHead);

	// create buffers for our vertex data
	GLuint buffersHead[4];
	glGenBuffers(4, buffersHead);

	//vertex coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersHead[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesHead), verticesHead, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::VERTEX_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::VERTEX_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	// 	//texture coordinates buffer
	// 	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[1]);
	// 	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoordsCube), texCoordsCube, GL_STATIC_DRAW);
	// 	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	// 	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 2, GL_FLOAT, 0, 0, 0);

	//color coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersHead[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorsHead), colorsHead, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	//normals buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersHead[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normalsHead), normalsHead, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::NORMAL_ATTRIB);
	glVertexAttribPointer(VSShaderLib::NORMAL_ATTRIB, 3, GL_FLOAT, 0, 0, 0);

	//index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffersHead[3]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(faceIndexHead), faceIndexHead, GL_STATIC_DRAW);

	// unbind the VAO
	glBindVertexArray(0);


	// create body
	glGenVertexArrays(1, &vaoBody);
	glBindVertexArray(vaoBody);

	// create buffers for our vertex data
	GLuint buffersBody[4];
	glGenBuffers(4, buffersBody);

	//vertex coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersBody[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesBody), verticesBody, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::VERTEX_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::VERTEX_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	// 	//texture coordinates buffer
	// 	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[1]);
	// 	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoordsCube), texCoordsCube, GL_STATIC_DRAW);
	// 	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	// 	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 2, GL_FLOAT, 0, 0, 0);

	//color coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersBody[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorsBody), colorsBody, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	//normals buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersBody[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normalsBody), normalsBody, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::NORMAL_ATTRIB);
	glVertexAttribPointer(VSShaderLib::NORMAL_ATTRIB, 3, GL_FLOAT, 0, 0, 0);

	//index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffersBody[3]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(faceIndexBody), faceIndexBody, GL_STATIC_DRAW);

	// unbind the VAO
	glBindVertexArray(0);


}


Frog::~Frog()
{
}

void Frog::draw()
{
	float rotAngle = getRotationAngle();
	Vector3D * rotation = getRotation();
	Vector3D * scale = getScale();

	getVSML()->loadIdentity(VSMathLib::MODEL);
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	getVSML()->rotate(rotAngle, rotation->getX(), rotation->getY(), rotation->getZ());
	getVSML()->scale(scale->getX(), scale->getY(), scale->getZ());

	/** Head **/
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(1.0, 1.0, 0.0);
	getVSML()->rotate(-90.0f, 0.0f, 0.0f, 1.0f);
	getVSML()->scale(0.7, 0.5, 1.0);

	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	glBindVertexArray(vaoHead);
	glDrawElements(GL_TRIANGLES, faceCountHead * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);
	/**********/

	/** Body **/
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.0, 0.3, 0.0);
	getVSML()->scale(1.0, 0.7, 1.0);

	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	glBindVertexArray(vaoBody);
	glDrawElements(GL_TRIANGLES, faceCountBody * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);
	/**********/


	/** eyes **/
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(1.2, 0.8, 0.2);
	getVSML()->scale(0.45f, 0.45f, 0.45f);

	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);

	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(1.2, 0.8, 0.8);
	getVSML()->scale(0.45f, 0.45f, 0.45f);

	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);
	/**********/


	/** legs **/
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.0, 0.2, -0.1);
	getVSML()->scale(0.2f, 0.1f, 0.2f);

	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	glBindVertexArray(vaoBody);
	glDrawElements(GL_TRIANGLES, faceCountBody * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);

	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.8, 0.2, -0.1);
	getVSML()->scale(0.2f, 0.1f, 0.2f);

	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	glBindVertexArray(vaoBody);
	glDrawElements(GL_TRIANGLES, faceCountBody * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);

	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.0, 0.2, 0.9);
	getVSML()->scale(0.2f, 0.1f, 0.2f);

	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	glBindVertexArray(vaoBody);
	glDrawElements(GL_TRIANGLES, faceCountBody * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);

	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.8, 0.2, 0.9);
	getVSML()->scale(0.2f, 0.1f, 0.2f);

	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	glBindVertexArray(vaoBody);
	glDrawElements(GL_TRIANGLES, faceCountBody * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);
	/**********/

	getVSML()->popMatrix(VSMathLib::MODEL);


}

void Frog::move(float x, float z)
{
	float posY = getPosition()->getY();
	float posX = getPosition()->getX();
	float posZ = getPosition()->getZ();

	setPosition(posX + x, posY, posZ + z);
}

