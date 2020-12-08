#include "Window.h"
#include <iostream>

namespace SouraEngine
{
	Window::Window(std::string title, const unsigned int width, const unsigned int height)
	{
		m_Title = title;
		m_Width = width;
		m_Height = height;

		m_Window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

		m_Context = std::make_unique<GraphicsContext>(m_Window);

		if (m_Window == NULL)
		{
			//To be part of Log
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();

		}

		m_Context->Init();
	}
	Window::~Window()
	{
		glfwDestroyWindow(m_Window);
	}
	void Window::OnUpdate()
	{
		m_Context->SwapBuffers();
		glfwPollEvents();
	}
	unsigned int Window::GetWidth()
	{
		return m_Width;
	}

	unsigned int Window::GetHeight()
	{
		return m_Height;
	}

	void Window::framebufferSizeCallback(GLFWwindow * window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}