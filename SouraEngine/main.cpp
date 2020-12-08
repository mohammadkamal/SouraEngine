#include "Renderer/Renderer2D.h"

int main()
{
	std::unique_ptr<SouraEngine::Renderer2D> renderer2D;
	renderer2D = std::make_unique<SouraEngine::Renderer2D>();

	renderer2D->Init();

	while (true)
	{
		renderer2D->OnUpdate();
	}
	renderer2D->Shutdown();

	return 0;
}