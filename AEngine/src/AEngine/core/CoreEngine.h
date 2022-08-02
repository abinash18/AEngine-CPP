#pragma once
#include "AEngine/LayerStack.h"
#include "AEngine/render/window/Window.h"
#include "AEngine/input/event/WindowEvent.h"
#include "AEngine/render/window/GLFWWindowManager.h"

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

			void setFramerateUncapped(bool cap) {
				m_isFramerateUncapped = true;
			}

			bool isFramerateUncapped() {
				return m_isFramerateUncapped;
			}

			Window*            m_window;
			static CoreEngine* s_instance;
		private:
			bool   m_running             = false;
			double m_frameTime           = 1.0 / 60.0;
			bool   m_isCloseRequested    = false;
			bool   m_isFramerateUncapped = false;

			GLFWWindowManager m_manager;
			LayerStack        m_layers;

	};
}
