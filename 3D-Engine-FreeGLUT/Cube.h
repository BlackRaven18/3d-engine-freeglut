#pragma once
#include <GL/freeglut.h>
#include <glm.hpp>
#include "DrawableObject.h"
#include "TransformableObject.h"

class Cube: public virtual DrawableObject, public virtual TransformableObject{
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