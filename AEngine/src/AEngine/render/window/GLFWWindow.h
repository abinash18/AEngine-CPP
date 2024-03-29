#pragma once

#include <GLFW/glfw3.h>
#include "GLFW_API_TOKENS.h"
#include "AEngine/render/window/GLFWWindowProperties.h"
#include "AEngine/render/window/Window.h"
#include "AEngine/util/Destroyable.h"

#include "AEngine/LayerStack.h"
#include "AEngine/input/GLFWMouseAndKeyboardInput.h"
#include "AEngine/render/api/ae/RenderEngine.h"

#include "AEngine/render/api/opengl/ContextOGL.h"

namespace AEngine {
    class AE_API GLFWWindow : public Window {
        public:
            GLFWWindow();
            GLFWWindow(const GLFWWindowProperties& properties);
            ~GLFWWindow() override;
            virtual void    destroy() override;
            virtual void    update(float delta) override;
            virtual void    setEventCallback(const event_callback_fn& callback) override;
            virtual void    input(float delta) override;
            virtual Window* create() override;

            /**
             * GLFW wrapper functions.
             */
            virtual void swapbuffers() override;
            void         addGLFWWindowHint(int hint, int value);
            void         addGLFWWindowAttrib(int attrib, int value);
            int          getGLFWWindowAttrib(int attrib);
            void         resetToDefaults();
            void         setWindowSizeLimits(int min_width,
                                             int min_height,
                                             int max_width,
                                             int max_height);
            void setWindowSizeLimits();
            void getWindowContentScale(float* x_scale, float* y_scale);

            // Iconify.

            /**
             * @brief This is what the user calls to close the window,
             * this function will request the window manager to close this window at the next update,
             * it sets a close flag. 
            */
            virtual void requestClose() override;

            virtual bool isCloseRequested() override;

            /**
             * @brief The aspect ratio is specified as a numerator and denominator,
             * corresponding to the width and height, respectively.
             * If you want a window to maintain its current aspect ratio,
             * use its current size as the ratio.
             * @param width_numerator 
             * @param height_denominator 
            */
            void setWindowAspectRatio(int width_numerator, int height_denominator);

            /**
             * Getters and Setters.
            */
            virtual unsigned int  getWidth() const override;
            virtual unsigned int  getHeight() const override;
            virtual void          setVSync(bool enabled) override;
            virtual bool          isVSync() const override;
            virtual void*         getWindowHandle() override;
            GLFWWindowProperties* getWindowProperties();
            int*                  getCurrentMonitor();
            int*                  getCurrentVidMode();
            int                   getCurrentRefreshRate();
            void                  setCloseFlag(bool close_flag);
            void                  addLayer(Layer* lyr);
            void                  addOverlay(Layer* ovr);

            bool         checkWindowPointer();
            virtual void render() override;

            virtual LayerStack& getLayerStack() override;
        protected:
            GLFWwindow*  glfw_handle;
            GLFWmonitor* current_monitor;

            RenderContext* context;

            bool CLOSE_FLAG;

            /**
             * @brief vid mode is a const structure so it cannot be modified,
             * therefore its a const pointer.
             */
            const GLFWvidmode* video_mode;
            int                current_refresh_rate;

            // SceneManager
            // InputManager
            // AssetStore
            // AssetManager

            GLFWWindowProperties properties;

            // This is where user will add any pre creation window hints
            virtual void preInit() override { };
            // This is where the user can execute any post creation methods that require context.
            virtual void postInit() override { };

            void onClose() { };
            /**
             * @brief Add a scene to the window's scene manager.
             */
            // virtual void addScene(Scene scene);

            void close(GLFWwindow* window);
            void setCallbacks();

            /**
             * @brief current layer stack for this window.
            */
            LayerStack layerStack;

            RenderEngine* renderengine;
    };
}
