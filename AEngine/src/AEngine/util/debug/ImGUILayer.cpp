#include "aepch.h"
#include "ImGUILayer.h"

#include "AEngine/render/OpenGL3/imgui_impl_opengl3.h"
#include "imgui.h"

#include "AEngine/input/event/WindowEvent.h"
#include "AEngine/input/event/KeyEvent.h"
#include "AEngine/input/event/MouseEvent.h"
#include "AEngine/render/window/GLFW_API_TOKENS.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "AEngine/core/CoreEngine.h"

namespace AEngine {
	ImGUILayer::ImGUILayer() : Layer("ImGUILayer AEngine Debug") {
	}

	ImGUILayer::~ImGUILayer() {
	}

	void ImGUILayer::onAttach() {
		using namespace ImGui;
		CreateContext();
		StyleColorsLight();

		ImGuiIO& io = GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		// TEMPORARY: should eventually use Hazel key codes
		io.KeyMap[ImGuiKey_Tab]        = GLFW_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow]  = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow]    = GLFW_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow]  = GLFW_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp]     = GLFW_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown]   = GLFW_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home]       = GLFW_KEY_HOME;
		io.KeyMap[ImGuiKey_End]        = GLFW_KEY_END;
		io.KeyMap[ImGuiKey_Insert]     = GLFW_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete]     = GLFW_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace]  = GLFW_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space]      = GLFW_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter]      = GLFW_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape]     = GLFW_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_A]          = GLFW_KEY_A;
		io.KeyMap[ImGuiKey_C]          = GLFW_KEY_C;
		io.KeyMap[ImGuiKey_V]          = GLFW_KEY_V;
		io.KeyMap[ImGuiKey_X]          = GLFW_KEY_X;
		io.KeyMap[ImGuiKey_Y]          = GLFW_KEY_Y;
		io.KeyMap[ImGuiKey_Z]          = GLFW_KEY_Z;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGUILayer::onDetach() {
	}

	void ImGUILayer::update() {
		ImGuiIO& io    = ImGui::GetIO();
		io.DisplaySize = ImVec2(CoreEngine::s_instance->m_window->getWidth(),
								CoreEngine::s_instance->m_window->getHeight());
		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();
		float time       = (float) glfwGetTime();
		io.DeltaTime     = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time           = time;
		static bool show = true;

		ImGui::ShowDemoWindow(&show);
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}


	void ImGUILayer::onEvent(Event& event) {
		EventDispatcher dispatcher(event);


		dispatcher.dispatch<MouseButtonPressedEvent>([=] (MouseButtonPressedEvent& _e) {
			return mouseButtonPressed(_e);
		});
		dispatcher.dispatch<MouseButtonReleasedEvent>([=] (MouseButtonReleasedEvent& _e) {
			return mouseButtonReleased(_e);
		});
		dispatcher.dispatch<MouseMovedEvent>([=] (MouseMovedEvent& _e) {
			return mouseMoved(_e);
		});
		dispatcher.dispatch<MouseScrolledEvent>([=] (MouseScrolledEvent& _e) {
			return mouseScrolled(_e);
		});

		dispatcher.dispatch<WindowResizeEvent>([=] (WindowResizeEvent& _e) {
			return windowResize(_e);
		});
		dispatcher.dispatch<KeyPressedEvent>([=] (KeyPressedEvent& _e) {
			return keyPressed(_e);
		});
		dispatcher.dispatch<KeyReleasedEvent>([=] (KeyReleasedEvent& _e) {
			return keyReleased(_e);
		});
		dispatcher.dispatch<KeyTypedEvent>([=] (KeyTypedEvent& _e) {
			return keyTyped(_e);
		});
	}

	bool ImGUILayer::mouseButtonPressed(MouseButtonPressedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();

		io.MouseDown[e.getButton()] = true;

		return false;
	}

	bool ImGUILayer::mouseButtonReleased(MouseButtonReleasedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();

		io.MouseDown[e.getButton()] = false;

		return false;
	}

	bool ImGUILayer::mouseMoved(MouseMovedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();

		io.MousePos = ImVec2(e.getX(), e.getY());

		return false;
	}

	bool ImGUILayer::mouseScrolled(MouseScrolledEvent& e) {
		ImGuiIO& io = ImGui::GetIO();

		io.MouseWheel += e.getYOffset();
		io.MouseWheelH += e.getXOffset();
		return false;
	}

	bool ImGUILayer::windowResize(WindowResizeEvent& e) {
		ImGuiIO& io                = ImGui::GetIO();
		io.DisplaySize             = ImVec2(e.getWidth(), e.getHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, (GLsizei) e.getWidth(), (GLsizei) e.getHeight());
		AE_CORE_CRITICAL(e);
		return false;
	}

	bool ImGUILayer::keyPressed(KeyPressedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();

		io.KeysDown[e.GetKeyCode()] = true;
		io.KeyCtrl                  = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
		io.KeyShift                 = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
		io.KeyAlt                   = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
		io.KeySuper                 = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
		return false;
	}

	bool ImGUILayer::keyReleased(KeyReleasedEvent& e) {
		return false;
	}

	bool ImGUILayer::keyTyped(KeyTypedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		int      c  = e.GetKeyCode();
		if (c > 0 && c < 0x10000) {
			io.AddInputCharacter((unsigned short) c);
		}

		return false;
	}

}
