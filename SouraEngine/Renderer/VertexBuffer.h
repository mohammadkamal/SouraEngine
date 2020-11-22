#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace SouraEngine
{
	class VertexBuffer
	{
	public:
		VertexBuffer();
		VertexBuffer(unsigned int size);
		VertexBuffer(float* vertices, unsigned int size);
		~VertexBuffer();

		void Bind();
		void Unbind();

		void SetData(const void* data, unsigned int size);

	private:
		unsigned int m_RendererID;

	};
}