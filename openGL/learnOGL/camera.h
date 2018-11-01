#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include <vector>

enum Camera_movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

const float YAW         = -90.0f;
const float PITCH       =  0.0f;
const float SPEED       =  2.5f;
const float SENSITIVITY =  0.1f;
const float ZOOM        =  45.0f;

class Camera
{
public:
	glm::vec3 pos;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 worldUp;
	glm::vec3 right;

	float yaw;
	float pitch;
	float movementSpeed;
	float mouseSensitivity;
	float zoom;

	Camera(glm::vec3 p = glm::vec3(0.0f, 0.0f, 0.0f), 
		glm::vec3 u = glm::vec3(0.0f, 1.0f, 0.0f),
		float y = YAW,
		float pit = PITCH)
	{
		pos = p;
		worldUp = u;
		yaw = y;
		pitch = pit;

		front = glm::vec3(0.0f, 0.0f, -1.0f);

		movementSpeed = SPEED;
		mouseSensitivity = SENSITIVITY;
		zoom = ZOOM;

		updateCameraVectors();
	} 

	glm::mat4 getViewMatrix()
	{
		return glm::lookAt(pos, pos + front, up);
	}

	void processMouseScroll(float y)
	{
		zoom -= y;

		if (zoom > 45.0f) zoom = 45.0f;
		if (zoom < 1.0f) zoom = 1.0f;
	}

	void processMouseMovement(float offsetX, float offsetY)
	{
		offsetX *= mouseSensitivity;
		offsetY *= mouseSensitivity;

		pitch += offsetY;
		yaw += offsetX;

		if (pitch > 89.0f) pitch = 89.0f;
		if (pitch < -89.0f) pitch = -89.0f;

		updateCameraVectors();
	}

	void processKeyboard(enum Camera_movement direction, float deltaTime)
	{
		float velocity = movementSpeed * deltaTime;

		switch (direction) {
		case FORWARD:
			pos += front * velocity;
			break;
		case BACKWARD:
			pos -= front * velocity;
			break;
		case LEFT:
			pos -= right * velocity;
			break;
		case RIGHT:
			pos += right * velocity;
			break;
		default:
			break;
		}

		pos.y = 0;
	}

private:
	void updateCameraVectors()
	{
		glm::vec3 f;
		f.x = cos(glm::radians(yaw))*cos(glm::radians(pitch));
		f.y = sin(glm::radians(pitch));
		f.z = sin(glm::radians(yaw))*cos(glm::radians(pitch));
		front = glm::normalize(f);

		right = glm::normalize(glm::cross(front, worldUp));
		up = glm::normalize(glm::cross(right, front));
	}
};

#endif
