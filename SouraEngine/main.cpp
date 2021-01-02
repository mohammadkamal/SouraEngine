#include "Renderer/Renderer2D.h"


SouraEngine::Renderer2D g_Renderer2D;

int main()
{
	//std::unique_ptr<SouraEngine::Renderer2D> renderer2D;
	//renderer2D = std::make_unique<SouraEngine::Renderer2D>();

	//renderer2D->Init();
	//SouraEngine::Renderer2D::get().Init();
	g_Renderer2D.Init();

	while (true)
	{
		//renderer2D->OnUpdate();
		//SouraEngine::Renderer2D::get().OnUpdate();
		g_Renderer2D.OnUpdate();
	}
	//renderer2D->Shutdown();
	//SouraEngine::Renderer2D::get().Shutdown();
	g_Renderer2D.Shutdown();

	return 0;
}