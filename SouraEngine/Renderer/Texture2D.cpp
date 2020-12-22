#include "Texture2D.h"
#include "Platform/OpenGL/OpenGLTexture2D.h"

namespace SouraEngine
{
	std::shared_ptr<Texture2D> Texture2D::Create(const std::string & path)
	{
		return std::make_shared<OpenGLTexture2D>();
	}
}