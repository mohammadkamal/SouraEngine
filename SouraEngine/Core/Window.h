#pragma once
#include <string>
#include "Renderer/GraphicsContext.h"

namespace SouraEngine
{
	struct WindowProperties
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProperties(const std::string& title = "Soura Engine",
			uint32_t width = 1280,
			uint32_t height = 720)
			:Title(title), Width(width), Height(height)
		{}
	};

	class Window
	{
	public:
		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static std::unique_ptr<Window> Create(const WindowProperties& props = WindowProperties());

	};
}