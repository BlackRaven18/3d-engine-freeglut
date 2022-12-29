#pragma once
#include <GL/freeglut.h>
#include "DrawableObject.h"
#include "TexturableObject.h"

class Triangle : public virtual DrawableObject, public virtual TexturableObject {
private:
	float* triangleVert;
	float* triangleColors;
	float* triangleTextCord;
	int howManyTriangles;

public:
	Triangle();
	Triangle(float* triangleVert, float* triangleColors, int howManyTriangles);
	Triangle(float* triangleVert, float* triangleColors, float* triangleTextCord, int howManyTriangles);

	void draw();
	void drawTextured();

	float* getTriangleVert();
	void setTriangleVert(float* TriangleVert);

	float* getTriangleColors();
	void setTriangleColors(float* TriangleColors);

	int getHowManyTriangles();
	void setHowManyTriangles(int howManyTriangles);
};