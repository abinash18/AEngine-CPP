#pragma once

#include "aepch.h"

#include "AEngine/LayerStack.h"
#include "AEngine/core/Core.h"
#include "AEngine/input/Input.h"
#include "AEngine/input/event/Event.h"

namespace AEngine {
    class AE_API Window {
        public:
            using event_callback_fn = std::function<void(Event&)>;

            virtual      ~Window() { };
            virtual void update(float delta) = 0;
            virtual void swapbuffers() = 0;
            virtual void input(float delta) = 0;

            virtual void render() = 0;

            // Used to request close
            virtual void requestClose() = 0;

            virtual bool isCloseRequested() = 0;

            virtual void destroy() = 0;

            /**
             * Getters and setters
             */
            virtual void*        getWindowHandle() = 0;
            virtual unsigned int getWidth() const = 0;
            virtual unsigned int getHeight() const = 0;
            virtual void         setEventCallback(const event_callback_fn& callback) = 0;
            virtual void         setVSync(bool enabled) = 0;
            virtual bool         isVSync() const = 0;
            virtual LayerStack&  getLayerStack() = 0;
            virtual void         postInit() = 0;
            virtual void         preInit() = 0;

            virtual Window* create() = 0;

    };
}
