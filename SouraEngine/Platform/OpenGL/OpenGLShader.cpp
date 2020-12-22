#include "OpenGLShader.h"

#include <array>
#include <fstream>
#include <iostream>
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

namespace SouraEngine
{
	static GLenum ShaderTypeFromString(const std::string& type)
	{
		if (type == "vertex")
			return GL_VERTEX_SHADER;
		if (type == "fragment")
			return GL_FRAGMENT_SHADER;

		std::cout << "Unknown Type" << std::endl;
		return 0;
	}

	OpenGLShader::OpenGLShader(const std::string & filepath)
	{
		std::string source = ReadFile(filepath);
		auto shaderSources = PreProcess(source);
		Compile(shaderSources);
	}
	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_RendererID);
	}
	void OpenGLShader::Bind() const
	{
		glUseProgram(m_RendererID);
	}
	void OpenGLShader::Unbind() const
	{
		glUseProgram(0);
	}
	void OpenGLShader::SetBool(const std::string & name, bool value)
	{
		glUniform1i(glGetUniformLocation(m_RendererID, name.c_str()), (int)value);
	}
	void OpenGLShader::SetInt(const std::string & name, int value)
	{
		glUniform1i(glGetUniformLocation(m_RendererID, name.c_str()), value);
	}
	void OpenGLShader::SetIntArray(const std::string & name, int * values, uint32_t count)
	{
		glUniform1iv(glGetUniformLocation(m_RendererID, name.c_str()), count, values);
	}
	void OpenGLShader::SetFloat(const std::string & name, float value)
	{
		glUniform1f(glGetUniformLocation(m_RendererID, name.c_str()), value);
	}
	void OpenGLShader::SetFloat2(const std::string & name, const glm::vec2 & value)
	{
		glUniform2fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, &value[0]);
	}
	void OpenGLShader::SetFloat2(const std::string & name, float x, float y)
	{
		glUniform2f(glGetUniformLocation(m_RendererID, name.c_str()), x, y);
	}
	void OpenGLShader::SetFloat3(const std::string & name, const glm::vec3 & value)
	{
		glUniform3fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, &value[0]);
	}
	void OpenGLShader::SetFloat3(const std::string & name, float x, float y, float z)
	{
		glUniform3f(glGetUniformLocation(m_RendererID, name.c_str()), x, y, z);
	}
	void OpenGLShader::SetFloat4(const std::string & name, const glm::vec4 & value)
	{
		glUniform4fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, &value[0]);
	}
	void OpenGLShader::SetFloat4(const std::string & name, float x, float y, float z, float w)
	{
		glUniform4f(glGetUniformLocation(m_RendererID, name.c_str()), x, y, z, w);
	}
	void OpenGLShader::UploadUniformMat2(const std::string & name, const glm::mat2 & matrix)
	{
		uint32_t location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniformMatrix2fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
	}
	void OpenGLShader::UploadUniformMat3(const std::string & name, const glm::mat3 & matrix)
	{
		uint32_t location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
	}
	void OpenGLShader::UploadUniformMat4(const std::string & name, const glm::mat4 & matrix)
	{
		uint32_t location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
	}
	std::string OpenGLShader::ReadFile(const std::string & filepath)
	{
		std::string result;
		std::ifstream in(filepath, std::ios::in | std::ios::binary);
		if (in)
		{
			in.seekg(0, std::ios::end);
			size_t size = in.tellg();
			if (size != -1)
			{
				result.resize(size);
				in.seekg(0, std::ios::beg);
				in.read(&result[0], size);
				in.close();
			}
			else
			{
				std::cout << "Could not read from file " << filepath << std::endl;
			}
		}
		else
		{
			std::cout << "Could not open file " << filepath << std::endl;
		}
		return result;
	}
	std::unordered_map<GLenum, std::string> OpenGLShader::PreProcess(const std::string & source)
	{
		std::unordered_map<GLenum, std::string> shaderSources;

		const char* typeToken = "#type";
		size_t typeTokenLength = strlen(typeToken);
		size_t pos = source.find(typeToken, 0); //Start of shader type declaration line
		while (pos != std::string::npos)
		{
			size_t eol = source.find_first_of("\r\n", pos); //End of shader type declaration line
			size_t begin = pos + typeTokenLength + 1; //Start of shader type name (after "#type " keyword)
			std::string type = source.substr(begin, eol - begin);

			size_t nextLinePos = source.find_first_not_of("\r\n", eol); //Start of shader code after shader type declaration line
			pos = source.find(typeToken, nextLinePos); //Start of next shader type declaration line

			shaderSources[ShaderTypeFromString(type)] = (pos == std::string::npos) ? source.substr(nextLinePos) : source.substr(nextLinePos, pos - nextLinePos);
		}
		return shaderSources;
	}
	void OpenGLShader::Compile(const std::unordered_map<GLenum, std::string>& shaderSources)
	{
		GLuint program = glCreateProgram();
		std::array<GLenum, 2> glShaderIDs;
		int glShaderIDIndex = 0;
		for (auto& kv : shaderSources)
		{
			GLenum type = kv.first;
			const std::string& source = kv.second;

			GLuint shader = glCreateShader(type);
			const GLchar* sourceCStr = source.c_str();
			glShaderSource(shader, 1, &sourceCStr, 0);
			glCompileShader(shader);

			GLint isCompiled = 0;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar> infoLog(maxLength);
				glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

				glDeleteShader(shader);

				std::cout << infoLog.data();
				std::cout << "Shader compilation failure!";
				break;
			}

			glAttachShader(program, shader);
			glShaderIDs[glShaderIDIndex++] = shader;
		}

		m_RendererID = program;

		// Link our program
		glLinkProgram(program);

		// Note the different functions here: glGetProgram* instead of glGetShader*.
		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

			// We don't need the program anymore.
			glDeleteProgram(program);

			for (auto id : glShaderIDs)
				glDeleteShader(id);

			std::cout << infoLog.data();
			std::cout << "Shader link failure!";
			return;
		}

		for (auto id : glShaderIDs)
		{
			glDetachShader(program, id);
			glDeleteShader(id);
		}
	}
}