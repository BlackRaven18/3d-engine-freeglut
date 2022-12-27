#include "Quad.h"

Quad::Quad() {
	quadVert = nullptr;
	quadColors = nullptr;
	howManyQuads = 0;
}

Quad::Quad(float* quadVert, float* quadColors, int howManyQuads) {
	this->quadVert = quadVert;
	this->quadColors = quadColors;
	this->howManyQuads = howManyQuads;
}

void Quad::draw() {

	if (quadVert == nullptr || quadColors == nullptr || howManyQuads < 1)
		return;

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, quadVert);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, quadColors);

	glDrawArrays(GL_QUADS, 0, howManyQuads * 4);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

float* Quad::getQuadVert() {
	return quadVert;
}

void Quad::setQuadVert(float* QuadVert) {
	this->quadVert = quadVert;
}

float* Quad::getQuadColors() {
	return quadColors;
}
void Quad::setQuadColors(float* QuadColors) {
	this->quadColors = quadColors;
}

int Quad::getHowManyQuads() {
	return howManyQuads;
}
void Quad::setHowManyQuads(int howManyQuads) {
	this->howManyQuads = howManyQuads;
}