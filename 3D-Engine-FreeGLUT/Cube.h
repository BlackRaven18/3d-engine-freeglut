#pragma once
#include <GL/freeglut.h>
#include <glm.hpp>
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "TexturableObject.h"

class Cube: public virtual DrawableObject, public virtual TransformableObject, public virtual TexturableObject{
private:
	float* cubeVert;
	float* cubeNorm;
	float* cubeColors;
	unsigned int* cubeInd;
	float* cubeTextCord;


public:
	Cube();
	Cube(float* cubeVert, float* cubeNorm, float* cubeColors, unsigned int* cubeInd);
	Cube(float* cubeVert, float* cubeNorm, float* cubeColors, unsigned int* cubeInd, float* cubeTextCord);

	void draw();
	void drawTextured();
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