/*****************************************************************/ /**
 * \file   Application.h
 * \brief  Super class for AEngine Applications.
 *
 * \author abina
 * \date   July 2021
 *********************************************************************/
#pragma once
#include "Core.h"
#include "window/Window.h"

#include "EventHandling/ApplicationEvent.h"
#include "AEngine/EventHandling/Event.h"
#include "AEngine/LayerStack.h"

namespace AEngine {
	class AE_API Application {
		public:
			Application();
			virtual ~Application();

			void run();

			void OnEvent(Event& e);

			void pushLayer(Layer* layer);
			void pushOverlay(Layer* overlay);
		private:
			bool                    OnWindowClose(WindowCloseEvent& e);
			std::unique_ptr<Window> m_Window;
			bool                    m_running = true;
			LayerStack              layerStack;
	};

	/**
	 *
	 *	This method returns a new User Extended Application.
	 *	This is a abstract method.
	 *	@returns AEngine::Application pointer.
	 */
	Application* createApplication();
}
