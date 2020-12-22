#pragma once
#include "Renderer/RenderCommand.h"

namespace SouraEngine
{
	class OpenGLRenderCommand :public RenderCommand
	{
	public:
		OpenGLRenderCommand() = default;
		virtual void Init() override;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
		virtual void SetClearColor(glm::vec4 color) override;

	};
}