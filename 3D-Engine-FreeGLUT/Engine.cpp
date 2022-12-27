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

float segVert[12] = {
	-2, 0, 0,
	0, 2, 0,
	2, 0, 0,
	0, 2, 0
};

float segCols[12] = {
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

float lineVert[9] = {
	0, 0, 0,
	2, 0, 0,
	1, -1, 0
};

float lineCols[9] = {
	1, 0, 0,
	1, 0, 0,
	1, 0, 0
};

float triangleVert[18] = {
	-2, 0, 0,
	2, 0, 0,
	0, 4, 0,
	-2, 0, 0,
	2, 0, 0,
	0, -4, 0
};

float triangleColors[18] = {
	1, 0, 0,
	1, 0, 0,
	1, 0, 0,
	0, 1, 0,
	0, 1, 0,
	0, 1, 0
};

float triangleStripVert[15] = {
	-1, 1, 0,
	0, 0, 0,
	1, 1, 0,
	1, -1, 0,
	2, 1, 0
};

float triangleStripColors[15] = {
	1, 0, 0,
	1, 0, 0,
	1, 0, 0,
	1, 0, 0,
	1, 0, 0
};

float triangleFanVerts[12] = {
	0, 0, 0,
	-1, 0, 0,
	-1, 1, 0,
	0, 1, 0
};

float triangleFanColors[12] = {
	1, 1, 0,
	1, 1, 0,
	1, 1, 0,
	1, 1, 0,
};

float quadVerts[12] = {
	-1, 0, 0,
	-1, 1, 0,
	1, 1, 0,
	1, 0, 0
};

float QuadColors[12] = {
	1, 1, 0,
	1, 1, 0,
	1, 1, 0,
	1, 1, 0,
};

//float cubeVert[18] = {
//	-1, -1, 1,
//	1, -1, 1,
//	-1, 1, 1,
//	1, 1, 1,
//	-1, -1, -1, 
//	-1, 1, -1
//};
//
float cubeNorm[] = {
	0, 0, 1,
	0, 0, 1,
	0, 0, 1,
	0, 0, 1,
	0, 0, -1,
	0, 0, -1,
	0, 0, -1,
	0, 0, -1,
};
//
//float cube_colors[18] = {
//	1, 0.3, 0.3,
//	1, 0.3, 0.3,
//	1, 1, 0.3,
//	1, 0.3, 0.3,
//	1, 0.3, 0.3,
//	1, 1, 0.3,
//};
//
unsigned char cubeInd[] = {
	0, 1, 2,
	2, 1, 3,
	4, 5, 6,
	6, 5, 7,
	8, 9, 10,
	10, 9, 11,
	12, 13, 14,
	14, 13, 15,
	16, 17, 18,
	18, 17, 19,
	20, 21, 22,
	22, 21, 23
};

float cubeVert[] = {
	-1.0, -1.0,  1.0,
	 1.0, -1.0,  1.0,
	 1.0,  1.0,  1.0,
	-1.0,  1.0,  1.0,
	-1.0, -1.0, -1.0,
	 1.0, -1.0, -1.0,
	 1.0,  1.0, -1.0,
	-1.0,  1.0, -1.0
};

//unsigned char cubeInd[] = {
//	0, 1, 2, 3,
//	4, 5, 6, 7,
//	0, 3, 7, 4,
//	1, 5, 6, 2,
//	0, 4, 5, 1,
//	3, 2, 6, 7
//};

float cubeColors[] = {
	1, 0.3, 0.3,
	1, 0.3, 0.3,
	1, 0.3, 0.3,
	1, 1, 0.3,
	1, 1, 0.3,
	1, 1, 0.3,
	1, 1, 1,
	1, 1, 1,
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

	Segment segment(segVert,segCols, 2);
	//segment.draw();

	Point point(pointVert, pointColors, 2);
	//point.draw();

	Line line(CLOSED, lineVert, lineCols, 3);
	//line.draw();

	Triangle triangle(triangleVert, triangleColors, 2);
	//triangle.draw();

	TriangleStrip ts(triangleStripVert, triangleStripColors, 5);
	//ts.draw();

	TriangleFan tf(triangleFanVerts, triangleFanColors, 4);
	//tf.draw();

	Quad q(quadVerts, QuadColors, 1);
	//q.draw();

	Cube cube(cubeVert, cubeNorm, cubeColors, cubeInd);
	cube.draw();

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