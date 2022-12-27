#include "Point.h"

Point::Point() {
	pointVert = nullptr;
	pointColors = nullptr;
	howManyPoints = 0;
}

Point::Point(float* pointVert, float* pointColors, int howManyPoints) {
	this->pointVert = pointVert;
	this->pointColors = pointColors;
	this->howManyPoints = howManyPoints;
}

void Point::draw() {

	if (pointVert == nullptr || pointColors == nullptr || howManyPoints < 1)
		return;

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, pointVert);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, pointColors);

	glDrawArrays(GL_POINTS, 0, howManyPoints);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

float* Point::getPointVert() {
	return pointVert;
}

void Point::setPointVert(float* PointVert) {
	this->pointVert = pointVert;
}

float* Point::getPointColors() {
	return pointColors;
}
void Point::setPointColors(float* PointColors) {
	this->pointColors = pointColors;
}

int Point::getHowManyPoints() {
	return howManyPoints;
}
void Point::setHowManyPoints(int howManyPoints) {
	this->howManyPoints = howManyPoints;
}