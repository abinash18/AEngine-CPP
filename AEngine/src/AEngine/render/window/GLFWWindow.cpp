#include "aepch.h"
#include "GLFWWindow.h"

#include "AEngine/Log.h"

#include <glad/glad.h>

#include "AEngine/input/event/WindowEvent.h"
#include "AEngine/input/event/KeyEvent.h"
#include "AEngine/input/event/MouseEvent.h"

namespace AEngine {
	GLFWWindow::GLFWWindow() {
	}

	GLFWWindow::GLFWWindow(const GLFWWindowProperties& properties) {
	}

	GLFWWindow::~GLFWWindow() {
		AE_CORE_INFO("DESTROYING WINDOW {0}", properties.title);
		requestClose();
	}

	Window* GLFWWindow::create() {
		AE_CORE_INFO("Creating window {0} ({1}, {2})", properties.title, properties.sc_width, properties.sc_height);
		resetToDefaults();

		if (properties.prefered_monitor == NULL) {
			properties.prefered_monitor = (int*) glfwGetPrimaryMonitor();
		}

		current_monitor = (GLFWmonitor*) properties.prefered_monitor;
		int* mon        = properties.prefered_monitor;

		video_mode           = glfwGetVideoMode(current_monitor);
		current_refresh_rate = video_mode->refreshRate;

		addGLFWWindowHint(GLFW_REFRESH_RATE,
						  properties.preferred_refresh_rate);

		addGLFWWindowHint(GLFW_VISIBLE,
						  !properties.start_hidden);

		preInit();

		// This is done because creating a window defaults to full screen and if the
		// user wants it full screen it will be, other wise we can change it like so and
		// then move the window to the proper monitor later.
		if (!properties.fullscreen) {
			mon = NULL;
		}

		// Create Window.
		glfw_handle = glfwCreateWindow((int) properties.sc_width,
									   (int) properties.sc_height,
									   properties.title.c_str(), // title
									   (GLFWmonitor*) mon,
									   nullptr);
		glfwMakeContextCurrent(glfw_handle);

		// Load gl functions in this context.
		int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
		AE_CORE_ASSERT(status, "Failed GLAD Initialization");

		glfwSetWindowUserPointer(glfw_handle, &properties);

		// Set GLFW Callbacks
		setCallbacks();

		// Do tasks that require window handle.
		setWindowSizeLimits();

		postInit();

		return this;
	}

	void GLFWWindow::addGLFWWindowHint(int hint, int value) {
		glfwWindowHint(hint, value);
	}

	void GLFWWindow::addGLFWWindowAttrib(int attrib, int value) {
		glfwSetWindowAttrib(glfw_handle, attrib, value);
	}

	int GLFWWindow::getGLFWWindowAttrib(int attrib) {
		return glfwGetWindowAttrib(glfw_handle, attrib);
	}


	void GLFWWindow::resetToDefaults() {
		glfwDefaultWindowHints();
	}

	void GLFWWindow::setWindowSizeLimits(int min_width, int min_height,
										 int max_width, int max_height) {
		properties.min_width  = min_width;
		properties.min_height = min_height;
		properties.max_width  = max_width;
		properties.max_height = max_height;

		glfwSetWindowSizeLimits(glfw_handle,
								min_width, min_height,
								max_width, max_height);
	}

	void GLFWWindow::setWindowSizeLimits() {
		glfwSetWindowSizeLimits(glfw_handle,
								properties.min_width, properties.min_height,
								properties.max_width, properties.max_height);
	}

	void GLFWWindow::getWindowContentScale(float* x_scale, float* y_scale) {
		glfwGetWindowContentScale(glfw_handle, x_scale, y_scale);
	}

	void GLFWWindow::swapbuffers() {
		glfwSwapBuffers(glfw_handle);
	}

	void GLFWWindow::input() {
		glfwPollEvents();
		// sceneManager.input()
	}

	void GLFWWindow::update() {
		// sceneManager.update()
	}

	void GLFWWindow::requestClose() {
		//glfwDestroyWindow(glfw_handle);
		//delete &m_data;
		glfwSetWindowShouldClose(glfw_handle, true);
	}

	bool GLFWWindow::isCloseRequested() {
		return glfwWindowShouldClose(glfw_handle);
	}

	void GLFWWindow::destroy() {
		glfwDestroyWindow(glfw_handle);
	}

	void GLFWWindow::close() {
	}


	void GLFWWindow::setCallbacks() {
		glfwSetWindowSizeCallback(glfw_handle, [] (GLFWwindow* window, int width, int height) {
			GLFWWindowProperties& d = *(GLFWWindowProperties*) glfwGetWindowUserPointer(window);
			d.sc_width              = width;
			d.sc_height             = height;
			WindowResizeEvent e(width, height);
			d.send_event_callback(e);
		});

		glfwSetWindowCloseCallback(glfw_handle, [] (GLFWwindow* window) {
			GLFWWindowProperties& d = *(GLFWWindowProperties*) glfwGetWindowUserPointer(window);
			WindowCloseEvent      e;
			d.send_event_callback(e);
			glfwWindowShouldClose(window);
		});

		glfwSetKeyCallback(glfw_handle, [] (GLFWwindow* window, int key, int scancode, int action, int mods) {
			GLFWWindowProperties& d = *(GLFWWindowProperties*) glfwGetWindowUserPointer(window);

			switch (action) {
				case GLFW_PRESS: {
					KeyPressedEvent e(key, 0);
					d.send_event_callback(e);
					break;
				}
				case GLFW_RELEASE: {
					KeyReleasedEvent e(key);
					d.send_event_callback(e);
					break;
				}
				case GLFW_REPEAT: {
					KeyPressedEvent e(key, 1);
					d.send_event_callback(e);
					break;
				}
			}
		});
		glfwSetCharCallback(glfw_handle, [] (GLFWwindow* window, unsigned int c) {
			GLFWWindowProperties& d = *(GLFWWindowProperties*) glfwGetWindowUserPointer(window);
			KeyTypedEvent         e(c);
			d.send_event_callback(e);

		});

		glfwSetMouseButtonCallback(glfw_handle, [] (GLFWwindow* window, int button, int action, int mods) {
			GLFWWindowProperties& d = *(GLFWWindowProperties*) glfwGetWindowUserPointer(window);

			switch (action) {
				case GLFW_PRESS: {
					MouseButtonPressedEvent e(button);
					d.send_event_callback(e);
					break;
				}
				case GLFW_RELEASE: {
					MouseButtonReleasedEvent e(button);
					d.send_event_callback(e);
					break;
				}
			}
		});

		glfwSetScrollCallback(glfw_handle, [] (GLFWwindow* window, double xoffset, double yoffset) {
			GLFWWindowProperties& d = *(GLFWWindowProperties*) glfwGetWindowUserPointer(window);

			MouseScrolledEvent e((float) xoffset, (float) yoffset);
			d.send_event_callback(e);
		});

		glfwSetCursorPosCallback(glfw_handle, [] (GLFWwindow* window, double xpos, double ypos) {
			GLFWWindowProperties& d = *(GLFWWindowProperties*) glfwGetWindowUserPointer(window);
			MouseMovedEvent       e((float) xpos, (float) ypos);
			d.send_event_callback(e);
		});
	}

	/**
	 * Getters and Setters.
	 */

	void GLFWWindow::setWindowAspectRatio(int width_numerator,
										  int height_denominator) {
		glfwSetWindowAspectRatio(glfw_handle, width_numerator, height_denominator);
	}

	unsigned int GLFWWindow::getWidth() const {
		return properties.sc_width;
	};

	unsigned int GLFWWindow::getHeight() const {
		return properties.sc_height;
	};

	void GLFWWindow::setVSync(bool enabled) {
		if (enabled) {
			glfwSwapInterval(1);
		} else {
			glfwSwapInterval(0);
		}
		properties.vSync = enabled;
	}

	bool GLFWWindow::isVSync() const {
		return properties.vSync;
	}

	int* GLFWWindow::getWindowHandle() {
		return (int*) glfw_handle;
	}

	GLFWWindowProperties* GLFWWindow::getWindowProperties() {
		return &properties;
	}

	int* GLFWWindow::getCurrentMonitor() {
		return nullptr;
	}

	int* GLFWWindow::getCurrentVidMode() {
		return nullptr;
	}

	int GLFWWindow::getCurrentRefreshRate() {
		return 0;
	}

	void GLFWWindow::setEventCallback(const event_callback_fn& callback) {
		properties.send_event_callback = callback;
	};

}
