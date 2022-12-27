#pragma once

#include <GL/freeglut.h>
#include <cmath>
#include <iostream>
#include "EasyFreeGLUTShapesDrawer.h"

#define M_PI 3.14159265358979323846264338327950288



//void keyboard(unsigned char key, int x, int y);
//void releaseKey(unsigned char key, int x, int y);
//
//void renderScene(void);

//void mouseMove(int x, int y);
//void mouseButton(int button, int state, int x, int y);
//void pressKey(int key, int xx, int yy);
//
////float angle = 0.0f;
////float lx = 0.0f, lz = -1.0f;
////float x = 0.0f, z = 5.0f;
////
////float deltaAngle = 0.0f;
////float deltaMove = 0;
////int xOrigin = -1;

class Engine {

private:

	static const int WINDOW_WIDTH;
	static const int WINDOW_HEIGHT;
	static const char * APP_TITLE;

	static Engine* instance;
	Engine();
	virtual ~Engine();

	float deltaTime;



public:

	static Engine* getInstance();

	void init(int argc, char** argv);
	void start();

	static void update();
	static void render();

	static void changeSize(int w, int h);
	static void keyboard(unsigned char key, int x, int y);

	float getDeltaTime();
};