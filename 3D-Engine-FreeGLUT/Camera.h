#pragma once
#include <glm.hpp>
#include <gtx/transform.hpp>
#include <gtc/type_ptr.hpp>

class Camera {
private:

	glm::mat4 mainMatrix;
	glm::vec3 position;

public:
	Camera();
	//fovy - The field of view angle, in degrees, in the y - direction.
	//aspect - The aspect ratio that determines the field of view in the x - direction.The aspect ratio is the ratio of x(width) to y(height).
	//zNear - The distance from the viewer to the near clipping plane(always positive).
	//zFar - The distance from the viewer to the far clipping plane(always positive).
	void setPerspective(float fovy, float aspect, float zNear, float zFar);
	void setPosition(float x, float y, float z);

	void setUpDownAngle(float angle);
	void setLeftRightAngle(float angle);

	void moveUp(float angle) {
		mainMatrix = glm::rotate(mainMatrix, glm::radians(-angle), glm::vec3(1, 0, 0));
	}
	void moveDown(float angle) {
		mainMatrix = glm::rotate(mainMatrix, glm::radians(angle), glm::vec3(1, 0, 0));
	}
	void moveLeft(float angle) {
		mainMatrix = glm::rotate(mainMatrix, glm::radians(-angle), glm::vec3(0, 1, 0));
	}
	void moveRight(float angle) {
		mainMatrix = glm::rotate(mainMatrix, glm::radians(angle), glm::vec3(0, 1, 0));
	}
	void moveForward(float value) {
		//position.z += value;
		//mainMatrix = glm::translate(position);
		//mainMatrix *= glm::vec3(0, 0, value);
		mainMatrix = glm::translate(mainMatrix, glm::vec3(0, 0, value));
	}
	void moveBackward(float value) {
		//position.z -= value;
		//mainMatrix = glm::translate(position);
		//mainMatrix *= glm::vec3(0, 0, -value);
		mainMatrix = glm::translate(mainMatrix, glm::vec3(0, 0, -value));
	}

	glm::mat4 getMainMatrix();


};