#include "IndexBuffer.h"
#include "Platform/OpenGL/OpenGLIndexBuffer.h"

namespace SouraEngine
{
	std::shared_ptr<IndexBuffer> IndexBuffer::Create(uint32_t * indices, uint32_t count)
	{
		return std::make_shared<OpenGLIndexBuffer>(indices, count);
	}
}