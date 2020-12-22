#include "VertexArray.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace SouraEngine
{
	std::shared_ptr<VertexArray> VertexArray::Create()
	{
		return std::make_shared<OpenGLVertexArray>();
	}
}