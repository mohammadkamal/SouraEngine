#include <iostream>
#include "Core/Application.h"
#include "Editor.h"

int main()
{
	SouraEngine::Application::Get().Run();
	Moharrer::Editor::Get().OnUpdate();
}