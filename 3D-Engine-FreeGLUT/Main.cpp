#include "Engine.h"

//void drawCube()
//{
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//    glBegin(GL_QUADS);
//    // Front face
//    glColor3f(1.0, 0.0, 0.0);
//    glVertex3f(-1.0, -1.0, 1.0);
//    glVertex3f(1.0, -1.0, 1.0);
//    glVertex3f(1.0, 1.0, 1.0);
//    glVertex3f(-1.0, 1.0, 1.0);
//
//    // Back face
//    glColor3f(0.0, 1.0, 0.0);
//    glVertex3f(-1.0, -1.0, -1.0);
//    glVertex3f(-1.0, 1.0, -1.0);
//    glVertex3f(1.0, 1.0, -1.0);
//    glVertex3f(1.0, -1.0, -1.0);
//
//    // Right face
//    glColor3f(0.0, 0.0, 1.0);
//    glVertex3f(1.0, -1.0, -1.0);
//    glVertex3f(1.0, 1.0, -1.0);
//    glVertex3f(1.0, 1.0, 1.0);
//    glVertex3f(1.0, -1.0, 1.0);
//
//    // Left face
//    glColor3f(1.0, 1.0, 0.0);
//    glVertex3f(-1.0, -1.0, -1.0);
//    glVertex3f(-1.0, -1.0, 1.0);
//    glVertex3f(-1.0, 1.0, 1.0);
//    glVertex3f(-1.0, 1.0, -1.0);
//
//    // Top face
//    glColor3f(1.0, 0.0, 1.0);
//    glVertex3f(-1.0, 1.0, 1.0);
//    glVertex3f(1.0, 1.0, 1.0);
//    glVertex3f(1.0, 1.0, -1.0);
//    glVertex3f(-1.0, 1.0, -1.0);
//
//    // Bottom face
//    glColor3f(0.0, 1.0, 1.0);
//    glVertex3f(-1.0, -1.0, -1.0);
//    glVertex3f(1.0, -1.0, -1.0);
//    glVertex3f(1.0, -1.0, 1.0);
//    glVertex3f(-1.0, -1.0, 1.0);
//    glEnd();
//}
//
//void drawSnowMan() {
//    glColor3f(1.0f, 1.0f, 1.0f);
//
//    glTranslatef(0.0f, 0.75f, 0.0f);
//    glutSolidSphere(0.75f, 20, 20);
//
//    glTranslatef(0.0f, 1.0f, 0.0f);
//    glutSolidSphere(0.25f, 20, 20);
//
//    glPushMatrix();
//    glColor3f(0.0f, 0.0f, 0.0f);
//    glTranslatef(0.05f, 0.10f, 0.18f);
//    glutSolidSphere(0.05f, 10, 10);
//    glTranslatef(-0.1f, 0.0f, 0.0f);
//    glutSolidSphere(0.05f, 10, 10);
//    glPopMatrix();
//
//    glColor3f(1.0f, 0.5f, 0.5f);
//    glRotatef(0.0f, 1.0f, 0.0f, 0.0f);
//    glutSolidCone(0.08f, 0.5f, 10, 2);
//}





int main(int argc, char** argv) {

	Engine* engine = Engine::getInstance();
	engine->init(argc, argv);
	engine->start();

    return 1;


}



