#pragma once
#include <GL/freeglut.h>
#include <GL/GL.h>

class EasyFreeGLUTShapesDrawer {
public:

	void drawWireSphere(double dRadius, GLint slices, GLint stacks);
	void drawSolidSphere(double dRadius, GLint slices, GLint stacks);

	void drawWireTorus(double dInnerRadius, double dOuterRadius, GLint nSides, GLint nRings);
	void drawSolidTorus(double dInnerRadius, double dOuterRadius, GLint nSides, GLint nRings);

	void drawWireCylinder(double base, double height, GLint slices, GLint stacks);
	void drawSolidCylinder(double base, double height, GLint slices, GLint stacks);

	void drawWireCube(double dSize);
	void drawSolidCube(double dSize);

	void drawWireTeapot(double dSize);
	void drawSolidTeapot(double dSize);
	void drawWireTeacup(double dSize);
	void drawSolidTeacup(double dSize);
	void drawWireTeaspoon(double dSize);
	void drawSolidTeaspoon(double dSize);
};