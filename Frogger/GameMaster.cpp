// Frogger.cpp : Defines the entry point for the console application.
//

/** Includes **/
#include "GameMaster.h"
#include "Entity.h"


/** Definitions **/
#define CAPTION "Frogger"

/** Variables **/
VSMathLib *vsml;
VSShaderLib shader;
VSResSurfRevLib mySurfRev;
Truck * truck;
Border * border;
Border * border2;
Margin * margin;
Margin * margin2;
Road * road;
River * river;
Frog * frog;
Turtle * turtle;
Car * car;
Log * stem;
Bus * bus;

// Camera Position
float camX, camY, camZ;
float ratio;
int camera;

//Frog stuff
int frogJump, frogRot;

// Mouse Tracking Variables
int startX, startY;
int tracking = 0;

// Camera Spherical Coordinates
float alpha = -43.0f, beta = 48.0f;
float r = 5.25f;

// Frame counting and FPS computation
long myTime, timebase = 0, frame = 0;
char s[32];

// Boolean state variables
bool hasFrogCamMoved = false;

// VAO
GLuint vaoPiramide, vaoCube;

// Display
int WinX = 1366, WinY = 768;
int WindowHandle = 0;
unsigned int FrameCount = 0;

/*********************************************************/
/*                                                       */
/*                        GAME	                         */
/*                                                       */

void speedUpCharacters(int value)
{
	turtle->speedUp();
	stem->speedUp();
	truck->speedUp();
	car->speedUp();
	bus->speedUp();

	glutTimerFunc(20000, speedUpCharacters, 0);
}

void moveCharacters(int value)
{
	if(stem->isAlive())
		stem->move();

	if (turtle->isAlive()) 
		turtle->move();

	if (truck->isAlive())
		truck->move();

	if (car->isAlive())
		car->move();

	if (bus->isAlive())
		bus->move();

	glutTimerFunc(25, moveCharacters, 0);
}

void moveFrog()
{
	if (frogJump == 1){
		frog->move(0.0, -1.0);
		frogJump = 0;
	}
	else if (frogJump == 2){
		frog->move(0.0, 1.0);
		frogJump = 0;
	}
	else if (frogJump == 3){
		frog->move(-1.0, 0.0);
		frogJump = 0;
	}
	else if (frogJump == 4){
		frog->move(1.0, 0.0);
		frogJump = 0;
	}
}

void drawObjects()
{
	border->draw();
	border2->draw();
	margin->draw();
	margin2->draw();
	road->draw();
	river->draw();

	frog->draw();

	if (stem->isAlive())
		stem->draw();

	if (turtle->isAlive())
		turtle->draw();

	if (truck->isAlive())
		truck->draw();

	if (car->isAlive())
		car->draw();

	if (bus->isAlive())
		bus->draw();
}

void initObjects()
{
	truck = new Truck(vsml, &shader, -6.7, 0.0, 1.9);

	frog = new Frog(vsml, &shader, 0.0, -0.2, 5.85);
	frogJump = 0;
	frogRot = 1;
	//frogMouseMove = 0;

	car = new Car(vsml, &shader, 6.7, 0, 2.8);

	road = new Road(vsml, &shader, -8.0, -1.23, 1.0);
	river = new River(vsml, &shader, -8.0, -1.23, -4.0);

	border = new Border(vsml, &shader, -8.0, -1.23, 5.0);
	border2 = new Border(vsml, &shader, -8.0, -1.23, 0.0);

	stem = new Log(vsml, &shader, -6.8, -0.5, -3.5);

	margin = new Margin(vsml, &shader, -8.0, -1.23, -1.0);
	margin2 = new Margin(vsml, &shader, -8.0, -1.23, -5.0);

	turtle = new Turtle(vsml, &shader, 7.4, -0.4, -2.5);

	bus = new Bus(vsml, &shader, -8.2, 0, 3.0);
}



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

void updateCamera(){

	if (camera == 1){
		vsml->loadIdentity(VSMathLib::PROJECTION);
		//vsml->rotate(VSMathLib::PROJECTION, 90.0, -1.0, 0.0, 0.0);
		vsml->ortho(-8.0f*ratio, 8.0f*ratio, -8.0f, 8.0f, -6.0f, 6.0f);
		vsml->loadIdentity(VSMathLib::VIEW);
		vsml->loadIdentity(VSMathLib::MODEL);
	}
	else if (camera == 2){
		vsml->loadIdentity(VSMathLib::PROJECTION);
		vsml->perspective(45.0f, ratio, 0.1f, 100.0f);
		vsml->loadIdentity(VSMathLib::VIEW);
		vsml->loadIdentity(VSMathLib::MODEL);
		// set the camera using a function similar to gluLookAt
		vsml->lookAt(0.0f, -16.0f, 16.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	}
	else if (camera == 3){
		vsml->loadIdentity(VSMathLib::PROJECTION);
		vsml->perspective(45.0f, ratio, 0.1f, 100.0f);
		vsml->loadIdentity(VSMathLib::VIEW);
		vsml->loadIdentity(VSMathLib::MODEL);
		// set the camera using a function similar to gluLookAt

		if (tracking == 1) //testing to see if user is looking around
		{
			vsml->lookAt(frog->getPosition()->getX() + 0.25f, 0.5f, frog->getPosition()->getZ() + 1, camX, camY, frog->getPosition()->getZ() - 5, 0, 1, 0);
		}
		else{
			vsml->lookAt(frog->getPosition()->getX() + 0.25f, 0.5f, frog->getPosition()->getZ() + 1, frog->getPosition()->getX() + 0.25f, frog->getPosition()->getY() + 0.25f, frog->getPosition()->getZ() - 5, 0, 1, 0);
		}
	}

	glutPostRedisplay();
}


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
	updateCamera();

}

void renderScene(void) {

	++FrameCount;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	

	//moves the frog acording to user input
	moveFrog();

	if (camera == 3 && hasFrogCamMoved){
		updateCamera();
		hasFrogCamMoved = false;
	}
	//draws all objects on scene
	drawObjects();

	//swap buffers
	glutSwapBuffers();

}

/*********************************************************/
/*                                                       */
/*                        Timers                         */
/*                                                       */

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

void giveLife(int value)
{
	int randomValue = rand() % 100;

	if (randomValue < 20){ //create object -- no futuro dar outro valor rand ao randomValue para escolher um objecto qlq
		
		turtle->setAlive(true);
	}

	if (randomValue >=20 && randomValue < 40){ //create object -- no futuro dar outro valor rand ao randomValue para escolher um objecto qlq

		stem->setAlive(true);
	}

	if (randomValue >= 40 && randomValue < 60){ //create object -- no futuro dar outro valor rand ao randomValue para escolher um objecto qlq

		truck->setAlive(true);
	}

	if (randomValue >= 60 && randomValue < 80){ //create object -- no futuro dar outro valor rand ao randomValue para escolher um objecto qlq

		car->setAlive(true);
	}

	if (randomValue >= 80 && randomValue < 100){

		bus->setAlive(true);
	}
	

	glutTimerFunc(2000, giveLife, 0);
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
		updateCamera();
		break;

	case 50:
		camera = 2;
		updateCamera();
		break;

	case 51:
		camera = 3;
		updateCamera();
		break;

	case 113:
		hasFrogCamMoved = true;
		frogJump = 1;
		break;

	case 97:
		hasFrogCamMoved = true;
		frogJump = 2;
		break;

	case 111:
		hasFrogCamMoved = true;
		frogJump = 3;
		break;

	case 112:
		hasFrogCamMoved = true;
		frogJump = 4;
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

		if (button == GLUT_LEFT_BUTTON){
			tracking = 1;
		}
		else if (button == GLUT_RIGHT_BUTTON){
			tracking = 2;
		}
	}


	//stop tracking the mouse
	else if (state == GLUT_UP) {
		if (tracking == 1) {
			alpha -= (xx - startX);
			beta += (yy - startY);
		}
		else if (tracking == 2) {

			// alterar para so mexer com um modulo maior que um dado numero (diminuir jitter)
			if (abs(xx - startX) > abs(yy - startY)){
				if (xx - startX > 0){
					frog->move(1.0, 0.0);
				}
				else{
					frog->move(-1.0, 0.0);
				}

			}
			else {
				if (yy - startY > 0){
					frog->move(0.0, 1.0);
				}
				else{
					frog->move(0.0, -1.0);
				}
			}

			startX = xx;
			startY = yy;
		}
		

		tracking = 0;


		updateCamera();
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

		if (camera == 3) //camera can only be moved in 1st person
			updateCamera();

		camX = rAux * sin(alphaAux * 3.14f / 180.0f) * cos(betaAux * 3.14f / 180.0f);
		camZ = rAux * cos(alphaAux * 3.14f / 180.0f) * cos(betaAux * 3.14f / 180.0f);
		camY = rAux *   						       sin(betaAux * 3.14f / 180.0f);
	}


	//  uncomment this if not using an idle func
	//	glutPostRedisplay();
}


/*********************************************************/
/*                                                       */
/*                    INITIALIZATIONS                    */
/*                                                       */

void initOpenGL()
{

	camera = 1;
	// set the camera position based on its spherical coordinates
	camX = 0;
	camZ = 0;
	camY = 0;

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

	// mouse starting point
	startX = WinX / 2;
	startY = WinY / 2;

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

	//creation of random seed
	srand(time(NULL));

	glutTimerFunc(0, timedDisplay, 0);
	glutTimerFunc(0, timer, 0);
	glutTimerFunc(0, moveCharacters, 0);
	glutTimerFunc(10000, speedUpCharacters, 0);
	glutTimerFunc(0, giveLife, 0);

	initObjects();

	//set up camera initially
	updateCamera();

	glutWarpPointer(WinX / 2, WinY / 2);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}


