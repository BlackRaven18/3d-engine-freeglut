#pragma once
#include <GL/freeglut.h>

class Cube {
private:
	float* cubeVert;
	float* cubeNorm;
	float* cubeColors;
	unsigned int* cubeInd;

public:
	Cube();
	Cube(float* cubeVert, float* cubeNorm, float* cubeColors, unsigned int* cubeInd);

	void draw();

	float* getCubeVert();
	void setCubeVert(float* cubeVert);

	float* getCubeNorm();
	void setCubeNorm(float* cubeNorm);

	float* getCubeColors();
	void setCubeColors(float* cubeColors);

	unsigned int* getCubeInd();
	void setCubeInd(unsigned int* cubeInd);

};