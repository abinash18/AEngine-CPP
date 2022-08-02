#pragma once
#include "AEngine/Layer.h"
#include "AEngine/input/event/WindowEvent.h"
#include "AEngine/input/event/Event.h"
#include "AEngine/input/event/KeyEvent.h"
#include "AEngine/input/event/MouseEvent.h"

namespace AEngine {
	class AE_API ImGUILayer : public Layer {
		public:
			ImGUILayer();
			~ImGUILayer();

			void onAttach() override;
			void onDetach() override;
			void update() override;
			void onEvent(Event& event) override;

		private:
			bool  mouseButtonPressed(MouseButtonPressedEvent& e);
			bool  mouseButtonReleased(MouseButtonReleasedEvent& e);
			bool  mouseMoved(MouseMovedEvent& e);
			bool  mouseScrolled(MouseScrolledEvent& e);
			bool  windowResize(WindowResizeEvent& e);
			bool  keyPressed(KeyPressedEvent& e);
			bool  keyReleased(KeyReleasedEvent& e);
			bool  keyTyped(KeyTypedEvent& e);
			float m_Time = 0;
	};
}
