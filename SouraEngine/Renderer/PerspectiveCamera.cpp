#include "PerspectiveCamera.h"
#include "Platform/OpenGL/OpenGLPerspectiveCamera.h"

namespace SouraEngine
{
	std::shared_ptr<PerspectiveCamera> PerspectiveCamera::Create(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
	{
		return std::make_shared<OpenGLPerspectiveCamera>(position, up, yaw, pitch);
	}
	std::shared_ptr<PerspectiveCamera> PerspectiveCamera::Create(float positionX, float positionY, float positionZ, float upX, float upY, float upZ, float yaw, float pitch)
	{
		return std::make_shared<OpenGLPerspectiveCamera>(positionX, positionY, positionZ, upX, upY, upZ, yaw, pitch);
	}
}