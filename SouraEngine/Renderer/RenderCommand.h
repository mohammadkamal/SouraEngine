#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>

namespace SouraEngine
{
	enum class ShapeType
	{
		None = 0,
		Triangle = 1,
		Quad = 2,
		Cube = 3
	};

	class RenderCommand
	{
	public:
		RenderCommand() = default;

		void Init();
		void SetViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
		void SetClearColor(glm::vec4 color);

	};
}