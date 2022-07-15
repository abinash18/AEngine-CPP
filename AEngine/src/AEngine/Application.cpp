#include "aepch.h"
#include "Application.h"

#include "Log.h"

#include <GLFW/glfw3.h>

namespace AEngine {

	#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)


	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->setEventCallback(BIND_EVENT_FN(OnEvent));
	};

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		AE_CORE_TRACE("{0}", e);
	}

	Application::~Application() { };

	void Application::run() {
		while (m_running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->update();
		};
	}

	bool Application::OnWindowClose(WindowCloseEvent) {
		m_running = false;
		return true;
	}

}
