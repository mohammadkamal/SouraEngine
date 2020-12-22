#pragma once
#include "Renderer/Shader.h"

namespace SouraEngine
{
	class OpenGLShader :public Shader
	{
	public:
		OpenGLShader(const std::string& filepath);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		// utility uniform functions
		virtual void SetBool(const std::string &name, bool value) override;

		virtual void SetInt(const std::string &name, int value) override;
		virtual void SetIntArray(const std::string &name, int* values, uint32_t count) override;

		virtual void SetFloat(const std::string &name, float value) override;
		virtual void SetFloat2(const std::string &name, const glm::vec2& value) override;
		virtual void SetFloat2(const std::string &name, float x, float y) override;
		virtual void SetFloat3(const std::string &name, const glm::vec3& value) override;
		virtual void SetFloat3(const std::string &name, float x, float y, float z) override;
		virtual void SetFloat4(const std::string &name, const glm::vec4& value) override;
		virtual void SetFloat4(const std::string &name, float x, float y, float z, float w) override;

		virtual void UploadUniformMat2(const std::string &name, const glm::mat2& matrix) override;
		virtual void UploadUniformMat3(const std::string &name, const glm::mat3& matrix) override;
		virtual void UploadUniformMat4(const std::string &name, const glm::mat4& matrix) override;

	private:
		std::string ReadFile(const std::string& filepath);
		std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);
		void Compile(const std::unordered_map<GLenum, std::string>& shaderSources);

		uint32_t m_RendererID; //Program ID
	};
}