#include "Shader.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace SouraEngine
{
	std::shared_ptr<Shader> Shader::Create(const std::string & filepath)
	{
		return std::make_shared<OpenGLShader>(filepath);
	}
}