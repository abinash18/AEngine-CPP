#pragma once
#include "AEngine/LayerStack.h"
#include "AEngine/window/Window.h"
#include "AEngine/EventHandling/ApplicationEvent.h"
#include "AEngine/window/GLFWWindowManager.h"

namespace AEngine {
	class AE_API CoreEngine {
		public:
			CoreEngine();
			~CoreEngine();
			void start();
			void initGLFW();
			bool isRunning();
			void run();
			void stop();
			void cleanUp();
			void exit();
			void OnEvent(Event& e);
			bool OnWindowClose(WindowCloseEvent& e);

			void addLayer(Layer* lyr);
			void addOverlay(Layer* ovr);
		private:
			bool              m_running = false;
			Window*           m_window;
			GLFWWindowManager m_manager;
			LayerStack        m_layers;
			double            m_frameTime      = 1.0 / 60.0;
			bool              isCloseRequested = false;
	};
}
