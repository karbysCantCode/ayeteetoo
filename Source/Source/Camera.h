#ifndef CAMERA_H
#define CAMERA_H

#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <iostream>

class Camera
{
private:
	const float m_CameraSpeed = 10;

	const float m_Sensitivity = 0.1f;
	float m_Yaw = -90.0f, m_Pitch, M_Roll;
	float m_LastX, m_LastY;

	const float m_MaxFov = 120.0f;

	float m_RelativeCameraSpeed = m_CameraSpeed;

public:
	float currentFov = 45.0f;

	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	Camera();
	~Camera();

	inline void registerRelativeCameraSpeed(const float deltaTime)
	{
		m_RelativeCameraSpeed = deltaTime * m_CameraSpeed;
	}
	inline void registerW()
	{
		cameraPos += m_RelativeCameraSpeed * cameraFront;
	}
	inline void registerS()
	{
		cameraPos -= m_RelativeCameraSpeed * cameraFront;
	}
	inline void registerA()
	{
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * m_RelativeCameraSpeed;
	}
	inline void registerD()
	{
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * m_RelativeCameraSpeed;
	}

	inline void registerScroll(int yoffset)
	{
		currentFov -= (float)yoffset;
		if (currentFov < 1.0f)
			currentFov = 1.0f;
		if (currentFov > m_MaxFov)
			currentFov = m_MaxFov;
	}
	inline void registerMouseMove(double xpos, double ypos)
	{
		float xoffset = xpos - m_LastX;
		float yoffset = ypos - m_LastY;
		m_LastX = xpos;
		m_LastY = ypos;

		xoffset *= m_Sensitivity;
		yoffset *= m_Sensitivity;

		m_Yaw += xoffset;
		m_Pitch -= yoffset;

		if (m_Pitch > 89.0f)
			m_Pitch = 89.0f;
		if (m_Pitch < -89.0f)
			m_Pitch = -89.0f;

		glm::vec3 direction;
		direction.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
		direction.y = sin(glm::radians(m_Pitch));
		direction.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));

		cameraFront = glm::normalize(direction);
	}
	inline void setLastPositions(double xpos, double ypos)
	{
		m_LastX = xpos;
		m_LastY = ypos;
	}
};

#endif CAMERA_H