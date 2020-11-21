#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <memory>

namespace SouraEngine
{
	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void Bind();
		void Unbind();

		//To-add vertex buffers


	private:
		unsigned int m_RendererID;
		unsigned int m_VertexBufferIndex = 0;
		
	};
}