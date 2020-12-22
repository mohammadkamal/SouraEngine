#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>

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

		virtual void Init() = 0;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
		virtual void SetClearColor(glm::vec4 color) = 0;

		static std::unique_ptr<RenderCommand> Create();

	};
}