#include "Line.h"

Line::Line() {
	lineVert = nullptr;
	lineColors = nullptr;
	howManyLines = 0;
}

Line::Line(float* lineVert, float* lineColors, int howManyLines) {
	this->lineVert = lineVert;
	this->lineColors = lineColors;
	this->howManyLines = howManyLines;
}

void Line::drawLine(){

	if (lineVert == nullptr || lineColors == nullptr || howManyLines < 1)
		return;

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, lineVert);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, lineColors);

	glDrawArrays(GL_LINES, 0, howManyLines * 2);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

float* Line::getLineVert() {
	return lineVert;
}

void Line::setLineVert(float* LineVert) {
	this->lineVert = lineVert;
}

float* Line::getLineColors() {
	return lineColors;
}
void Line::setLineColors(float* LineColors) {
	this->lineColors = lineColors;
}

int Line::getHowManyLines() {
	return howManyLines;
}
void Line::setHowManyLines(int howManyLines) {
	this->howManyLines = howManyLines;
}