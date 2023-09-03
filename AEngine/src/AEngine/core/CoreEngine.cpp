#include "aepch.h"
#include "CoreEngine.h"

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include "Time.h"

#include "AEngine/input/event/WindowEvent.h"
#include "AEngine/render/window/GLFWWindow.h"
#include "AEngine/render/window/Window.h"
#include "AEngine/render/window/manager/GLFWWindowManager.h"
#include "AEngine/render/window/models/EngineLoadingWindow.h"

namespace AEngine {

    CoreEngine* CoreEngine::s_instance = nullptr;

    static bool GLFWInitialized = false;
    //#define BIND_EVENT_FN(x) std::bind(&CoreEngine::x, this, std::placeholders::_1)

    static void GLFWErrorCallback(int error_code, const char* description) {
        AE_CORE_ERROR("GLFW Error ({0}): {1}", error_code, description);
    }

    CoreEngine::CoreEngine() {
        m_window_manager = new GLFWWindowManager(this);
        initGLFW();

        s_instance = this;
        //m_window = std::unique_ptr<Window>(Window::create());
        m_window = new EngineLoadingWindow();
        //m_window->create();
        m_window_manager->openWindow("Engine", m_window);
        //m_Window->setEventCallback(BIND_EVENT_FN(OnEvent));
        // TODO: Find a better way to do this idk if this is most efficent.
        m_window->setEventCallback([=] (Event& e) {
            OnEvent(e);
        });
        //m_window->setVSync(false);
        m_frameTime = 1.0 / static_cast<double>(60);
        setFramerateUncapped(true);
        //layerStack = LayerStack();
    };

    CoreEngine::~CoreEngine() {
        //delete m_window;
    };

    void CoreEngine::start() {
        if (m_running) {
            return;
        }
        run();
    };

    bool CoreEngine::isRunning() {
        return m_running;
    }

    bool CoreEngine::OnWindowClose(WindowCloseEvent& e) {
        //m_isCloseRequested = true;
        return true;
    }

    // TODO: Engine should not handle events move to window class
    void CoreEngine::OnEvent(Event& e) {
        //AE_CORE_TRACE("{0}", e);
        // This dispatcher is stupid
        // TODO: Come up with better dispacther without templates (IDK Based fully on callback lamdas).
        EventDispatcher dispatcher(e);
        //dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
        dispatcher.dispatch<WindowCloseEvent>([=] (WindowCloseEvent& _e) {
            return OnWindowClose(_e);
        });


        // Loop over the layer from last to first, since the last layer would be the top of the stack. And poll events on each layer backwards.
        for (auto it = m_window->getLayerStack().end(); it != m_window->getLayerStack().begin();) {
            (*--it)->onEvent(e);
            if (e.handled) {
                // if the current layer captured the event then we dont need to send it to the lower layers.
                break;
            }
        }

    }

    void CoreEngine::run() {
        if (m_running) {
            return;
        }
        m_running = true;

        double lastTime        = getTime(); // Current time at the start of the last frame
        double frameCounter    = 0;         // Total passed time since last frame counter display
        double unprocessedTime = 0;         // Amount of passed time that the engine hasn't accounted for
        int    frames          = 0;         // Number of frames rendered since last
        bool   render;                      // Whether or not the game needs to be rerendered.
        double startTime;
        double passedTime;

        while (m_running) {
            render = false;

            startTime  = getTime();            //Current time at the start of the frame.
            passedTime = startTime - lastTime; //Amount of passed time since last frame.
            lastTime   = startTime;

            unprocessedTime += passedTime;
            frameCounter += passedTime;


            if (frameCounter >= 1.0) {
                AE_CORE_INFO("FRAMES: {0} ; FRAME_TIME: {1}",
                             frames,
                             static_cast<double>(1000) / frames
                             //m_frameTime
                             // The double cast of 1 second over number of frames. How much time each frame takes per 1 second  
                            );
                frames       = 0;
                frameCounter = 0;
            }

            //The engine works on a fixed update system, where each update is 1/frameRate seconds of time.
            //Because of this, there can be a situation where there is, for instance, a fixed update of 16ms, 
            //but 20ms of actual time has passed. To ensure all time is accounted for, all passed time is
            //stored in unprocessedTime, and then the engine processes as much time as it can. Any
            //unaccounted time can then be processed later, since it will remain stored in unprocessedTime.
            while (m_running && (unprocessedTime > m_frameTime)) {
                //Input must be processed here because the window may have found new
                //input events from the OS when it updated. Since inputs can trigger
                //new game actions, the game also needs to be updated immediately 
                //afterwards.

                //if (m_window->isCloseRequested()) {
                if (m_window_manager->isEngineStopFlagRaised()) {
                    stop();
                    break;
                }
                m_window_manager->update(static_cast<float>(m_frameTime));
                m_window_manager->input(static_cast<float>(m_frameTime));
                render = true;

                unprocessedTime -= m_frameTime;
            }

            if (render && m_running) {
                //m_game->Render(m_renderingEngine);
                /*for (Layer* layer : m_layers) {
                    layer->update();
                }*/
                //m_window->swapbuffers();
                m_window_manager->render();
                frames++;
                //m_frameTime = 1.0 / (double) frames;
            } else {
                //If no rendering is needed, sleep for some time so the OS
                //can use the processor for other tasks.
                //if (m_running) {
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                //}
            }
        }
        cleanUp();
    }

    void CoreEngine::addLayer(Layer* lyr) {
        m_window->getLayerStack().pushLayer(lyr);
    }

    void CoreEngine::addOverlay(Layer* ovr) {
        m_window->getLayerStack().pushOverlay(ovr);
    }

    void CoreEngine::cleanUp() {
        delete m_window_manager;
        //delete m_window;
        glfwTerminate();
    }

    void CoreEngine::stop() {
        if (!m_running) {
            return;
        }
        AE_CORE_INFO("STOPPING ENGINE");
        m_running = false;
    }

    void CoreEngine::initGLFW() {
        int success = glfwInit();
        AE_CORE_ASSERT(success, "ERROR INITALIZING GLFW!");
        m_window_manager->setErrorCallback(GLFWErrorCallback);
        //glfwSetErrorCallback((GLFWerrorfun) GLFWErrorCallback);
        GLFWInitialized = true;
        AE_CORE_INFO("INITIALIZED GLFW");
    };


}
