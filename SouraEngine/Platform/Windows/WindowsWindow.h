#pragma once
#include "Core/Window.h"
#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace SouraEngine
{
	class WindowsWindow :public Window
	{
	public:
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();

		virtual void OnUpdate() override;
		virtual uint32_t GetWidth() const override { return m_Data.Width; }
		virtual uint32_t GetHeight() const override { return m_Data.Height; }

		//Event Callback Method
		//VSync

		virtual void* GetNativeWindow() const { return m_Window; }

	private:
		virtual void Init(const WindowProperties& props);
		virtual void Shutdown();

		GLFWwindow* m_Window;
		std::unique_ptr<GraphicsContext> m_Context;

		struct WindowData
		{
			std::string Title;
			uint32_t Width, Height;
			//VSync
			//Event Callback
		};

		WindowData m_Data;
	};
}