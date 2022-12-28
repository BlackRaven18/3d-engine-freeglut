#pragma once
#include "GameObject.h"

class TransformableObject : public virtual GameObject {

	virtual void translate(float x, float y, float z) {};
	virtual void rotate(float angle, float x, float y, float z) {};
	virtual void scale(float x, float y, float z) {};
};