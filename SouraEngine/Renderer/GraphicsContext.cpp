#include "GraphicsContext.h"

#include "Platform/OpenGL/OpenGLGraphicsContext.h"

namespace SouraEngine
{
	std::unique_ptr<GraphicsContext> GraphicsContext::Create(void * window)
	{
		return std::make_unique<OpenGLGraphicsContext>(static_cast<GLFWwindow*>(window));
	}
}