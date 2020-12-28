#include "OpenGLGraphicsContext.h"
#include <iostream>

#include "Core/Window.h"

namespace SouraEngine
{
	OpenGLGraphicsContext::OpenGLGraphicsContext(GLFWwindow * window) :m_Window(window)
	{
	}
	void OpenGLGraphicsContext::Init()
	{
		glfwMakeContextCurrent(m_Window);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD";
		}
	}
	void OpenGLGraphicsContext::SwapBuffers()
	{
		glfwSwapBuffers(m_Window);
	}
}