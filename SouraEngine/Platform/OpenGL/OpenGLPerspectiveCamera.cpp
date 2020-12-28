#include "OpenGLPerspectiveCamera.h"

namespace SouraEngine
{
	OpenGLPerspectiveCamera::OpenGLPerspectiveCamera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
	{
		m_Position = position;
		m_WorldUp = up;
		m_Yaw = yaw;
		m_Pitch = pitch;
		UpdateCameraVectors();
	}
	OpenGLPerspectiveCamera::OpenGLPerspectiveCamera(float positionX, float positionY, float positionZ, float upX, float upY, float upZ, float yaw, float pitch)
	{
		m_Position = { positionX,positionY,positionZ };
		m_WorldUp = { upX,upY,upZ };
		m_Yaw = yaw;
		m_Pitch = pitch;
		UpdateCameraVectors();
	}
	const glm::mat4 & OpenGLPerspectiveCamera::GetViewMatrix() const
	{
		return m_ViewMatrix;
	}
	void OpenGLPerspectiveCamera::RecalculateViewMatrix()
	{
		m_ViewMatrix = glm::lookAt(m_Position, m_Position + m_Front, m_Up);
	}
	void OpenGLPerspectiveCamera::UpdateCameraVectors()
	{
		// calculate the new Front vector
		glm::vec3 front;
		front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
		front.y = sin(glm::radians(m_Pitch));
		front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
		m_Front = glm::normalize(front);
		// also re-calculate the Right and Up vector
		m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));
		m_Up = glm::normalize(glm::cross(m_Right, m_Front));
	}
}