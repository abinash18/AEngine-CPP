/*****************************************************************/ /**
 * \file   Application.h
 * \brief  Super class for AEngine Applications.
 *
 * \author abina
 * \date   July 2021
 *********************************************************************/
#pragma once
#include "Core.h"

namespace AEngine {
	class AE_API Application {
		public:
			Application();
			virtual ~Application();

			void run();

	};

	/**
	 *
	 *	This method returns a new User Extended Application.
	 *	This is a abstract method.
	 *	@returns AEngine::Application pointer.
	 */
	Application* createApplication();
}
