#pragma once
#include "AEngine/Layer.h"
#include "AEngine/input/event/WindowEvent.h"
#include "AEngine/input/event/Event.h"
#include "AEngine/input/event/KeyEvent.h"
#include "AEngine/input/event/MouseEvent.h"
#include "AEngine/core/Core.h"

namespace AEngine {
	class AE_API ImGUILayer : public Layer {
		public:
			ImGUILayer();
			~ImGUILayer();

			void attach() override;
			void detach() override;
			void render() override;
			void update(float delta) override;

			void begin();
			void end();

		private:
			float m_Time = 0;
	};
}
