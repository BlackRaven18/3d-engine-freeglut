#include "Engine.h"

const int Engine::WINDOW_WIDTH = 1280;
const int Engine::WINDOW_HEIGHT = 720;
const char* Engine::APP_TITLE = "3D Game Engine!";
 bool Engine::LIGHTNING_ENABLED = false;
const int Engine::SHADOW_ALGORYTHM = FLAT;

Engine* Engine::instance = nullptr;
float Engine::currentTime = 0;
float Engine::prevTime = 0;
float Engine::deltaTime = 0;
float Engine::deltaX = 0;
float Engine::deltaY = 0;

Camera Engine::camera;
PresentationClass Engine::presentationClass;


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


void Engine::turnOnOffTheLight() {
	if (LIGHTNING_ENABLED) {
		std::cout << "Light turned on!" << std::endl << std::endl;
		// Zdefiniowanie materia³u obiektu
		GLfloat mat_specular[] = { 0.8, 0.8, 0.8, 1.0 };
		GLfloat mat_shininess[] = { 50.0 };
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		GLfloat light_position[] = { 105.0, 0.0, -2.0, 0.0 };
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);

		// W³¹czenie oœwietlenia
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_COLOR_MATERIAL);
	}
	else {
		std::cout << "Light turned off!" << std::endl << std::endl;
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
		glDisable(GL_COLOR_MATERIAL);
	}
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
	glutMouseFunc(mouse);

	Engine::camera.setPerspective(45.0f, (float)(WINDOW_WIDTH / WINDOW_HEIGHT), 130, 470);
	Engine::camera.setPosition(0, 0, -8);
	Engine::camera.setUpDownAngle(0);
	Engine::camera.setLeftRightAngle(0);

	if (LIGHTNING_ENABLED) {
		// Zdefiniowanie materia³u obiektu
		GLfloat mat_specular[] = {0.8, 0.8, 0.8, 1.0 };
		GLfloat mat_shininess[] = { 50.0 };
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		GLfloat light_position[] = { 105.0, 0.0, -2.0, 0.0 };
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);

		// W³¹czenie oœwietlenia
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_COLOR_MATERIAL);

	}

	switch (SHADOW_ALGORYTHM) {
	case SMOOTH:
		glShadeModel(GL_SMOOTH);
		break;
	case FLAT:
		glShadeModel(GL_FLAT);
		break;
	default:
		break;
	}
	
	BitmapHandler bh;
	if (bh.loadTexture("sample_texture.jpg") == -1) {
		exit(0);
	}


	// W³¹czenie teksturowania
	glEnable(GL_TEXTURE_2D);

}

void Engine::start() {
	glutMainLoop();
}


void Engine::update(void) {
	glLoadIdentity();
}


void Engine::display(void) {
	currentTime = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = currentTime - prevTime;
	prevTime = currentTime;

	glClear(GL_COLOR_BUFFER_BIT);

	
	glm::mat4 m1 = camera.getMainMatrix();
	glLoadMatrixf(glm::value_ptr(m1));
	presentationClass.run();
	

	glutSwapBuffers();
}



void Engine::changeSize(int w, int h) {

	if (h == 0)
		h = 1;

	float ratio = w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);
	//gluPerspective(45, w / h, 0.1, 100);
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
	case 'l':
		LIGHTNING_ENABLED = !LIGHTNING_ENABLED;
		turnOnOffTheLight();
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

void Engine::mouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			// kod wykonywany gdy przycisk lewy jest wciœniêty
		}
		else
		{
			presentationClass.changeToNextMode();
			// kod wykonywany gdy przycisk lewy jest zwolniony
		}
	}
}