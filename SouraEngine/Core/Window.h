#pragma once
#include <string>
#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GraphicsContext.h"

namespace SouraEngine
{
	class Window
	{
	public:
		Window(std::string title, const unsigned int width, const unsigned int height);
		~Window();

		void OnUpdate();

		unsigned int GetWidth();
		unsigned int GetHeight();

		static void framebufferSizeCallback(GLFWwindow* window, int width, int height);

		GLFWwindow* GetNativeWindow() const { return m_Window; }

	private:
		std::string m_Title;
		unsigned int m_Width, m_Height;
		GLFWwindow* m_Window;
		std::unique_ptr<GraphicsContext> m_Context;
	};
}