#pragma once
#include <GL/freeglut.h>

class Line {
private:
	float* lineVert;
	float* lineColors;
	int howManyLines;

public:
	Line();
	Line(float* lineVert, float* lineColors, int howManyLines);

	void drawLine();

	float* getLineVert();
	void setLineVert(float* LineVert);

	float* getLineColors();
	void setLineColors(float* LineColors);

	int getHowManyLines();
	void setHowManyLines(int howManyLines);
};