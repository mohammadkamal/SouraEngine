#pragma once
#include "Renderer/IndexBuffer.h"

namespace SouraEngine
{
	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		virtual ~OpenGLIndexBuffer();

		virtual void Bind() const;
		virtual void Unbind() const;

	private:
		uint32_t m_RendererID;
	};
}