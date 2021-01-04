#pragma once
#include "KeyCodes.h"
#include "MouseCodes.h"
#include <Math/Vector2.h>

namespace SouraEngine
{
	class Input
	{
	public:
		static bool isKeyPressed(KeyCode key);

		static bool isMouseButtonPressed(MouseCode button);
		static Reyadhah::Vector2 GetMousePosition();
		static float GetMousePositionX();
		static float GetMousePositionY();
	};
}