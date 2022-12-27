#include "Cube.h"

Cube::Cube() {
	cubeVert = nullptr;
	cubeNorm = nullptr;
	cubeColors = nullptr;
	cubeInd = nullptr;
	
}

Cube::Cube(float* cubeVert, float* cubeNorm, float* cubeColors, unsigned char* cubeInd) {
	this->cubeVert = cubeVert;
	this->cubeNorm = cubeNorm;
	this->cubeColors = cubeColors;
	this->cubeInd = cubeInd;
}

void Cube::draw() {

	if (cubeVert == nullptr || cubeNorm == nullptr || cubeColors == nullptr || cubeInd == nullptr)
		return;

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, cubeVert);

	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, 0, cubeNorm);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, cubeColors);

	glDrawElements(GL_TRIANGLES, sizeof(cubeInd), GL_UNSIGNED_BYTE, cubeInd);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

float* Cube::getCubeVert() {
	return cubeVert;
}

void Cube::setCubeVert(float* cubeVert) {
	this->cubeVert = cubeVert;
}

float* Cube::getCubeNorm() {
	return cubeNorm;

}
void Cube::setCubeNorm(float* cubeNorm) {
	this->cubeNorm = cubeNorm;
}

float* Cube::getCubeColors() {
	return cubeColors;
}
void Cube::setCubeColors(float* cubeColors) {
	this->cubeColors = cubeColors;
}

unsigned char* Cube::getCubeInd() {
	return cubeInd;
}
void Cube::setCubeInd(unsigned char* cubeInd) {
	this->cubeInd = cubeInd;
}
