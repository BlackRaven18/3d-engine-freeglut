#pragma once
#include <GL/freeglut.h>

class Cube {
private:
	float* cubeVert;
	float* cubeNorm;
	float* cubeColors;
	unsigned char* cubeInd;

public:
	Cube();
	Cube(float* cubeVert, float* cubeNorm, float* cubeColors, unsigned char* cubeInd);

	void draw();

	float* getCubeVert();
	void setCubeVert(float* cubeVert);

	float* getCubeNorm();
	void setCubeNorm(float* cubeNorm);

	float* getCubeColors();
	void setCubeColors(float* cubeColors);

	unsigned char* getCubeInd();
	void setCubeInd(unsigned char* cubeInd);

};