#include "Triangle.h"

Triangle::Triangle() {
	triangleVert = nullptr;
	triangleColors = nullptr;
	triangleTextCord = nullptr;
	howManyTriangles = 0;
}

Triangle::Triangle(float* triangleVert, float* triangleColors, int howManyTriangles) {
	this->triangleVert = triangleVert;
	this->triangleColors = triangleColors;
	this->triangleTextCord = nullptr;
	this->howManyTriangles = howManyTriangles;
}

Triangle::Triangle(float* triangleVert, float* triangleColors, float* triangleTextCord, int howManyTriangles) {
	this->triangleVert = triangleVert;
	this->triangleColors = triangleColors;
	this->triangleTextCord = triangleTextCord;
	this->howManyTriangles = howManyTriangles;
}

void Triangle::draw() {

	if (triangleVert == nullptr || triangleColors == nullptr || howManyTriangles < 1)
		return;

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, triangleVert);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, triangleColors);

	glDrawArrays(GL_TRIANGLES, 0, howManyTriangles * 3);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Triangle::drawTextured(){
	if (triangleVert == nullptr || triangleColors == nullptr || triangleTextCord == nullptr || howManyTriangles < 1)
		return;

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, triangleVert);

	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, triangleTextCord);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, triangleColors);

	glDrawArrays(GL_TRIANGLES, 0, howManyTriangles * 3);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

float* Triangle::getTriangleVert() {
	return triangleVert;
}

void Triangle::setTriangleVert(float* TriangleVert) {
	this->triangleVert = triangleVert;
}

float* Triangle::getTriangleColors() {
	return triangleColors;
}
void Triangle::setTriangleColors(float* TriangleColors) {
	this->triangleColors = triangleColors;
}

int Triangle::getHowManyTriangles() {
	return howManyTriangles;
}
void Triangle::setHowManyTriangles(int howManyTriangles) {
	this->howManyTriangles = howManyTriangles;
}