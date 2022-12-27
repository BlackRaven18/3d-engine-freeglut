#pragma once
#include <GL/freeglut.h>

class TriangleFan {
private:
	float* trianglesVert;
	float* trianglesColors;
	int howManyPoints;

public:
	TriangleFan();
	TriangleFan(float* trianglesVert, float* trianglesColors, int howManyPoints);

	void draw();

	float* getTriangleVert();
	void setTriangleVert(float* triangleVert);

	float* getTriangleColors();
	void setTriangleColors(float* triangleColors);

	int getHowManyTriangles();
	void setHowManyTriangles(int howManyPoints);
};