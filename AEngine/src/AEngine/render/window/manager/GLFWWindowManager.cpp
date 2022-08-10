#include <aepch.h>

#include "GLFWWindowManager.h"

#include "AEngine/render/window/Window.h"

#include "GLFW/glfw3.h"

namespace AEngine {

	GLFWWindowManager::GLFWWindowManager(CoreEngine* controller) : WindowManager() {
		this->controler = controller;
		windows         = {};
	};

	GLFWWindowManager::~GLFWWindowManager() {
		//delete the windows inside the map first since they are pointers.
		for (auto itr = windows.begin(); itr != windows.end(); ++itr) {
			Window* wnd = *itr;
			delete wnd;
			itr = windows.erase(itr); // get the new iterator after deleting the element.
		}
		//windows.clear();
	}

	void GLFWWindowManager::render() {
		for (auto wnd : windows) {
			setContext(wnd);
			wnd->render();
		}
	}

	/**
	 * @brief This function updates the state of the windows this manager has.
	 * It also checks if the window is requested to close because it is the first function called in the main game loop. 
	 * @param delta change in time.
	*/
	void GLFWWindowManager::update(float delta) {
		Window* wnd;
		for (auto itr = windows.begin(); itr != windows.end(); itr++) {
			wnd = *itr;
			//for (auto wnd : windows) {
			setContext(wnd);
			if (wnd->isCloseRequested()) {
				delete wnd;
				itr = windows.erase(itr);
				if (itr == windows.end()) {
					//If the list is empty then raise the stop flag.
					//TODO: implement a engine hint weather or not to stop the engine once all windows are closed.
					raiseEngineStopFlag();
					break;
				}
			} else {
				wnd->update(delta);
			}
		}
		//setContext(NULL);

	}

	void GLFWWindowManager::input(float delta) {
		/*for (auto itr = windows.begin(); itr != windows.end(); ++itr) {
			Window* wnd = itr->second;*/
		for (auto wnd : windows) {
			// Since this is a pointer the window pointer will be deleted if it is closed.
			setContext(wnd);
			wnd->input(delta);
		}
		//setContext(NULL);
	}

	void GLFWWindowManager::openWindow(std::string id, Window* wnd) {
		//if (!windows.) {
		windows.push_back(wnd);
		wnd->create();
		//}
	}

	bool GLFWWindowManager::isEngineStopFlagRaised() const {
		return ENGINE_STOP_FLAG;
	}

	void GLFWWindowManager::raiseEngineStopFlag() {
		ENGINE_STOP_FLAG = true;
	}

	void GLFWWindowManager::setErrorCallback(void* errorCallback) {
		glfwSetErrorCallback(*(GLFWerrorfun) errorCallback);
	}

	void GLFWWindowManager::setContext(Window* wnd) {
		glfwMakeContextCurrent((GLFWwindow*) wnd->getWindowHandle());
	}


}
