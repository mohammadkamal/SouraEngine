#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace SouraEngine
{
	class GraphicsContext
	{
	public:
		GraphicsContext(GLFWwindow* window);
		~GraphicsContext() = default;

		void Init();
		void SwapBuffers();

	private:
		GLFWwindow* m_Window;

	};
}