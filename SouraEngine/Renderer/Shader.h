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
		// constructor reads and builds the shader
		Shader() = default;
		Shader(const std::string& filepath);
		~Shader();

		void Bind();
		void Unbind();

		// utility uniform functions
		void SetBool(const std::string &name, bool value) const;

		void SetInt(const std::string &name, int value) const;
		void SetIntArray(const std::string &name, int* values, uint32_t count) const;

		void SetFloat(const std::string &name, float value) const;
		void SetFloat2(const std::string &name, const glm::vec2& value);
		void SetFloat2(const std::string &name, float x, float y);
		void SetFloat3(const std::string &name, const glm::vec3& value);
		void SetFloat3(const std::string &name, float x, float y, float z);
		void SetFloat4(const std::string &name, const glm::vec4& value);
		void SetFloat4(const std::string &name, float x, float y, float z, float w);

		void UploadUniformMat2(const std::string &name, const glm::mat2& matrix);
		void UploadUniformMat3(const std::string &name, const glm::mat3& matrix);
		void UploadUniformMat4(const std::string &name, const glm::mat4& matrix);

	private:
		std::string ReadFile(const std::string& filepath);
		std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);
		void Compile(const std::unordered_map<GLenum, std::string>& shaderSources);

		uint32_t m_RendererID; //Program ID
	};
}