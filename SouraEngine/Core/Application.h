#pragma once
#include "Window.h"

namespace SouraEngine
{
	class Application
	{
	public:
		Application(const std::string& name = "New Soura Application");
		virtual ~Application();

		void Run();
		
		//OnEvent Method

		Window& GetWindow() { return *m_Window; }

		void Close();
		
		//static Application& Get() { return *s_Instance; }
		static Application& Get()
		{
			static Application g_Application;
			return g_Application;
		}

	private:
		bool OnWindowClose();
		bool OnWindowResize();

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		bool m_Minimized = false;
		
		float m_LastFrame = 0.0f;

		//static Application* s_Instance;

	};
}