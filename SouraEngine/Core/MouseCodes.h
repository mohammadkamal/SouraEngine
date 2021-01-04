#pragma once
#include <array>

namespace SouraEngine
{
	typedef enum class MouseCode : uint16_t
	{
		MouseButton0         = 0,
		MouseButton1         = 1,
		MouseButton2         = 2,
		MouseButton3         = 3,
		MouseButton4         = 4,
		MouseButton5         = 5,
		MouseButton6         = 6,
		MouseButton7         = 7,
		MouseButtonLast      = MouseButton7,
		MouseButtonLeft      = MouseButton0,
		MouseButtonRight     = MouseButton1,
		MouseButtonMiddle    = MouseButton2
	};
}