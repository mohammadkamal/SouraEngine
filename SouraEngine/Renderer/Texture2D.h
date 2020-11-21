#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Shader.h"

namespace SouraEngine
{
	class Texture2D
	{
	public:
		Texture2D(const std::string& path);
		~Texture2D();

		void Bind(uint32_t slot);

	private:
		unsigned int texture;
	};
}