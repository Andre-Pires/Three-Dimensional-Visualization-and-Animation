#include "River.h"

int verticeCountRiver = 24;
int faceCountRiver = 12;

float verticesRiver[] = {
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

float normalsRiver[] = {
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

float colorsRiver[] = {

	0.0f, 0.5f, 0.5f, 1.0f,
	0.0f, 0.5f, 0.5f, 1.0f,
	0.0f, 0.5f, 0.5f, 1.0f,
	0.0f, 0.5f, 0.5f, 1.0f,

	0.0f, 0.5f, 0.5f, 1.0f,
	0.0f, 0.5f, 0.5f, 1.0f,
	0.0f, 0.5f, 0.5f, 1.0f,
	0.0f, 0.5f, 0.5f, 1.0f,

	0.0f, 0.5f, 0.5f, 1.0f,
	0.0f, 0.5f, 0.5f, 1.0f,
	0.0f, 0.5f, 0.5f, 1.0f,
	0.0f, 0.5f, 0.5f, 1.0f,

	0.0f, 0.5f, 0.5f, 1.0f,
	0.0f, 0.5f, 0.5f, 1.0f,
	0.0f, 0.5f, 0.5f, 1.0f,
	0.0f, 0.5f, 0.5f, 1.0f,

	0.0f, 0.5f, 0.5f, 1.0f,
	0.0f, 0.5f, 0.5f, 1.0f,
	0.0f, 0.5f, 0.5f, 1.0f,
	0.0f, 0.5f, 0.5f, 1.0f,

	0.0f, 0.5f, 0.5f, 1.0f,
	0.0f, 0.5f, 0.5f, 1.0f,
	0.0f, 0.5f, 0.5f, 1.0f,
	0.0f, 0.5f, 0.5f, 1.0f
	
};

float texCoordsRiver[] = {
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

unsigned int faceIndexRiver[] = {
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




River::River(VSMathLib *vsml, VSShaderLib *shader, float x, float y, float z)
{
	this->setPosition(x, y, z);
	this->setRotation(0.0f, 0.0f, 0.0f);
	this->setRotationAngle(0.0f);
	this->setScale(16.0f, 0.5f, 3.0f);
	this->setShader(shader);
	this->setVSML(vsml);

	glGenVertexArrays(1, &vaoRiver);
	glBindVertexArray(vaoRiver);

	// create buffers for our vertex data
	GLuint buffersCube[4];
	glGenBuffers(4, buffersCube);

	//vertex coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesRiver), verticesRiver, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::VERTEX_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::VERTEX_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	// 	//texture coordinates buffer
	// 	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[1]);
	// 	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoordsCube), texCoordsCube, GL_STATIC_DRAW);
	// 	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	// 	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 2, GL_FLOAT, 0, 0, 0);

	//color coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorsRiver), colorsRiver, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	//normals buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normalsRiver), normalsRiver, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::NORMAL_ATTRIB);
	glVertexAttribPointer(VSShaderLib::NORMAL_ATTRIB, 3, GL_FLOAT, 0, 0, 0);

	//index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffersCube[3]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(faceIndexRiver), faceIndexRiver, GL_STATIC_DRAW);

	// unbind the VAO
	glBindVertexArray(0);


}


River::~River()
{
}

void River::draw()
{
	Vector3D * scale = getScale();

	// River
	getVSML()->pushMatrix(VSMathLib::MODEL);
	getVSML()->loadIdentity(VSMathLib::MODEL);
	getVSML()->translate(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	getVSML()->scale(scale->getX(), scale->getY(), scale->getZ());
	glUseProgram((*getShader()).getProgramIndex());
	// send matrices to uniform buffer

	getVSML()->matricesToGL();
	glBindVertexArray(vaoRiver);
	glDrawElements(GL_TRIANGLES, faceCountRiver * 3, GL_UNSIGNED_INT, 0);
	getVSML()->popMatrix(VSMathLib::MODEL);
	// River
}