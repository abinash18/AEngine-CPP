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
		//AE_CORE_TRACE("{0}", e);

		// Loop over the layer from last to first, since the last layer would be the top of the stack. And poll events on each layer backwards.
		for (auto it = layerStack.end(); it != layerStack.begin();) {
			(*--it)->onEvent(e);
			if (e.handled) {
				// if the current layer captured the event then we dont need to send it to the lower layers.
				break;
			}
		}

	}

	Application::~Application() { };

	void Application::run() {
		while (m_running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : layerStack) {
				layer->update();
			}

			m_Window->update();
		};
	}

	bool Application::OnWindowClose(WindowCloseEvent) {
		m_running = false;
		return true;
	}

	void Application::pushLayer(Layer* layer) {
		layerStack.pushLayer(layer);
	}

	void Application::pushOverlay(Layer* overlay) {
		layerStack.pushOverlay(overlay);
	}


}
