#include <GL/freeglut.h>
#include <cmath>
#include <iostream>

#define M_PI 3.14159265358979323846264338327950288

#define GLUT_KEY_ESCAPE 27
#define DEG2RAD(a) (a * M_PI / 180.0)

void initialize();
void resize(int width, int height);
void display();
void keyboard(unsigned char key, int x, int y);

void releaseKey(unsigned char key, int x, int y);
void changeSize(int w, int h);
void renderScene(void);

int window; 
float angle = 0.0f;
float lx = 0.0f, lz = -1.0f;
float x = 0.0f, z = 5.0f;

float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin = -1;

void drawCube()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    glBegin(GL_QUADS);
    // Front face
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);

    // Back face
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);

    // Right face
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);

    // Left face
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);

    // Top face
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);

    // Bottom face
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glEnd();
}

void drawSnowMan() {
    glColor3f(1.0f, 1.0f, 1.0f);

    glTranslatef(0.0f, 0.75f, 0.0f);
    glutSolidSphere(0.75f, 20, 20);

    glTranslatef(0.0f, 1.0f, 0.0f);
    glutSolidSphere(0.25f, 20, 20);

    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.05f, 0.10f, 0.18f);
    glutSolidSphere(0.05f, 10, 10);
    glTranslatef(-0.1f, 0.0f, 0.0f);
    glutSolidSphere(0.05f, 10, 10);
    glPopMatrix();

    glColor3f(1.0f, 0.5f, 0.5f);
    glRotatef(0.0f, 1.0f, 0.0f, 0.0f);
    glutSolidCone(0.08f, 0.5f, 10, 2);
}

void mouseMove(int x, int y) {
    if (xOrigin >= 0) {

        deltaAngle = (x - xOrigin) * 0.001f;

        lx = sin(angle + deltaAngle);
        lz = -cos(angle + deltaAngle);
    }
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {

        if (state == GLUT_UP) {
            angle += deltaAngle;
            xOrigin = -1;
        }
        else {
            xOrigin = x;
        }
    }
}

void pressKey(int key, int xx, int yy) {

    switch (key) {
    case GLUT_KEY_LEFT: deltaAngle = -0.01f; break;
    case GLUT_KEY_RIGHT: deltaAngle = 0.01f; break;
    case GLUT_KEY_UP: deltaMove = 0.5f; break;
    case GLUT_KEY_DOWN: deltaMove = -0.5f; break;
    }
}





int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(320, 320);
    window = glutCreateWindow("Lighthouse3D - GLUT Tutorial");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);

    glutIgnoreKeyRepeat(1);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(pressKey);

    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutKeyboardUpFunc(releaseKey);

    glutMainLoop();

    return 1;

	/*glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Open gl!");

	initialize();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(releaseKey);
	glutReshapeFunc(resize);


	glutMainLoop();*/
}

void initialize() {
	glClearColor(0, 0, 0, 1);
}

void resize(int width, int height) {
	if (height == 0)
		height = 1;
	if (width == 0)
		width = 1;

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45, (float)width / (float)height, 0.1, 100);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glTranslatef(0, 0, -10);
	//glRotatef(30.0, 1, 0, 0.0);
	//drawCube();

    drawSnowMan();
	//glutWireCube(2);
	//glutWireCylinder(2, 5, 4, 5);

	/*glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -3);

	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex3f(0, 1, 0);

	glColor3f(0, 1, 0);
	glVertex3f(-1, 0, 0);

	glColor3f(0, 0, 1);
	glVertex3f(1, 0, 0);

	glEnd();*/
	glFlush();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
    case 27: glutLeaveMainLoop(); break;
 
	default:
		break;
	}
}

void releaseKey(unsigned char key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
    case GLUT_KEY_RIGHT: deltaAngle = 0.0f; break;
    case GLUT_KEY_UP:
    case GLUT_KEY_DOWN: deltaMove = 0; break;
    }
}

void changeSize(int w, int h) {

    if (h == 0)
        h = 1;

    float ratio = w * 1.0 / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w, h);

    gluPerspective(45.0f, ratio, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
}


void renderScene(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(2.0f, 1.0f, z - 3,
        x + 1.5 + lx, 1.0f, z - 3 + lz,
        0.0f, 1.0f, 0.0f);

    drawSnowMan();

    glutSwapBuffers();
}


