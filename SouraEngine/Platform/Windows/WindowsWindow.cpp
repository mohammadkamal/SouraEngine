#include "WindowsWindow.h"
#include <iostream>

namespace SouraEngine
{
	static void GLFWErrorCallback(int error, const char* description)
	{
		std::cout << "GLFW Error (" << error << ": "<< description << ")" << std::endl;
	}

	WindowsWindow::WindowsWindow(const WindowProperties & props)
	{
		Init(props);
	}
	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}
	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		m_Context->SwapBuffers();
	}
	void WindowsWindow::Init(const WindowProperties & props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		//Logging
		std::cout << "Creating window " << props.Title << "(" << props.Width <<", " << props.Height << ")" << std::endl;

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);

		if (m_Window == NULL)
		{
			glfwTerminate();
			glfwSetErrorCallback(GLFWErrorCallback);
		}

		m_Context = GraphicsContext::Create(m_Window);
		m_Context->Init();

		//To be added: Set GLFW callbacks

	}
	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}
}