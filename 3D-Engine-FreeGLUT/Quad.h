#pragma once
#include <GL/freeglut.h>
#include "DrawableObject.h"
#include "TexturableObject.h"

class Quad : public virtual DrawableObject, public virtual TexturableObject {
private:
	float* quadVert;
	float* quadColors;
	float* quadTextCord;
	int howManyQuads;

public:
	Quad();
	Quad(float* quadVert, float* quadColors, int howManyQuads);
	Quad(float* quadVert, float* quadColors,float* quadTextCord, int howManyQuads);

	void draw();
	void drawTextured();

	float* getQuadVert();
	void setQuadVert(float* QuadVert);

	float* getQuadColors();
	void setQuadColors(float* QuadColors);

	int getHowManyQuads();
	void setHowManyQuads(int howManyQuads);
};