#pragma once
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

//Class for presentation puropses only
enum presentationMode { POINTSS, SEGMENT, NORMAL_LINE, TRIANGLE, QUAD, TRIANGLE_FAN, TRIANGLE_STRIP, CUBE,  TEX_TRIANGLE, TEX_QUAD, EASY_SHAPE_1, EASY_SHAPE_2};

class PresentationClass {
private:

	int modeIndicator;

	float segVert[12] = {
		-2, 0, 0,
		0, 2, 0,
		2, 0, 0,
		0, 2, 0
	};

	float segCols[12] = {
		1, 0, 0,
		0, 1, 0,
		1, 0, 0,
		0, 0, 1
	};
	float pointVert[6] = {
		1, 0, 0,
		0, 1, 0
	};

	float pointColors[6]{
		0, 1, 0,
		0, 1, 0
	};

	float lineVert[9] = {
		0, 0, 0,
		2, 0, 0,
		1, -1, 0
	};

	float lineCols[9] = {
		1, 0, 0,
		1, 0, 0,
		1, 0, 0
	};

	float triangleVert[18] = {
		-2, 0, 0,
		2, 0, 0,
		0, 4, 0,
		-2, 0, 0,
		2, 0, 0,
		0, -4, 0
	};

	float triangleColors[18] = {
		1, 1, 1,
		1, 1, 1,
		1, 1, 1,
		1, 1, 1,
		1, 1, 1,
		1, 1, 1
		/*1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		0, 1, 0,
		0, 1, 0,
		0, 1, 0*/
	};

	float triangleStripVert[15] = {
		-1, 1, 0,
		0, 0, 0,
		1, 1, 0,
		1, -1, 0,
		2, 1, 0
	};

	float triangleStripColors[15] = {
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0
	};

	float triangleFanVerts[12] = {
		0, 0, 0,
		-1, 0, 0,
		-1, 1, 0,
		0, 1, 0
	};

	float triangleFanColors[12] = {
		1, 1, 0,
		1, 1, 0,
		1, 1, 0,
		1, 1, 0,
	};

	float quadVerts[12] = {
		-1, 0, 0,
		-1, 1, 0,
		1, 1, 0,
		1, 0, 0
	};

	float quadColors[12] = {
		1, 1, 0,
		1, 1, 0,
		1, 1, 0,
		1, 1, 0,
	};

	float cubeNorm[24] = {
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, -1,
		0, 0, -1,
		0, 0, -1,
		0, 0, -1,
	};


	float cubeColors[24] = {
		1, 1, 1,
		1, 1, 1,
		1, 1, 1,
		1, 1, 1,
		1, 1, 1,
		1, 1, 1,
		1, 1, 1,
		1, 1, 1,
	};

	float cubeVert[24] = {

		0, 0, 0,
		2, 0, 0,
		2, 2, 0,
		0, 2, 0,

		0, 0, 2,
		2, 0, 2,
		2, 2, 2,
		0, 2, 2

	};



	unsigned int cubeInd[24] = {
		// przednia œciana
		0, 1, 2, 3,
		// lewa œciana
		0, 3, 7, 4,
		// prawa œciana
		1, 2, 6, 5,
		// tylna œciana
		4, 5, 6, 7,
		// górna œciana
		0, 1, 5, 4,
		// dolna œciana
		7, 6, 3, 2
	};


	float cubeTextCord[16] = {
		0, 0,
		1, 0,
		0, 1,
		1, 1,
		0, 0,
		1, 0,
		0, 1,
		1, 1,

	};

	float triangleTextCord[12] = {
		0, 0,
		0, 1,
		1, 0,
		0, 0,
		0, 1,
		1, 0
	};

	float quadTextCord[8] = {
		0, 0,
		0, 1,
		1, 1,
		1, 0
	};

	Point* point;
	Segment *segment;
	Line* line;
	Triangle *triangle;
	Quad *quad;
	TriangleFan* tf;
	TriangleStrip* ts;
	Cube *cube;
	Triangle *texturedTriangle;
	Quad *texturedQuad;
	
	EasyFreeGLUTShapesDrawer easyShapeDrawer;




public:
	PresentationClass() {
		std::cout << "***********************************************************" << std::endl;
		std::cout << "                    3D Game Engine Demo" << std::endl;
		std::cout << "***********************************************************" << std::endl;
		std::cout << "Press LEFT button to change mode" << std::endl;
		std::cout << "Press L to turn on/off light" << std::endl;
		std::cout << "Press W,A,S,D, LEFT / RIGHT ARROW to change position" << std::endl;
		std::cout << "***********************************************************" << std::endl;
		std::cout << "Presentation mode: Point" << std::endl;


		modeIndicator = POINTSS;
		segment = new Segment(segVert, segCols, 2);
		point = new Point(pointVert, pointColors, 2);
		line = new Line(NORMAL, lineVert, lineCols, 2);
		triangle = new Triangle(triangleVert, triangleColors, 2);
		quad = new Quad(quadVerts, quadColors, 1);
		tf = new TriangleFan(triangleFanVerts, triangleFanColors, 4);
		ts = new TriangleStrip(triangleStripVert, triangleStripColors, 5);
		cube = new Cube(cubeVert, cubeNorm, cubeColors, cubeInd);
		texturedTriangle = new Triangle(triangleVert, triangleColors, triangleTextCord, 2);
		texturedQuad = new Quad(quadVerts, quadColors, quadTextCord, 1);
	}
	void run() {
		switch (modeIndicator) {
		case POINTSS:
			point->draw();
			break;
		case SEGMENT:
			segment->draw();
			break;
		case NORMAL_LINE:
			line->draw();
			break;
		case TRIANGLE:
			triangle->draw();
			break;
		case QUAD:
			quad->draw();
			break;
		case TRIANGLE_FAN:
			tf->draw();
			break;
		case TRIANGLE_STRIP:
			ts->draw();
			break;
		case CUBE:
			cube->draw();
			break;
		case TEX_TRIANGLE:
			texturedTriangle->drawTextured();
			break;
		case TEX_QUAD:
			texturedQuad->drawTextured();
			break;
		case EASY_SHAPE_1:
			glColor3f(1, 0, 0);
			easyShapeDrawer.drawSolidSphere(3, 10, 10);
			break;
		case EASY_SHAPE_2:
			easyShapeDrawer.drawSolidTeapot(4);
			break;
		default:
			break;
		}
	}

	void changeToNextMode() {
		modeIndicator++;
		//std::cout << modeIndicator << std::endl;
		modeIndicator %= EASY_SHAPE_2 + 1;

		switch (modeIndicator) {
		case POINTSS:
			std::cout << "Presentation mode: Point" << std::endl;
			break;
		case SEGMENT:
			std::cout << "Presentation mode: Segment" << std::endl;
			break;
		case NORMAL_LINE:
			std::cout << "Presentation mode: Line" << std::endl;
			break;
		case TRIANGLE:
			std::cout << "Presentation mode: Triangle" << std::endl;
			break;
		case QUAD:
			std::cout << "Presentation mode: Quad" << std::endl;
			break;
		case TRIANGLE_FAN:
			std::cout << "Presentation mode: Triangle Fan" << std::endl;
			break;
		case TRIANGLE_STRIP:
			std::cout << "Presentation mode: Triangle Strip" << std::endl;
			break;
		case CUBE:
			std::cout << "Presentation mode: Cube" << std::endl;
			break;
		case TEX_TRIANGLE:
			std::cout << "Presentation mode: Textured Triangle" << std::endl;
			break;
		case TEX_QUAD:
			std::cout << "Presentation mode: Textured Quad" << std::endl;
			break;
		case EASY_SHAPE_1:
			std::cout << "Presentation mode: Solid Sphere" << std::endl;
			break;
		case EASY_SHAPE_2:
			std::cout << "Presentation mode: Solid Teapot" << std::endl;
			break;
		default:
			modeIndicator = POINTSS;
			std::cout << "Presentation mode: Point" << std::endl;
			break;
		}
	}
};