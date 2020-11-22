#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace SouraEngine
{
	class IndexBuffer
	{
	public:
		IndexBuffer();
		IndexBuffer(unsigned int* indices, unsigned int count);
		~IndexBuffer();

		void Bind();
		void Unbind();

		void SetData(const void* data, unsigned int size);

	private:
		unsigned int m_RendererID;
	};
}