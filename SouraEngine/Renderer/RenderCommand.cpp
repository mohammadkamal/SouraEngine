#include "RenderCommand.h"

namespace SouraEngine
{
	void RenderCommand::SetClearColor(glm::vec4 color)
	{
		glClearColor(color.x, color.y, color.z, color.w);
	}
}