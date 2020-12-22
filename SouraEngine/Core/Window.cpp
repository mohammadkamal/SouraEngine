#include "Window.h"
#include <iostream>

namespace SouraEngine
{
	Window::Window(std::string title, const uint32_t width, const uint32_t height)
	{
		m_Title = title;
		m_Width = width;
		m_Height = height;

		m_Window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

		m_Context = GraphicsContext::Create(m_Window);

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
	uint32_t Window::GetWidth()
	{
		return m_Width;
	}

	uint32_t Window::GetHeight()
	{
		return m_Height;
	}

	void Window::framebufferSizeCallback(GLFWwindow * window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}