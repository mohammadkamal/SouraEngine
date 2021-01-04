#include "Window.h"
#include "Platform/Windows/WindowsWindow.h"

namespace SouraEngine
{
	std::unique_ptr<Window> Window::Create(const WindowProperties & props)
	{
		return std::make_unique<WindowsWindow>(props);
	}
}