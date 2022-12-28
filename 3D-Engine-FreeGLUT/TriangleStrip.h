#pragma once
#include <GL/freeglut.h>
#include "DrawableObject.h"

class TriangleStrip: public virtual DrawableObject {
private:
	float* trianglesVert;
	float* trianglesColors;
	int howManyPoints;

public:
	TriangleStrip();
	TriangleStrip(float* trianglesVert, float* trianglesColors, int howManyPoints);

	void draw();

	float* getTriangleVert();
	void setTriangleVert(float* triangleVert);

	float* getTriangleColors();
	void setTriangleColors(float* triangleColors);

	int getHowManyTriangles();
	void setHowManyTriangles(int howManyPoints);
};