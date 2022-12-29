#pragma once

#define M_PI 3.14159265358979323846264338327950288


#include <GL/freeglut.h>
#include <cmath>
#include <iostream>
#include "EasyFreeGLUTShapesDrawer.h"
#include <glm.hpp>
#include <gtx/transform.hpp>
#include <gtc/type_ptr.hpp>

#include "Point.h"
#include "Segment.h"
#include "Line.h"
#include "Triangle.h"
#include "TriangleStrip.h"
#include "TriangleFan.h"
#include "Quad.h"
#include "Cube.h"
#include "Camera.h"
#include "BitmapHandler.h"





enum ShadowMapping {FLAT, SMOOTH};

class Engine {

private:

	static const int WINDOW_WIDTH;
	static const int WINDOW_HEIGHT;
	static const char * APP_TITLE;
	static const bool LIGHTNING_ENABLED;
	static const int SHADOW_ALGORYTHM;

	static Engine* instance;
	Engine();
	virtual ~Engine();

	static float currentTime, prevTime, deltaTime;
	static float deltaX, deltaY;


public:

	static Engine* getInstance();

	static Camera camera;

	void init(int argc, char** argv);
	void start();

	static void update();
	static void display();

	static void changeSize(int w, int h);
	static void keyboard(unsigned char key, int x, int y);
	static void specialKeysHandler(int key, int x, int y);

	float getDeltaTime();
};