// Frogger.cpp : Defines the entry point for the console application.
//

/** Includes **/
#include "GameMaster.h"

/** Definitions **/
#define CAPTION "Frogger"

/** Variables **/
VSMathLib *vsml;
VSShaderLib shader;
VSResSurfRevLib mySurfRev;

// Camera Position
float camX, camY, camZ;
float ratio;
int camera;

// Mouse Tracking Variables
int startX, startY, tracking = 0;

// Camera Spherical Coordinates
float alpha = -43.0f, beta = 48.0f;
float r = 5.25f;

// Frame counting and FPS computation
long myTime, timebase = 0, frame = 0;
char s[32];

// VAO
GLuint vaoPiramide, vaoCube;

// Display
int WinX = 640, WinY = 480;
int WindowHandle = 0;
unsigned int FrameCount = 0;

/*********************************************************/
/*                                                       */
/*                        SHADERS                        */
/*                                                       */

GLuint setupShaders() {

	// Shader for models
	shader.init();
	shader.loadShader(VSShaderLib::VERTEX_SHADER, "shaders/shader.vert");
	shader.loadShader(VSShaderLib::FRAGMENT_SHADER, "shaders/shader.frag");

	// set semantics for the shader variables
	shader.setProgramOutput(0, "outputF");
	shader.setVertexAttribName(VSShaderLib::VERTEX_COORD_ATTRIB, "position");
	shader.setVertexAttribName(VSShaderLib::NORMAL_ATTRIB, "in_color");
	shader.setVertexAttribName(VSShaderLib::TEXTURE_COORD_ATTRIB, "texCoord");

	shader.prepareProgram();

	printf("InfoLog for Hello World Shader\n%s\n\n", shader.getAllInfoLogs().c_str());

	return(shader.isProgramValid());
}


/*********************************************************/
/*                                                       */
/*                        DISPLAY                        */
/*                                                       */

void changeSize(int w, int h) {
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	ratio = w * 1.0 / h;

	// Reset Matrix
	vsml->loadIdentity(VSMathLib::PROJECTION);
	
	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	vsml->perspective(45.0f, ratio, 0.1f, 100.0f);
}

void renderScene(void) {

	++FrameCount;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//printf("camera %d", camera);
	if (camera == 1){
		vsml->loadIdentity(VSMathLib::PROJECTION);
		vsml->rotate(VSMathLib::PROJECTION, 90.0, -1.0, 0.0, 0.0);
		vsml->ortho(-3.0f, 3.0f, -3.0f, 3.0f, -3.0f, 3.0f);
		vsml->loadIdentity(VSMathLib::VIEW);
		vsml->loadIdentity(VSMathLib::MODEL);
	}
	else if (camera == 2){
		vsml->loadIdentity(VSMathLib::PROJECTION);
		vsml->perspective(45.0f, ratio, 0.1f, 100.0f);
		vsml->loadIdentity(VSMathLib::VIEW);
		vsml->loadIdentity(VSMathLib::MODEL);
		// set the camera using a function similar to gluLookAt
		vsml->lookAt(0.0, 10.0, 0.0, 0, 0, 0, 0, 0, 1);
	}

	else if (camera == 3){
		vsml->loadIdentity(VSMathLib::PROJECTION);
		vsml->perspective(45.0f, ratio, 0.1f, 100.0f);
		vsml->loadIdentity(VSMathLib::VIEW);
		vsml->loadIdentity(VSMathLib::MODEL);
		// set the camera using a function similar to gluLookAt
		vsml->lookAt(camX, camY, camZ, 0, 0, 0, 0, 1, 0);
	}

	truck->draw();

	border->draw();


	/*vsml->pushMatrix(VSMathLib::MODEL);
	vsml->scale(1.0, 0.5, 2.0);
	glUseProgram(shader.getProgramIndex());
	// send matrices to uniform buffer
	vsml->matricesToGL();
	glBindVertexArray(vaoCube);
	glDrawElements(GL_TRIANGLES, faceCountCube * 3, GL_UNSIGNED_INT, 0);
	vsml->popMatrix(VSMathLib::MODEL);

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(0.0, 0.5, 0.6);
	vsml->scale(1.0, 0.3, 1.0);
	glUseProgram(shader.getProgramIndex());
	// send matrices to uniform buffer
	vsml->matricesToGL();
	glBindVertexArray(vaoCube);
	glDrawElements(GL_TRIANGLES, faceCountCube * 3, GL_UNSIGNED_INT, 0);
	vsml->popMatrix(VSMathLib::MODEL);

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(0.5, 0.0, 0.5);
	vsml->rotate(90.0, 0.0, 0.0, 1.0);
	vsml->scale(1.0f, 0.6f, 1.0f);
	glUseProgram(shader.getProgramIndex());
	// send matrices to uniform buffer
	vsml->matricesToGL();
	mySurfRev.render();
	vsml->popMatrix(VSMathLib::MODEL);

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(0.5, 0.0, 1.5);
	vsml->rotate(90.0, 0.0, 0.0, 1.0);
	vsml->scale(1.0f, 0.6f, 1.0f);
	glUseProgram(shader.getProgramIndex());
	// send matrices to uniform buffer
	vsml->matricesToGL();
	mySurfRev.render();
	vsml->popMatrix(VSMathLib::MODEL);

	//vsml->loadIdentity(VSMathLib::MODEL);

	//glBindVertexArray(vao);
	*/

	//swap buffers
	glutSwapBuffers();

}

void timedDisplay(int value){
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timedDisplay, 0);
}

void timer(int value)
{
	std::ostringstream oss;
	oss << CAPTION << ": " << FrameCount << " FPS @ (" << WinX << "x" << WinY << ")";
	std::string s = oss.str();
	glutSetWindow(WindowHandle);
	glutSetWindowTitle(s.c_str());
	FrameCount = 0;
	glutTimerFunc(1000, timer, 0);
}

void idle(){

}

/*********************************************************/
/*                                                       */
/*                        KEYBOARD                       */
/*                                                       */

void processKeys(unsigned char key, int xx, int yy)
{
	switch (key) {

	case 49:
		camera = 1;
		break;

	case 50:
		camera = 2;
		break;

	case 51:
		camera = 3;
		break;

	}
}

/*********************************************************/
/*                                                       */
/*                         MOUSE                         */
/*                                                       */

void processMouseButtons(int button, int state, int xx, int yy)
{
	// start tracking the mouse
	if (state == GLUT_DOWN)  {
		startX = xx;
		startY = yy;
		if (button == GLUT_LEFT_BUTTON)
			tracking = 1;
		else if (button == GLUT_RIGHT_BUTTON)
			tracking = 2;
	}

	//stop tracking the mouse
	else if (state == GLUT_UP) {
		if (tracking == 1) {
			alpha -= (xx - startX);
			beta += (yy - startY);
		}
		else if (tracking == 2) {
			r += (yy - startY) * 0.01f;
			if (r < 0.1f)
				r = 0.1f;
		}
		tracking = 0;
	}
}

// Track mouse motion while buttons are pressed

void processMouseMotion(int xx, int yy)
{

	int deltaX, deltaY;
	float alphaAux, betaAux;
	float rAux;

	deltaX = -xx + startX;
	deltaY = yy - startY;

	// left mouse button: move camera
	if (tracking == 1) {


		alphaAux = alpha + deltaX;
		betaAux = beta + deltaY;

		if (betaAux > 85.0f)
			betaAux = 85.0f;
		else if (betaAux < -85.0f)
			betaAux = -85.0f;
		rAux = r;
	}
	// right mouse button: zoom
	else if (tracking == 2) {

		alphaAux = alpha;
		betaAux = beta;
		rAux = r + (deltaY * 0.01f);
		if (rAux < 0.1f)
			rAux = 0.1f;
	}

	camX = rAux * sin(alphaAux * 3.14f / 180.0f) * cos(betaAux * 3.14f / 180.0f);
	camZ = rAux * cos(alphaAux * 3.14f / 180.0f) * cos(betaAux * 3.14f / 180.0f);
	camY = rAux *   						       sin(betaAux * 3.14f / 180.0f);

	//  uncomment this if not using an idle func
	//	glutPostRedisplay();
}


/*
void createCube() {

	glGenVertexArrays(1, &vaoCube);
	glBindVertexArray(vaoCube);

	// create buffers for our vertex data
	GLuint buffersCube[4];
	glGenBuffers(4, buffersCube);

	//vertex coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesCube), verticesCube, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::VERTEX_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::VERTEX_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	//color coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorsCube), colorsCube, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	//normals buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersCube[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normalsCube), normalsCube, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::NORMAL_ATTRIB);
	glVertexAttribPointer(VSShaderLib::NORMAL_ATTRIB, 3, GL_FLOAT, 0, 0, 0);

	//index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffersCube[3]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(faceIndexCube), faceIndexCube, GL_STATIC_DRAW);

	// unbind the VAO
	glBindVertexArray(0);

}*/

/*********************************************************/
/*                                                       */
/*                    INITIALIZATIONS                    */
/*                                                       */

void initOpenGL()
{

	camera = 1;
	// set the camera position based on its spherical coordinates
	camX = r * sin(alpha * 3.14f / 180.0f) * cos(beta * 3.14f / 180.0f);
	camZ = r * cos(alpha * 3.14f / 180.0f) * cos(beta * 3.14f / 180.0f);
	camY = r *   						     sin(beta * 3.14f / 180.0f);

	mySurfRev.createSphere(0.2, 50);

	/*mySurfRev.createCylinder(2.0, 0.2, 50);*/

	// some GL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_MULTISAMPLE);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

}

void initVSL() {
	vsml = VSMathLib::getInstance();
	// tell VSL the uniform block name
	vsml->setUniformBlockName("Matrices");
	// set semantics for the matrix variable
	vsml->setUniformName(VSMathLib::PROJ_VIEW_MODEL, "pvm");
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);

	//versao e flags
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutInitContextFlags(GLUT_DEBUG);

	//criar janela
	glutInitWindowPosition(300, 100);
	glutInitWindowSize(WinX, WinY);
	WindowHandle = glutCreateWindow(CAPTION);

	// register callbacks
	// o que desenhar na janela
	glutDisplayFunc(renderScene);

	// faz reshape - com que o que e desenhado nao seja distorcido
	glutReshapeFunc(changeSize);

	// here is the idle func registration - serve para a animacao
	glutIdleFunc(idle);

	glutKeyboardFunc(processKeys);
	glutMouseFunc(processMouseButtons);
	glutMotionFunc(processMouseMotion);

	//returns from mainloop
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	//	Init GLEW
	glewExperimental = GL_TRUE;
	glewInit();

	if (!setupShaders())
		return(1);

	initOpenGL();

	//inicializa a mathlib

	initVSL();

	glutTimerFunc(0, timedDisplay, 0);
	glutTimerFunc(0, timer, 0);

	truck = new Truck(vsml, &shader);
	truck->move(1.0, 1.0);

	border = new Border(vsml, &shader);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}


