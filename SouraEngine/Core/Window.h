#pragma once
#include <string>
#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Renderer/GraphicsContext.h"

namespace SouraEngine
{
	class Window
	{
	public:
		Window(std::string title, const uint32_t width, const uint32_t height);
		~Window();

		void OnUpdate();

		uint32_t GetWidth();
		uint32_t GetHeight();

		static void framebufferSizeCallback(GLFWwindow* window, int width, int height);

		GLFWwindow* GetNativeWindow() const { return m_Window; }

	private:
		std::string m_Title;
		uint32_t m_Width, m_Height;
		GLFWwindow* m_Window;
		std::unique_ptr<GraphicsContext> m_Context;
	};
}