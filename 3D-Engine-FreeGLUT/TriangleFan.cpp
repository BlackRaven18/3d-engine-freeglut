#include "TriangleFan.h"

TriangleFan::TriangleFan() {
	trianglesVert = nullptr;
	trianglesColors = nullptr;
	howManyPoints = 0;
}

TriangleFan::TriangleFan(float* trianglesVert, float* trianglesColors, int howManyPoints) {
	this->trianglesVert = trianglesVert;
	this->trianglesColors = trianglesColors;
	this->howManyPoints = howManyPoints;
}

void TriangleFan::draw() {

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

float* TriangleFan::getTriangleVert() {
	return trianglesVert;
}

void TriangleFan::setTriangleVert(float* TriangleVert) {
	this->trianglesVert = trianglesVert;
}

float* TriangleFan::getTriangleColors() {
	return trianglesColors;
}
void TriangleFan::setTriangleColors(float* TriangleColors) {
	this->trianglesColors = trianglesColors;
}

int TriangleFan::getHowManyTriangles() {
	return howManyPoints;
}
void TriangleFan::setHowManyTriangles(int howManyPoints) {
	this->howManyPoints = howManyPoints;
}