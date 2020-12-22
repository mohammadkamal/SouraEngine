#include "VertexBuffer.h"
#include "Platform/OpenGL/OpenGLVertexBuffer.h"

namespace SouraEngine
{
	std::shared_ptr<VertexBuffer> VertexBuffer::Create(uint32_t size)
	{
		return std::make_shared<OpenGLVertexBuffer>(size);
	}
	std::shared_ptr<VertexBuffer> VertexBuffer::Create(float * vertices, uint32_t size)
	{
		return std::make_shared<OpenGLVertexBuffer>(vertices, size);
	}
}