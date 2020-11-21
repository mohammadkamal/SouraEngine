#pragma once
#include <string>
#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
namespace SouraEngine
{
	class Window
	{
	public:
		unsigned int GetWidth();
		unsigned int GetHeight();

		static GLFWwindow* Create(std::string title, const unsigned int width, const unsigned int height);

		void framebufferSizeCallback(GLFWwindow* window, int width, int height);

	private:
		//static std::string m_Title;
		unsigned int m_Width, m_Height;
		//static GLFWwindow* m_Window;
	};
}