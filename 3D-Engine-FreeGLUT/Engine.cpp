#include "Engine.h"

const int Engine::WINDOW_WIDTH = 1280;
const int Engine::WINDOW_HEIGHT = 720;
const char* Engine::APP_TITLE = "3D Game Engine!";

Engine* Engine::instance = nullptr;
float Engine::currentTime = 0;
float Engine::prevTime = 0;
float Engine::deltaTime = 0;



Engine::Engine() {
}

Engine::~Engine() {
}



Engine* Engine::getInstance() {
	if (instance == nullptr) {
		instance = new Engine();
	}
	return instance;
}


void Engine::init(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(glutGet(GLUT_SCREEN_WIDTH)/ 2 - WINDOW_WIDTH / 2, glutGet(GLUT_SCREEN_HEIGHT)/ 2 - WINDOW_HEIGHT / 2);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow(APP_TITLE);

	glutIdleFunc(update);
	glutDisplayFunc(display);
	glutReshapeFunc(changeSize);
	glutKeyboardFunc(keyboard);


}

void Engine::start() {
	glutMainLoop();
}


void Engine::update(void) {
	glLoadIdentity();

	/*gluLookAt(2.0f, 1.0f, z - 3,
		x + 1.5 + lx, 1.0f, z - 3 + lz,
		0.0f, 1.0f, 0.0f);*/
}

float lineVert[12] = {
	-2, 0, 0,
	0, 2, 0,
	2, 0, 0,
	0, 2, 0
};

float lineCols[12] = {
	1, 0, 0,
	0, 1, 0,
	1, 0, 0,
	0, 0, 1
};

float pointVert[6] = {
	1, 0, 0,
	0, 1, 0
};

float pointColors[6]{
	0, 1, 0,
	0, 1, 0
};

void Engine::display(void) {
	currentTime = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = currentTime - prevTime;
	prevTime = currentTime;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -8);

	Line line(lineVert,lineCols, 2);
	line.draw();

	Point point(pointVert, pointColors, 2);
	point.draw();

	/*glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, lineVert);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, lineCols);

	glDrawArrays(GL_LINES, 0, 2);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);*/

	//EasyFreeGLUTShapesDrawer shapesDrawer;
	//glColor3f(1, 0, 0);
	//glColor3f(0, 1, 0);
	//shapesDrawer.drawWireTeapot(4);
	//shapesDrawer.drawSolidSphere(2, 10, 10);

	/*glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex3f(0, 1, 0);

	glColor3f(0, 1, 0);
	glVertex3f(-1, 0, 0);

	glColor3f(0, 0, 1);
	glVertex3f(1, 0, 0);
	glEnd();
	glFlush();*/

	glutSwapBuffers();
}



void Engine::changeSize(int w, int h) {

	if (h == 0)
		h = 1;

	float ratio = w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
}

void Engine::keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 27: // kod klawisza Esc
		exit(0);
		break;
	default:
		break;
	}
}