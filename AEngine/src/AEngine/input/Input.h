#pragma once

#include "AEngine/core/Core.h"
#include "AEngine/render/window/Window.h"

namespace AEngine {
	class AE_API Input {
		public:
			/**
			 * @brief Initialize the input with the window handle.
			 */
			Input();

			/**
			 * Delete the input buffers here.
			 */
			~Input();

			virtual void initInput() = 0;

			virtual void update() = 0;

	};
}
