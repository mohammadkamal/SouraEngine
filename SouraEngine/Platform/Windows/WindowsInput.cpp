#include "Core/Input.h"
#include "Core/Application.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace SouraEngine
{
	bool Input::isKeyPressed(KeyCode key)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, static_cast<int32_t>(key));
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
	bool Input::isMouseButtonPressed(MouseCode button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));
		return state == GLFW_PRESS;
	}
	Reyadhah::Vector2 Input::GetMousePosition()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);
		return Reyadhah::Vector2((float)xPos, (float)yPos);
	}
	float Input::GetMousePositionX()
	{
		Reyadhah::Vector2 vector = GetMousePosition();
		return vector.x;
	}
	float Input::GetMousePositionY()
	{
		Reyadhah::Vector2 vector = GetMousePosition();
		return vector.y;
	}
}