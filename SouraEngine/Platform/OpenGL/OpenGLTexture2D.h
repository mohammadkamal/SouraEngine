#pragma once
#include "Renderer/Texture2D.h"

namespace SouraEngine
{
	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D() = default;
		OpenGLTexture2D(const std::string& path);
		virtual ~OpenGLTexture2D();

		/*
		virtual uint32_t GetWidth() const override;
		virtual uint32_t GetHeight() const override;
		virtual uint32_t GetRendererID() const override;
		*/

		//virtual void SetData(void* data, uint32_t size) override;

		virtual void Bind(uint32_t slot) override;

	private:
		std::string m_Path;
		uint32_t m_Width, m_Height, m_RendererID;
	};
}