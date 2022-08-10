#include <AEngine.h>

int main(int argc, char** argv) {
	AEngine::Log::Init();
	AE_CRITICAL("Initialized Logger");
	auto engine = new AEngine::CoreEngine();
	engine->addOverlay(new AEngine::ImGUILayer());
	engine->start();
	delete engine;
	//auto app = AEngine::createApplication();
	//app->run();
	//delete app;
}
