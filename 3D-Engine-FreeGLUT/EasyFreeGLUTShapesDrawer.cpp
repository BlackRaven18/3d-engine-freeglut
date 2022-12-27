#include "EasyFreeGLUTShapesDrawer.h"

void EasyFreeGLUTShapesDrawer::drawWireSphere(double dRadius, GLint slices, GLint stacks) {
	glutWireSphere(dRadius, slices, stacks);
}

void EasyFreeGLUTShapesDrawer::drawSolidSphere(double dRadius, GLint slices, GLint stacks) {
	glutSolidSphere(dRadius, slices, stacks);
}


void EasyFreeGLUTShapesDrawer::drawWireTorus(double dInnerRadius, double dOuterRadius, GLint nSides, GLint nRings) {
	glutWireTorus(dInnerRadius, dOuterRadius, nSides, nRings);
}
void EasyFreeGLUTShapesDrawer::drawSolidTorus(double dInnerRadius, double dOuterRadius, GLint nSides, GLint nRings) {
	glutSolidTorus(dInnerRadius, dOuterRadius, nSides, nRings);
}

void EasyFreeGLUTShapesDrawer::drawWireCylinder(double base, double height, GLint slices, GLint stacks) {
	glutWireCylinder(base, height, slices, stacks);
}
void EasyFreeGLUTShapesDrawer::drawSolidCylinder(double base, double height, GLint slices, GLint stacks) {
	glutSolidCylinder(base, height, slices, stacks);
}

void EasyFreeGLUTShapesDrawer::drawWireCube(double dSize) {
	glutWireCube(dSize);
}
void EasyFreeGLUTShapesDrawer::drawSolidCube(double dSize) {
	glutSolidCube(dSize);
}

void EasyFreeGLUTShapesDrawer::drawWireTeapot(double dSize) {
	glutWireTeapot(dSize);
}
void EasyFreeGLUTShapesDrawer::drawSolidTeapot(double dSize) {
	glutSolidTeacup(dSize);
}
void EasyFreeGLUTShapesDrawer::drawWireTeacup(double dSize) {
	glutWireTeacup(dSize);
}
void EasyFreeGLUTShapesDrawer::drawSolidTeacup(double dSize) {
	glutSolidTeacup(dSize);
}
void EasyFreeGLUTShapesDrawer::drawWireTeaspoon(double dSize) {
	glutWireTeaspoon(dSize);
}
void EasyFreeGLUTShapesDrawer::drawSolidTeaspoon(double dSize) {
	glutSolidTeaspoon(dSize);
}