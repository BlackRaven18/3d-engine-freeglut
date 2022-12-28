#pragma once
#include <GL/freeglut.h>
#include "DrawableObject.h"

class Quad : public virtual DrawableObject {
private:
	float* quadVert;
	float* quadColors;
	int howManyQuads;

public:
	Quad();
	Quad(float* quadVert, float* quadColors, int howManyQuads);

	void draw();

	float* getQuadVert();
	void setQuadVert(float* QuadVert);

	float* getQuadColors();
	void setQuadColors(float* QuadColors);

	int getHowManyQuads();
	void setHowManyQuads(int howManyQuads);
};