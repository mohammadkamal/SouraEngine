#pragma once

#include <glad/glad.h> // include glad to get all the required OpenGL headers
#include <glm/glm.hpp>
#include <string>
#include <unordered_map>

namespace SouraEngine
{
	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		// utility uniform functions
		virtual void SetBool(const std::string &name, bool value) = 0;

		virtual void SetInt(const std::string &name, int value) = 0;
		virtual void SetIntArray(const std::string &name, int* values, uint32_t count) = 0;

		virtual void SetFloat(const std::string &name, float value) = 0;
		virtual void SetFloat2(const std::string &name, const glm::vec2& value) = 0;
		virtual void SetFloat2(const std::string &name, float x, float y) = 0;
		virtual void SetFloat3(const std::string &name, const glm::vec3& value) = 0;
		virtual void SetFloat3(const std::string &name, float x, float y, float z) = 0;
		virtual void SetFloat4(const std::string &name, const glm::vec4& value) = 0;
		virtual void SetFloat4(const std::string &name, float x, float y, float z, float w) = 0;

		virtual void UploadUniformMat2(const std::string &name, const glm::mat2& matrix) = 0;
		virtual void UploadUniformMat3(const std::string &name, const glm::mat3& matrix) = 0;
		virtual void UploadUniformMat4(const std::string &name, const glm::mat4& matrix) = 0;

		static std::shared_ptr<Shader> Create(const std::string& filepath);

	};
}