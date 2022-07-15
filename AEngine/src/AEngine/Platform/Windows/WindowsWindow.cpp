#include "aepch.h"
#include "WindowsWindow.h"

#include "AEngine/Log.h"
#include "AEngine/EventHandling/ApplicationEvent.h"
#include "AEngine/EventHandling/MouseEvent.h"
#include "AEngine/EventHandling/KeyEvent.h"

namespace AEngine {
	static bool GLFWInitialized = false;

	static void GLFWErrorCallback(int error_code, const char* description) {
		AE_CORE_ERROR("GLFW Error ({0}): {1}", error_code, description);
	}

	Window* Window::Create(const WindowProperties& props) { return new WindowsWindow(props); }
	WindowsWindow::WindowsWindow(const WindowProperties& properties) { init(properties); }

	WindowsWindow::~WindowsWindow() { close(); }

	void WindowsWindow::init(const WindowProperties& properties) {
		m_data.title  = properties.title;
		m_data.width  = properties.width;
		m_data.height = properties.height;

		AE_CORE_INFO("Creating window {0} ({1}, {2})", properties.title, properties.width, properties.height);

		// Right now this is being done per window in future this needs to be done either at engine init or window manager init.
		if (!GLFWInitialized) {
			int success = glfwInit();
			AE_CORE_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)properties.width, (int)properties.height, m_data.title.c_str(), nullptr,
									nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_data);
		setVSync(true);

		// Set GLFW Callbacks
		// TODO : make a seperate function to set these

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			WindowData& d = *(WindowData*)glfwGetWindowUserPointer(window);
			d.width       = width;
			d.height      = height;
			WindowResizeEvent e(width, height);
			d.set_event_callback(e);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			WindowData&      d = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent e;
			d.set_event_callback(e);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& d = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action) {
				case GLFW_PRESS: {
					KeyPressedEvent e(key, 0);
					d.set_event_callback(e);
					break;
				}
				case GLFW_RELEASE: {
					KeyReleasedEvent e(key);
					d.set_event_callback(e);
					break;
				}
				case GLFW_REPEAT: {
					KeyPressedEvent e(key, 1);
					d.set_event_callback(e);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& d = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action) {
				case GLFW_PRESS: {
					MouseButtonPressedEvent e(button);
					d.set_event_callback(e);
					break;
				}
				case GLFW_RELEASE: {
					MouseButtonReleasedEvent e(button);
					d.set_event_callback(e);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset) {
			WindowData& d = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent e((float)xoffset, (float)yoffset);
			d.set_event_callback(e);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos) {
			WindowData&     d = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent e((float)xpos, (float)ypos);
			d.set_event_callback(e);
		});
	};


	void WindowsWindow::close() { glfwDestroyWindow(m_Window); }

	void WindowsWindow::update() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::setVSync(bool enabled) {
		if (enabled) { glfwSwapInterval(1); } else { glfwSwapInterval(0); }
		m_data.vSync = enabled;
	}


	bool WindowsWindow::isVSync() const { return m_data.vSync; }


}
