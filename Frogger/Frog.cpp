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


Frog::Frog(VSMathLib *vsml, VSShaderLib *shader, float x, float y, float z) : DynamicObject(x, y, z)
{
	VSResSurfRevLib surfRev;

	this->setPosition(x, y, z);
	this->initialPosition.set(x, y, z);
	this->setRotation(0.0f, 1.0f, 0.0f);
	this->setRotationAngle(0.0f);
	this->setScale(1.0f, 1.0f, 1.0f);
	this->setShader(shader);
	this->setVSML(vsml);
	// create eye
	surfRev.createSphere(0.5f, 50);
	this->setResSurfRev(surfRev);
	this->setCharBoundaries(0.5f,0.4f);

	lives = 5;

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

	// Frog
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	getVSML()->rotate(rotAngle, rotation->getX(), rotation->getY(), rotation->getZ());
	getVSML()->scale(scale->getX(), scale->getY(), scale->getZ());

	// head
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.0f, 0.35, 0.0);
	getVSML()->scale(0.6f, 0.3f, 0.3f);

	// pyramid
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.5f, -0.5f, -0.5f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	glBindVertexArray(vaoHead);
	glDrawElements(GL_TRIANGLES, faceCountHead * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);
	//pyramid 

	getVSML()->popMatrix(VSMathLib::MODEL);
	// head


	// body
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.0f, -0.05f, 0.0f);
	getVSML()->scale(0.6f, 0.5f, 0.3f);

	// cube
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.5f, -0.5f, -0.5f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	glBindVertexArray(vaoBody);
	glDrawElements(GL_TRIANGLES, faceCountBody * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);
	// cube 

	getVSML()->popMatrix(VSMathLib::MODEL);
	// body


	// eyes
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.15f, 0.35f, 0.1f);
	getVSML()->scale(0.15f, 0.15f, 0.15f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);

	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.15f, 0.35f, 0.1f);
	getVSML()->scale(0.15f, 0.15f, 0.15f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	getResSurfRev().render();
	getVSML()->popMatrix(VSMathLib::MODEL);
	// eyes
	

	// legs
	// 1
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.3f, 0.1f, -0.2f);
	getVSML()->scale(0.2f, 0.2f, 0.1f);

	// cube
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.5f, -0.5f, -0.5f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	glBindVertexArray(vaoBody);
	glDrawElements(GL_TRIANGLES, faceCountBody * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);
	//cube

	getVSML()->popMatrix(VSMathLib::MODEL);
	// 1

	// 2
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.3f, 0.1f, -0.2f);
	getVSML()->scale(0.2f, 0.2f, 0.1f);

	// cube
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.5f, -0.5f, -0.5f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	glBindVertexArray(vaoBody);
	glDrawElements(GL_TRIANGLES, faceCountBody * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);
	// cube

	getVSML()->popMatrix(VSMathLib::MODEL);
	// 2

	// 3
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.3f, -0.3f, -0.2f);
	getVSML()->scale(0.2f, 0.2f, 0.1f);

	// cube
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.5f, -0.5f, -0.5f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	glBindVertexArray(vaoBody);
	glDrawElements(GL_TRIANGLES, faceCountBody * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);
	// cube

	getVSML()->popMatrix(VSMathLib::MODEL);
	// 3

	// 4
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(0.3f, -0.3f, -0.2f);
	getVSML()->scale(0.2f, 0.2f, 0.1f);

	// cube
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.5f, -0.5f, -0.5f);
	glUseProgram((*getShader()).getProgramIndex());

	getVSML()->matricesToGL();
	glBindVertexArray(vaoBody);
	glDrawElements(GL_TRIANGLES, faceCountBody * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);
	// cube

	getVSML()->popMatrix(VSMathLib::MODEL);
	// 4

	getVSML()->popMatrix(VSMathLib::MODEL);


}

// Refactorizar no futuro
void Frog::move(float x, float y) 
{
	float posY = getPosition()->getY();
	float posX = getPosition()->getX();
	float posZ = getPosition()->getZ();
	
	if (posX < 12.0f && posX > -12.0f)
		setPosition(posX + x, posY, posZ);
	else{
		if (posX <= -12.0f && (x > 0))
			setPosition(posX + x, posY, posZ);
		else if (posX >= 12.0f && (x < 0))
			setPosition(posX + x, posY, posZ);
	}

	posY = getPosition()->getY();
	posX = getPosition()->getX();

	if (posY < 6.0f && posY > -6.0f)
		setPosition(posX, posY + y, posZ);
	else{
		if (posY <= -6.0f && (y > 0))
			setPosition(posX, posY + y, posZ);
		else if (posY >= 6.0f && (y < 0))
			setPosition(posX, posY + y, posZ);
	}
}	

int Frog::getLives()
{
	return lives;
}

void Frog::loseLife()
{
	lives--;
	this->resetFroggerPosition();
}

void Frog::resetCharacter()
{
	lives = 5;
	this->resetFroggerPosition();
}

void Frog::resetFroggerPosition()
{
	this->setPosition(initialPosition.getX(), initialPosition.getY(), initialPosition.getZ());
}