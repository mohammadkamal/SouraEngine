#include "Transform.h"

namespace SouraEngine
{
	Transform::Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	{
		m_Position = position;
		m_Rotation = rotation;
		m_Scale = scale;
	}

	void Transform::SetPosition(glm::vec3 position)
	{
		m_Position = position;
	}

	glm::mat4 Transform::Translate(glm::vec3 delta)
	{
		m_Translation = glm::translate(m_Translation, delta);
		return m_Translation;
	}

}