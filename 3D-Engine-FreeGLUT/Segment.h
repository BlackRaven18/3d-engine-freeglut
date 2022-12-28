#pragma once
#include <GL/freeglut.h>
#include "DrawableObject.h"

class Segment : public virtual DrawableObject {
private:
	float* segmentVert;
	float* segmentColors;
	int howManySegments;

public:
	Segment();
	Segment(float* segmentVert, float* segmentColors, int howManySegments);

	void draw();

	float* getSegmentVert();
	void setSegmentVert(float* SegmentVert);

	float* getSegmentColors();
	void setSegmentColors(float* SegmentColors);

	int getHowManySegments();
	void setHowManySegments(int howManySegments);
};