// Frogger.cpp : Defines the entry point for the console application.
//

/** Includes **/
#include "GameMaster.h"
#include "Entity.h"
#include "Camera.h"

using namespace std;

/** Definitions **/
#define CAPTION "Frogger"

/** Variables **/
VSMathLib *vsml;
VSShaderLib shader;
VSResSurfRevLib mySurfRev;
Camera * camera;

/** Scenery **/
Border * border;
Border * border2;
Margin * margin;
Margin * margin2;
Road * road;
River * river;

/** Movables **/
Frog * frog;
Truck * trucks[5];
Turtle * turtles[5];
Car * cars[5];
Bus * buses[5];
Log * stems[5];

// Camera Position
float camX, camY, camZ;
int camState;

//Frog stuff
int frogJump, frogRot;

// Mouse Tracking Variables
int startX, startY;
int mouseState = 0;

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

	for (int i = 0; i < 5; i++)
	{
		turtles[i]->speedUp();
		stems[i]->speedUp();
		trucks[i]->speedUp();
		cars[i]->speedUp();
		buses[i]->speedUp();
	}

	glutTimerFunc(20000, speedUpCharacters, 0);
}

void collisionDetector(int value)
{
	vector<float> frogBounds = frog->getCharBoundaries();

	for (int i = 0; i < 5; i++)
	{
		if (trucks[i]->isAlive()){
			vector<float> objBounds = trucks[i]->getCharBoundaries();
		
			if (frogBounds[1] <= objBounds[0] && frogBounds[0] >= objBounds[1]){
				if (frogBounds[3] <= objBounds[2] && frogBounds[2] >= objBounds[3]){
					printf("truck");
					goto alreadyHadACollision;
				}
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (cars[i]->isAlive()){
			vector<float> objBounds = cars[i]->getCharBoundaries();

			if (frogBounds[1] <= objBounds[0] && frogBounds[0] >= objBounds[1]){
				if (frogBounds[3] <= objBounds[2] && frogBounds[2] >= objBounds[3]){
					printf("cars");
					goto alreadyHadACollision;
				}
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (buses[i]->isAlive()){
			vector<float> objBounds = buses[i]->getCharBoundaries();

			if (frogBounds[1] <= objBounds[0] && frogBounds[0] >= objBounds[1]){
				if (frogBounds[3] <= objBounds[2] && frogBounds[2] >= objBounds[3]){
					printf("buses");
					goto alreadyHadACollision;
				}
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (stems[i]->isAlive()){
			vector<float> objBounds = stems[i]->getCharBoundaries();

			if (frogBounds[1] <= objBounds[0] && frogBounds[0] >= objBounds[1] 
				&& frogBounds[3] <= objBounds[2] && frogBounds[2] >= objBounds[3]){ 
					printf("stems");
					goto alreadyHadACollision;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (turtles[i]->isAlive()){
			vector<float> objBounds = turtles[i]->getCharBoundaries();

			if (frogBounds[1] <= objBounds[0] && frogBounds[0] >= objBounds[1]){
				if (frogBounds[3] <= objBounds[2] && frogBounds[2] >= objBounds[3]){
					printf("turtles");
					goto alreadyHadACollision;
				}
			}
		}
	}

	alreadyHadACollision:
	glutTimerFunc(25, collisionDetector, 0);
}

void moveCharacters(int value)
{

	for (int i = 0; i < 5; i++)
	{
		if(stems[i]->isAlive())
			stems[i]->move();

		if (turtles[i]->isAlive()) 
			turtles[i]->move();

		if (trucks[i]->isAlive())
			trucks[i]->move();

		if (cars[i]->isAlive())
			cars[i]->move();

		if (buses[i]->isAlive())
			buses[i]->move();
	}

	glutTimerFunc(25, moveCharacters, 0);
}


void moveFrog()
{
	
	if (frogJump == 1){
		frog->move(0.0f, 1.2f);
		frogJump = 0;
	}else if (frogJump == 2){
		frog->move(0.0f, -1.2f);
		frogJump = 0;
	}
	else if (frogJump == 3){
		frog->move(-1.0f, 0.0f);
		frogJump = 0;
	}
	else if (frogJump == 4){
		frog->move(1.0f, 0.0f);
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


	for (int i = 0; i < 5; i++)
	{
		if (stems[i]->isAlive())
			stems[i]->draw();

		if (turtles[i]->isAlive())
			turtles[i]->draw();

		if (trucks[i]->isAlive())
			trucks[i]->draw();

		if (cars[i]->isAlive())
			cars[i]->draw();

		if (buses[i]->isAlive())
			buses[i]->draw();
	}
}

void initObjects()
{
	margin = new Margin(vsml, &shader, 0.0f, 1.2f, 0.0f);
	margin2 = new Margin(vsml, &shader, 0.0f, 6.0f, 0.0f);
	river = new River(vsml, &shader, 0.0f, 3.6f, -0.25f);

	border = new Border(vsml, &shader, 0.0f, 0.0f, 0.0f);
	border2 = new Border(vsml, &shader, 0.0f, -6.0f, 0.0f);
	road = new Road(vsml, &shader, 0.0f, -3.0f, 0.0f);

	for (int i = 0; i < 5; i++)
	{
		buses[i] = new Bus(vsml, &shader, -11.5f, -3.6f, 1.5f);
		cars[i] = new Car(vsml, &shader, 12.2f, -2.4f, 1.1f);
		trucks[i] = new Truck(vsml, &shader, -12.0f, -1.2f, 1.4f);
		stems[i] = new Log(vsml, &shader, -12.0f, 3.6f, 0.0f);
		turtles[i] = new Turtle(vsml, &shader, 12.5f, 2.4f, 0.5f);
	}



	frog = new Frog(vsml, &shader, 0.0f, -6.0f, 1.0f);
	frogJump = 0;
	frogRot = 1;
	//frogMouseMove = 0;

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

	printf("InfoLog for shader\n%s\n\n", shader.getAllInfoLogs().c_str());

	return(shader.isProgramValid());
}


/*********************************************************/
/*                                                       */
/*                        DISPLAY                        */
/*                                                       */

void changeSize(int w, int h) {

	float ratio;
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	ratio = w * 1.0 / h;

	camera->setRatio(ratio);
	// Reset Matrix
	vsml->loadIdentity(VSMathLib::PROJECTION);
	
	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	camera->update(camState, mouseState);

}

void renderScene(void) {

	++FrameCount;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	

	//moves the frog acording to user input
	moveFrog();

	if (camState == 3 && hasFrogCamMoved){
		camera->update(camState, mouseState);
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

	if (randomValue < 20){
		for (int i = 0; i < 5; i++)
		{
			if (!turtles[i]->isAlive()){
				turtles[i]->setAlive(true);
				break;
			}
		}
	}

	if (randomValue >=20 && randomValue < 40){
		for (int i = 0; i < 5; i++)
		{
			if (!stems[i]->isAlive()){
				stems[i]->setAlive(true);
				break;
			}
		}
	}

	if (randomValue >= 40 && randomValue < 60){

		for (int i = 0; i < 5; i++)
		{
			if (!trucks[i]->isAlive()){
				trucks[i]->setAlive(true);
				break;
			}
		}
	}

	if (randomValue >= 60 && randomValue < 80){

		for (int i = 0; i < 5; i++)
		{
			if (!cars[i]->isAlive()){
				cars[i]->setAlive(true);
				break;
			}
		}
	}

	if (randomValue >= 80 && randomValue < 100){
		
		for (int i = 0; i < 5; i++)
		{
			if (!buses[i]->isAlive()){
				buses[i]->setAlive(true);
				break;
			}
		}
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
		camState = 1;
		camera->update(camState, mouseState);
		break;

	case 50:
		camState = 2;
		camera->update(camState, mouseState);
		break;

	case 51:
		camState = 3;
		camera->update(camState, mouseState);
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
			mouseState = 1;
		}
		else if (button == GLUT_RIGHT_BUTTON){
			mouseState = 2;
		}
	}


	//stop tracking the mouse
	else if (state == GLUT_UP) {
		if (mouseState == 1) {
			alpha -= (xx - startX);
			beta += (yy - startY);
		}
		else if (mouseState == 2) {

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
		

		mouseState = 0;
		camera->update(camState, mouseState);
	}
}

// Track mouse motion while buttons are pressed

void processMouseMotion(int xx, int yy)
{
	float camX, camY, camZ;
	int deltaX, deltaY;
	float alphaAux, betaAux;
	float rAux;

	deltaX = -xx + startX;
	deltaY = yy - startY;
	
	// left mouse button: move camera
	if (mouseState == 1) {


		alphaAux = alpha + deltaX;
		betaAux = beta + deltaY;

		if (betaAux > 85.0f)
			betaAux = 85.0f;
		else if (betaAux < -85.0f)
			betaAux = -85.0f;
		rAux = r;

		if (camState == 3) //camera can only be moved in 1st person
			camera->update(camState, mouseState);


		camX = rAux * sin(alphaAux * 3.14f / 180.0f) * cos(betaAux * 3.14f / 180.0f);
		camY = rAux * cos(alphaAux * 3.14f / 180.0f) * cos(betaAux * 3.14f / 180.0f);
		camZ = rAux *   						       sin(betaAux * 3.14f / 180.0f);

		camera->setAt(camX, camY, camZ);
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

	camState = 1;
	// set the camera position based on its spherical coordinates
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
	glutTimerFunc(25, collisionDetector, 0);

	initObjects();

	camera = new Camera(vsml, frog);
	//set up camera initially
	camera->update(camState, mouseState);

	glutWarpPointer(WinX / 2, WinY / 2);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}


