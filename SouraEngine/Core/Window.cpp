#include "Window.h"
#include <iostream>

namespace SouraEngine
{
	static GLFWwindow* m_Window;

	unsigned int Window::GetWidth()
	{
		return m_Width;
	}

	unsigned int Window::GetHeight()
	{
		return m_Height;
	}

	GLFWwindow * Window::Create(std::string title, unsigned int width, unsigned int height)
	{
		/*m_Title = title;
		m_Width = width;
		m_Height = height;*/

		m_Window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

		//GLFWwindow* f_Window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

		if (m_Window /*f_Window*/ == NULL)
		{
			//To be part of Log
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();

		}

		glfwMakeContextCurrent(m_Window/* f_Window*/);
		//glfwSetFramebufferSizeCallback(/*m_Window*/ f_Window, &framebufferSizeCallback);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD";
		}

		return m_Window;
		//return f_Window;
	}
	void Window::framebufferSizeCallback(GLFWwindow * window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}