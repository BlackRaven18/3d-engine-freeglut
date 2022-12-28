#include "Engine.h"

const int Engine::WINDOW_WIDTH = 1280;
const int Engine::WINDOW_HEIGHT = 720;
const char* Engine::APP_TITLE = "3D Game Engine!";
const bool Engine::LIGHTNING_ENABLED = true;

Engine* Engine::instance = nullptr;
float Engine::currentTime = 0;
float Engine::prevTime = 0;
float Engine::deltaTime = 0;
float Engine::deltaX = 0;
float Engine::deltaY = 0;

Camera Engine::camera;





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
	glutSpecialFunc(specialKeysHandler);

	Engine::camera.setPerspective(45.0f, (float)(WINDOW_WIDTH / WINDOW_HEIGHT), 130, 470);
	Engine::camera.setPosition(0, 0, -8);
	Engine::camera.setUpDownAngle(0);
	Engine::camera.setLeftRightAngle(120);

	if (LIGHTNING_ENABLED) {
		// Zdefiniowanie materia³u obiektu
		GLfloat mat_specular[] = {0.8, 0.8, 0.8, 1.0 };
		GLfloat mat_shininess[] = { 50.0 };
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		GLfloat light_position[] = { 100.0, 1.0, 1.0, 0.0 };
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);

		// W³¹czenie oœwietlenia
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_COLOR_MATERIAL);

	}

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
//unsigned int cubeInd[] = {
//	0, 1, 2,
//	2, 1, 3,
//	4, 5, 6,
//	6, 5, 7,
//	8, 9, 10,
//	10, 9, 11,
//	12, 13, 14,
//	14, 13, 15,
//	16, 17, 18,
//	18, 17, 19,
//	20, 21, 22,
//	22, 21, 23
//};

//float cubeVert[] = {
//	-1.0, -1.0,  1.0,
//	 1.0, -1.0,  1.0,
//	-1.0,  1.0,  1.0,
//	 1.0,  1.0,  1.0,
//	-1.0, -1.0, -1.0,
//	 -1.0, 1.0, -1.0,
//	 1.0,  1.0, 1.0,
//	-1.0,  1.0, -1.0
//};
//
//unsigned int cubeInd[] = {
//	0, 1, 2, 3, // Przód
//	4, 5, 6, 7, // Ty³
//	0, 4, 7, 3, // Lewa strona
//	1, 5, 6, 2, // Prawa strona
//	2, 6, 7, 3, // Górna strona
//	0, 1, 5, 4  // Doln¹ strona
//};
//
float cubeColors[] = {
	1, 0, 0,
	1, 0, 0,
	1, 0, 0,
	1, 0, 0,
	1, 0, 0,
	1, 0, 0,
	1, 0, 0,
	1, 0, 0,
};

float cubeVert[] = {

	0, 0, 0,
	2, 0, 0,
	2, 2, 0,
	0, 2, 0,

	0, 0, 2,
	2, 0, 2,
	2, 2, 2,
	0, 2, 2

};



unsigned int cubeInd[] = {
		// przednia œciana
		0, 1, 2, 3,
		// lewa œciana
		0, 3, 7, 4,
		// prawa œciana
		1, 2, 6, 5,
		// tylna œciana
		4, 5, 6, 7,
		// górna œciana
		0, 1, 5, 4,
		// dolna œciana
		7, 6, 3, 2
};





void Engine::display(void) {
	currentTime = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = currentTime - prevTime;
	prevTime = currentTime;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);

	// Ustawienie rzutowania perspektywicznego.
	//glm::perspective<float>(glm::radians(60.0f), (float)WINDOW_WIDTH / WINDOW_HEIGHT, 130, 470);
	//Odsuniêcie œrodka sceny od kamery:
	//glm::mat4 MatM = glm::translate(glm::vec3(0 + deltaX, 0, -30));
	// K¹t patrzenia (góra/dó³):
	//MatM = glm::rotate(MatM, glm::radians(0.0f), glm::vec3(1, 0, 0));
	// Animacja (lewo/prawo):
	//MatM = glm::rotate(MatM, glm::radians(120.0f), glm::vec3(0, 1, 0));

	// Rotacja o~120 stopni wokó³ osi Y:
	//glm::mat4 MatRot120 = glm::rotate(glm::radians(120.0f), glm::vec3(0, 1, 0));
	//// Translacja +100 na osi X:
	//glm::mat4 MatTra100 = glm::translate(glm::vec3(100, 0, 0));

	Cube cube(cubeVert, cubeNorm, cubeColors, cubeInd);
	glm::mat4 m1 = camera.getMainMatrix();
	glLoadMatrixf(glm::value_ptr(m1));
	//glTranslatef(1, -1, -2); 
	cube.translate(1, -1, -2);
	cube.rotate(130, 1, 1, 0);
	cube.scale(2, 2, 1);
	cube.draw();
	 
	//Trzy obiekty kr¹¿¹ce wokó³ punktu centralnego:
	//glm::mat4 m1 = camera.getMainMatrix() *MatTra100;
	//glLoadMatrixf(glm::value_ptr(m1));
	//glColor3f(0, 1, 0); glTranslatef(-100, 0,2); cube.draw();//glutSolidCube(50); // Zielony szeœcian
	//glm::mat4 m2 = camera.getMainMatrix() * MatRot120 * MatTra100;
	//glLoadMatrixf(glm::value_ptr(m2));
	//glColor3f(1, 1, 0); glutSolidTeapot(40); // ¯ó³ty czajnik
	//glm::mat4 m3 = camera.getMainMatrix() * MatRot120 * MatRot120 * MatTra100;
	//glLoadMatrixf(glm::value_ptr(m3));
	//glColor3f(0, 0, 1); glutSolidSphere(50, 10, 10); // Niebieska sfera


	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//glTranslatef(0, 0, -8);



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

	//Cube cube(cubeVert, cubeNorm, cubeColors, cubeInd);
	//cube.draw();

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

	//gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	Engine::camera.setPerspective(60.0f, ratio, 0.1f, 100);

	glMatrixMode(GL_MODELVIEW);
}

void Engine::keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 27: // kod klawisza Esc
		exit(0);
		break;
	case 'w':
		camera.moveForward(5);
		break;
	case 's':
		camera.moveBackward(5);
		break;
	case 'a':
		camera.moveLeft(5);
		break;
	case 'd':
		camera.moveRight(5);
		break;
	default:
		break;
	}

	glutPostRedisplay();
}

void Engine::specialKeysHandler(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		camera.moveUp(5);
		break;
	case GLUT_KEY_DOWN:
		camera.moveDown(5);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}