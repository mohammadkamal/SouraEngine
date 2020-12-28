#pragma once
#include "Camera.h"
#include <memory>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

namespace SouraEngine
{
	class PerspectiveCamera
	{
	public:
		~PerspectiveCamera() = default;

		//virtual void SetProjection() = 0;

		virtual const glm::vec3& GetPosition() const = 0;
		//virtual void SetPosition(const glm::vec3& position) = 0;

		virtual float GetRotation() const = 0;
		//virtual void SetRotation(float rotation) = 0;

		//virtual const glm::mat4& GetProjectionMatrix() const = 0;
		virtual const glm::mat4& GetViewMatrix() const = 0;
		//virtual const glm::mat4& GetViewProjectionMatrix() const = 0;

		static std::shared_ptr<PerspectiveCamera> Create(glm::vec3 position, glm::vec3 up, float yaw, float pitch);
		static std::shared_ptr<PerspectiveCamera> Create(float positionX, float positionY, float positionZ, float upX, float upY, float upZ, float yaw, float pitch);
	};
}