#include "Cube.h"

Cube::Cube() {
	cubeVert = nullptr;
	cubeNorm = nullptr;
	cubeColors = nullptr;
	cubeInd = nullptr;
	
}

Cube::Cube(float* cubeVert, float* cubeNorm, float* cubeColors, unsigned int* cubeInd) {
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

	//glEnableClientState(GL_NORMAL_ARRAY);
	//glNormalPointer(GL_FLOAT, 0, cubeNorm);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, cubeColors);

	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_INT, cubeInd);

	glDisableClientState(GL_VERTEX_ARRAY);
	//glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Cube::translate(float x, float y, float z) {
	glTranslatef(x, y, z);
}

void Cube::rotate(float angle, float x, float y, float z) {
	glRotatef(glm::radians(angle), x, y, z);
}
void Cube::scale(float x, float y, float z) {
	glScalef(x, y, z);
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

unsigned int* Cube::getCubeInd() {
	return cubeInd;
}
void Cube::setCubeInd(unsigned int* cubeInd) {
	this->cubeInd = cubeInd;
}

