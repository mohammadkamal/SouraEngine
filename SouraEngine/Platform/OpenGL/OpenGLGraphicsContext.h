#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Renderer/GraphicsContext.h"

namespace SouraEngine
{
	class OpenGLGraphicsContext : public GraphicsContext
	{
	public:
		OpenGLGraphicsContext(GLFWwindow* window);

		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow* m_Window;
	};
}