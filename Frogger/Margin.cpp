#include "Margin.h"

int verticeCountMargin = 24;
int faceCountMargin = 12;

float verticesMargin[] = {
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

float normalsMargin[] = {
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

float colorsMargin[] = {

	0.3f, 0.9f, 0.0f, 1.0f,
	0.3f, 0.9f, 0.0f, 1.0f,
	0.3f, 0.9f, 0.0f, 1.0f,
	0.3f, 0.9f, 0.0f, 1.0f,

	0.3f, 0.9f, 0.0f, 1.0f,
	0.3f, 0.9f, 0.0f, 1.0f,
	0.3f, 0.9f, 0.0f, 1.0f,
	0.3f, 0.9f, 0.0f, 1.0f,
	
	0.3f, 0.9f, 0.0f, 1.0f,
	0.3f, 0.9f, 0.0f, 1.0f,
	0.3f, 0.9f, 0.0f, 1.0f,
	0.3f, 0.9f, 0.0f, 1.0f,

	0.44f, 0.26f, 0.08f, 1.0f,
	0.44f, 0.26f, 0.08f, 1.0f,
	0.44f, 0.26f, 0.08f, 1.0f,
	0.44f, 0.26f, 0.08f, 1.0f,

	0.3f, 0.9f, 0.0f, 1.0f,
	0.3f, 0.9f, 0.0f, 1.0f,
	0.3f, 0.9f, 0.0f, 1.0f,
	0.3f, 0.9f, 0.0f, 1.0f,

	0.44f, 0.26f, 0.08f, 1.0f,
	0.44f, 0.26f, 0.08f, 1.0f,
	0.44f, 0.26f, 0.08f, 1.0f,
	0.44f, 0.26f, 0.08f, 1.0f





};

float texCoordsMargin[] = {
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

unsigned int faceIndexMargin[] = {
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




Margin::Margin(VSMathLib *vsml, VSShaderLib *shader, float x, float y, float z)
{
	this->setPosition(x, y, z);
	this->setRotation(0.0f, 0.0f, 0.0f);
	this->setRotationAngle(0.0f);
	this->setScale(26.0f, 1.2f, 1.0f);
	this->setShader(shader);
	this->setVSML(vsml);
	this->setSceneryBoundaries(13.0f, 0.6f);

	glGenVertexArrays(1, &vaoMargin);
	glBindVertexArray(vaoMargin);

	// create buffers for our vertex data
	GLuint buffersCube[4];
	glGenBuffers(4, buffersCube);

	//vertex coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesMargin), verticesMargin, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::VERTEX_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::VERTEX_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	// 	//texture coordinates buffer
	// 	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[1]);
	// 	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoordsCube), texCoordsCube, GL_STATIC_DRAW);
	// 	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	// 	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 2, GL_FLOAT, 0, 0, 0);

	//color coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorsMargin), colorsMargin, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	//normals buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normalsMargin), normalsMargin, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::NORMAL_ATTRIB);
	glVertexAttribPointer(VSShaderLib::NORMAL_ATTRIB, 3, GL_FLOAT, 0, 0, 0);

	//index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffersCube[3]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(faceIndexMargin), faceIndexMargin, GL_STATIC_DRAW);

	// unbind the VAO
	glBindVertexArray(0);


}


Margin::~Margin()
{
}

void Margin::draw()
{

	Vector3D * scale = getScale();

	getVSML()->loadIdentity(VSMathLib::MODEL);

	// Margin
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	getVSML()->scale(scale->getX(), scale->getY(), scale->getZ());

	// cube
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->translate(-0.5f, -0.5f, -0.5f);
	glUseProgram((*getShader()).getProgramIndex());
	
	getVSML()->matricesToGL();
	glBindVertexArray(vaoMargin);
	glDrawElements(GL_TRIANGLES, faceCountMargin * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);
	// cube

	getVSML()->popMatrix(VSMathLib::MODEL);
	// Margin
}



