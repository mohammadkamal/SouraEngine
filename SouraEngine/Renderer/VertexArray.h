#pragma once
#include <memory>

namespace SouraEngine
{
	class VertexArray
	{
	public:
		virtual ~VertexArray() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		//To-add vertex buffers

		static std::shared_ptr<VertexArray> Create();
	};
}