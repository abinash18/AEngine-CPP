#pragma once

#include "AEngine/Core.h"

#include "input/event/Event.h"

namespace AEngine {
	class AE_API Layer {
		public:
			Layer(const std::string& name = "Layer");


			virtual ~Layer() = 0;

			// since virtual methods are defined as overidable and PURE virtual functions are abstract, here you have to define the methods.
			virtual void onAttach() {
			};

			virtual void onDetach() {
			};

			virtual void update() {
			};

			virtual void onEvent(Event& event) {
			};

			inline const std::string& getName() const {
				return m_DebugName;
			};
		private:
			std::string m_DebugName;
	};
}
