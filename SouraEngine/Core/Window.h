#pragma once
#include <string>
#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	unsigned int GetWidth();
	unsigned int GetHeight();

	//static std::unique_ptr<GLFWwindow> Create(std::string title, unsigned int width, unsigned int height);
	static GLFWwindow* Create(std::string title, const unsigned int width, const unsigned int height);

private:
	//static std::string m_Title;
	unsigned int m_Width, m_Height;
	static GLFWwindow* m_Window;
};