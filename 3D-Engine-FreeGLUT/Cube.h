#pragma once
#include <GL/freeglut.h>
#include <glm.hpp>

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
	void translate(float x, float y, float z);
	void rotate(float angle, float x, float y, float z);
	void scale(float x, float y, float z);

	float* getCubeVert();
	void setCubeVert(float* cubeVert);

	float* getCubeNorm();
	void setCubeNorm(float* cubeNorm);

	float* getCubeColors();
	void setCubeColors(float* cubeColors);

	unsigned int* getCubeInd();
	void setCubeInd(unsigned int* cubeInd);

};