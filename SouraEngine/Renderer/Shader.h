#pragma once

#include <glad/glad.h> // include glad to get all the required OpenGL headers

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <array>

namespace SouraEngine
{

	class Shader
	{
	public:
		// the program ID
		uint32_t ID;

		// constructor reads and builds the shader
		Shader(const std::string& filepath);

		void use();

		// utility uniform functions
		void setBool(const std::string &name, bool value) const;
		void setInt(const std::string &name, int value) const;
		void setFloat(const std::string &name, float value) const;

		void setVec2(const std::string &name, glm::vec2 &value) const;
		void setVec2(const std::string &name, float x, float y) const;
		void setVec3(const std::string &name, glm::vec3 &value) const;
		void setVec3(const std::string &name, float x, float y, float z) const;
		void setVec4(const std::string &name, glm::vec4 &value) const;
		void setVec4(const std::string &name, float x, float y, float z, float w) const;

		void UploadUniformMat2(const std::string &name, const glm::mat2& matrix);
		void UploadUniformMat3(const std::string &name, const glm::mat3& matrix);
		void UploadUniformMat4(const std::string &name, const glm::mat4& matrix);

	private:
		std::string ReadFile(const std::string& filepath);
		std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);
		void Compile(const std::unordered_map<GLenum, std::string>& shaderSources);
	};
}