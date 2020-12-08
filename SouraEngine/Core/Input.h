#pragma once

namespace SouraEngine
{
	class Input
	{
	public:
		static bool isKeyPressed();

		static bool isMouseButtonPressed();
		static float GetMousePositionX();
		static float GetMousePositionY();
	};
}