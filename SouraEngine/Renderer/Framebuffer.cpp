#include "Framebuffer.h"
#include "Platform/OpenGL/OpenGLFramebuffer.h"

namespace SouraEngine
{
	std::shared_ptr<Framebuffer> Framebuffer::Create(const FramebufferSpecification & spec)
	{
		return std::make_shared<OpenGLFramebuffer>(spec);
	}
}