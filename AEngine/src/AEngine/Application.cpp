#include "aepch.h"
#include "Application.h"

#include "Log.h"

#include "EventHandling/ApplicationEvent.h"

namespace AEngine {
	Application::Application() { };

	Application::~Application() { };

	void Application::run() {

		WindowResizeEvent event(200, 200);
		AE_TRACE(event);
		AE_INFO("asd");
		while (true) {};
	}
}
