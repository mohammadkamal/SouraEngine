#pragma once
#include <iostream>

namespace SouraEngine
{
	class Texture2D
	{
	public:
		virtual ~Texture2D() = default;

		virtual void Bind(uint32_t slot) = 0;

		static std::shared_ptr<Texture2D> Create(const std::string& path);

	};
}