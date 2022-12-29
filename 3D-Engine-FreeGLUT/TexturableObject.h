#pragma once
#include "GameObject.h"

class TexturableObject:public virtual GameObject {
public:
	virtual void drawTextured() {};
};