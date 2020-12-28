#pragma once
#include "Renderer/PerspectiveCamera.h"
#include <Math/Vector2.h>

namespace SouraEngine
{
	class OpenGLPerspectiveCamera :public PerspectiveCamera
	{
	public:
		OpenGLPerspectiveCamera(glm::vec3 position, glm::vec3 up, float yaw, float pitch);
		OpenGLPerspectiveCamera(float positionX, float positionY, float positionZ, float upX, float upY, float upZ, float yaw, float pitch);

		//virtual void SetProjection() override;

		virtual const glm::vec3& GetPosition() const override { return m_Position; }
		//virtual void SetPosition(const glm::vec3& position) override;

		virtual float GetRotation() const override { return m_Rotation; }
		//virtual void SetRotation(float rotation) override;

		//virtual const glm::mat4& GetProjectionMatrix() const override;
		virtual const glm::mat4& GetViewMatrix() const override;
		//virtual const glm::mat4& GetViewProjectionMatrix() const override;

	private:
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;
		glm::vec3 m_Position = { 0.0f ,0.0f ,0.0f };
		glm::vec3 m_Up = { 0.0f, 1.0f, 0.0f };
		glm::vec3 m_Front, m_Right, m_WorldUp;
		float m_Rotation = 0.0f;

		float m_Yaw = -90.0f;
		float m_Pitch = 0.0f;
		void RecalculateViewMatrix();
		void UpdateCameraVectors();
	};
}