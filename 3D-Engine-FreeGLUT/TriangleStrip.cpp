#include "TriangleStrip.h"

TriangleStrip::TriangleStrip() {
	trianglesVert = nullptr;
	trianglesColors = nullptr;
	howManyPoints = 0;
}

TriangleStrip::TriangleStrip(float* trianglesVert, float* trianglesColors, int howManyPoints) {
	this->trianglesVert = trianglesVert;
	this->trianglesColors = trianglesColors;
	this->howManyPoints = howManyPoints;
}

void TriangleStrip::draw() {

	if (trianglesVert == nullptr || trianglesColors == nullptr || howManyPoints < 1)
		return;

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, trianglesVert);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, trianglesColors);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, howManyPoints);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

float* TriangleStrip::getTriangleVert() {
	return trianglesVert;
}

void TriangleStrip::setTriangleVert(float* TriangleVert) {
	this->trianglesVert = trianglesVert;
}

float* TriangleStrip::getTriangleColors() {
	return trianglesColors;
}
void TriangleStrip::setTriangleColors(float* TriangleColors) {
	this->trianglesColors = trianglesColors;
}

int TriangleStrip::getHowManyTriangles() {
	return howManyPoints;
}
void TriangleStrip::setHowManyTriangles(int howManyPoints) {
	this->howManyPoints = howManyPoints;
}