#include "RenderCommand.h"
#include "Platform/OpenGL/OpenGLRenderCommand.h"

namespace SouraEngine
{

	std::unique_ptr<RenderCommand> RenderCommand::Create()
	{
		return std::make_unique<OpenGLRenderCommand>();
	}
}