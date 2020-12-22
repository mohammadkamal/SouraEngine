#include "OpenGLRenderCommand.h"
#include <GLFW/glfw3.h>

namespace SouraEngine
{
	void OpenGLRenderCommand::Init()
	{
	}
	void OpenGLRenderCommand::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
	}
	void OpenGLRenderCommand::SetClearColor(glm::vec4 color)
	{
		glClearColor(color.x, color.y, color.z, color.w);
	}
}