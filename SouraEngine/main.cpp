#include "Renderer/Renderer2D.h"

int main()
{
	SouraEngine::Renderer2D::Init();

	while (true)
	{
		SouraEngine::Renderer2D::OnUpdate();
	}
	SouraEngine::Renderer2D::Shutdown();

	return 0;
}