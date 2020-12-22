#pragma once
#include <memory>

namespace SouraEngine
{
	class GraphicsContext
	{
	public:
		//GraphicsContext(GLFWwindow* window);
		~GraphicsContext() = default;

		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;

		static std::unique_ptr<GraphicsContext> Create(void* window);

	};
}