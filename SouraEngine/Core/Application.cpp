#include "Application.h"
#include "Renderer2D.h"
#include <iostream>

namespace SouraEngine
{
	//Application* Application::s_Instance = nullptr;

	Application::Application(const std::string & name)
	{
		/*if (!s_Instance)
		{
			std::cout << "Application Already exists!" << std::endl;
		}
		s_Instance = this;*/
		
		Renderer2D::get().Awake();

		m_Window = Window::Create(WindowProperties(name));

		//Event Callback for Window
		Renderer2D::get().Init();

	}
	Application::~Application()
	{
		Renderer2D::get().Shutdown();
	}
	void Application::Run()
	{
		m_LastFrame = (float)glfwGetTime();
		while (m_Running)
		{
			Renderer2D::get().OnUpdate();
			m_Window->OnUpdate();
		}
	}
	void Application::Close()
	{
		m_Running = false;
	}
}