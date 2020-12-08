#include "GraphicsContext.h"
#include <iostream>

namespace SouraEngine
{
	GraphicsContext::GraphicsContext(GLFWwindow * window)
	{
		m_Window = window;
	}
	void GraphicsContext::Init()
	{
		glfwMakeContextCurrent(m_Window);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD";
		}
	}
	void GraphicsContext::SwapBuffers()
	{
		glfwSwapBuffers(m_Window);
	}
}