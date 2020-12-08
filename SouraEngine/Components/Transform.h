#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace SouraEngine
{
	class Transform
	{
	public:
		Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
		~Transform() = default;

		//Position
		glm::vec3 GetPosition() { return m_Position; }
		void SetPosition(glm::vec3 position);

		//Rotation
		glm::vec3 GetRotation();
		void SetRotation(glm::vec3 rotation);

		//Scale
		glm::vec3 GetScale();
		void SetScale(glm::vec3 scale);

		glm::mat4 Translate(glm::vec3 delta);
		void Rotate(glm::mat4 value, float degree);


	private:
		glm::vec3 m_Position, m_Rotation, m_Scale;
		glm::mat4 m_Translation = glm::mat4(1.0f);
	};
}