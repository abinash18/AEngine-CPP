/*****************************************************************/ /**
 * \file   Application.h
 * \brief  Super class for AEngine Applications.
 *
 * \author abina
 * \date   July 2021
 *********************************************************************/
#pragma once
#include "Core.h"
#include "Window.h"

#include "EventHandling/ApplicationEvent.h"
#include "EventHandling/Event.h"

namespace AEngine {
	class AE_API Application {
		public:
			Application();
			virtual ~Application();

			void run();

			void OnEvent(Event& e);
		private:
			bool                    OnWindowClose(WindowCloseEvent);
			std::unique_ptr<Window> m_Window;
			bool                    m_running = true;
	};

	/**
	 *
	 *	This method returns a new User Extended Application.
	 *	This is a abstract method.
	 *	@returns AEngine::Application pointer.
	 */
	Application* createApplication();
}
