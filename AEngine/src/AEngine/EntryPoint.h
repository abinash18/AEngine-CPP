#pragma once

#ifdef AE_PLATFORM_WINDOWS

/**
 *
 * External method defined in EntryPoint.h
 */
extern AEngine::Application* AEngine::createApplication();

/**
 *
 *	Entry point to the engine.
 *	@returns exit code.
 */
int main(int argc, char** argv) {
	AEngine::Log::Init();
	AE_CORE_CRITICAL("Initialized Logger");
	AE_INFO("Initialized Logger");
	auto app = AEngine::createApplication();
	app->run();
	delete app;
}
#endif // AE_PLATFORM_WINDOWS
