#pragma once

#include "AEngine/core/Core.h"

#include "input/event/Event.h"

namespace AEngine {
	class AE_API Layer {
		public:
			Layer(const std::string& name = "Layer");


			virtual ~Layer() = 0;

			// since virtual methods are defined as overidable and PURE virtual functions are abstract, here you have to define the methods.
			virtual void onAttach() = 0;

			virtual void onDetach() = 0;

			virtual void update(float delta) {
			}

			virtual void render() = 0;

			virtual void onEvent(Event& event) = 0;

			inline const std::string& getName() const {
				return m_DebugName;
			};
		private:
			std::string m_DebugName;
	};
}
