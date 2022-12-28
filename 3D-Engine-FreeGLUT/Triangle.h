#pragma once
#include <GL/freeglut.h>
#include "DrawableObject.h"

class Triangle : public virtual DrawableObject {
private:
	float* triangleVert;
	float* triangleColors;
	int howManyTriangles;

public:
	Triangle();
	Triangle(float* triangleVert, float* triangleColors, int howManyTriangles);

	void draw();

	float* getTriangleVert();
	void setTriangleVert(float* TriangleVert);

	float* getTriangleColors();
	void setTriangleColors(float* TriangleColors);

	int getHowManyTriangles();
	void setHowManyTriangles(int howManyTriangles);
};