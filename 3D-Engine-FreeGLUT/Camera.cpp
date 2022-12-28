#include "Camera.h"

Camera::Camera() {
	position.x = position.y = position.z = 0;
}

void Camera::setPerspective(float fovy, float aspect, float zNear, float zFar) {
	//glm::perspective<float>(glm::radians(fovy), aspect, zNear, zFar);
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void Camera::setPosition(float x, float y, float z) {
	position.x = x;
	position.y = y;
	position.z = z;
	mainMatrix = glm::translate(position);
}

void Camera::setUpDownAngle(float angle) {
	mainMatrix = glm::rotate(mainMatrix, glm::radians(angle), glm::vec3(1, 0, 0));
}
void Camera::setLeftRightAngle(float angle) {
	mainMatrix = glm::rotate(mainMatrix, glm::radians(angle), glm::vec3(0, 1, 0));
}

glm::mat4 Camera::getMainMatrix() {
	return mainMatrix;
}