#include "Segment.h"

Segment::Segment() {
	segmentVert = nullptr;
	segmentColors = nullptr;
	howManySegments = 0;
}

Segment::Segment(float* segmentVert, float* segmentColors, int howManySegments) {
	this->segmentVert = segmentVert;
	this->segmentColors = segmentColors;
	this->howManySegments = howManySegments;
}

void Segment::draw(){

	if (segmentVert == nullptr || segmentColors == nullptr || howManySegments < 1)
		return;

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, segmentVert);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, segmentColors);

	glDrawArrays(GL_LINES, 0, howManySegments * 2);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

float* Segment::getSegmentVert() {
	return segmentVert;
}

void Segment::setSegmentVert(float* SegmentVert) {
	this->segmentVert = segmentVert;
}

float* Segment::getSegmentColors() {
	return segmentColors;
}
void Segment::setSegmentColors(float* SegmentColors) {
	this->segmentColors = segmentColors;
}

int Segment::getHowManySegments() {
	return howManySegments;
}
void Segment::setHowManySegments(int howManySegments) {
	this->howManySegments = howManySegments;
}