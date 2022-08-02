#pragma once

#include "aepch.h"
#include "GLFW_API_TOKENS.h"

namespace AEngine {

	/*
	 * This is a stencil that the Engine will use to 
	 */
	struct GLFWWindowProperties {
		/**
		 * @brief pointers are in int* for now until i find a way to include GLFW in sub projects
		*/
		int* shared_context = 0;
		/**
		 * sc_ is the dimensions of the window in screen coordinates, This is different
		 * than pixels since the positive of the y axis is inverted meaning it points
		 * down instead of up so the 0, 0 of the window is in the top left of the
		 * corner.
		 */
		int sc_width = 1270, sc_height = 720,
			/*
			 * Min and Maximum size limits for the window on the OS,
			 * By default set to un-limited.
			 */
			min_width = GLFW_DONT_CARE, min_height = GLFW_DONT_CARE, max_width = GLFW_DONT_CARE, max_height =
					GLFW_DONT_CARE,
			/* The refresh rate used by VSync */
			preferred_refresh_rate = GLFW_DONT_CARE;
		/**
		 * This option Synchronizes the frames so they render more steadily instead of
		 * dropping and causing lag.
		 */
		int start_hidden = GLFW_FALSE;

		/**
		 * The name is what the engine recognizes and it is used to find the window.
		 */
		std::string name = "AEngine",
					/**
					 * The title to show on the decorated frame and the general title where ever it
					 * is showed.
					 */
					title = "AEngine Window";
		bool fullscreen   = false,
			 /** If the window is currently focused on or not. */
			 focused = true,
			 /** If the window has been minimized to tray (iconified) */
			 minimized = false,
			 /** If the window is maximized or not */
			 maximized = false,
			 vSync     = false;
		/**
		 * GLFW Supports whole window transparency, but only if the system supports it
		 * as well.
		 */
		float opacity = 1.0f;

		/**
		 *	This is a int* to GLFWmonitor*, so the user extended engine dose not have to include GLFW even though it should because reimplementing enums is stupid.
		*/
		int* prefered_monitor = nullptr;

		using event_callback_fn = std::function<void(Event&)>;

		/**
		 * Callbacks
		*/

		event_callback_fn     send_event_callback;
		std::function<void()> monitor_callback;


		/**
		 * @brief  Returned values not set by the user, if they are set they will be overwritten by the engine to the values provided by the OS.
		*/

		/**
		 * @breif The dimensions of the window in pixels this corresponds to the size of the
		 * frame buffer and may not always be the size of the window, since some
		 * displays can have a higher pixel density.
		*/
		int p_width, p_height,
			/**
			 * Stores the size of each of the frame elements, if the window is not decorated
			 * than the value is zero.
			 */
			f_top, f_left, f_right, f_bottom;

		GLFWWindowProperties() {
		}

	};

}
