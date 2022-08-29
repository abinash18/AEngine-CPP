#pragma once

#include "Input.h"

namespace AEngine {

    /**
     * @brief Input is set by the window class,
    */
    class AE_API GLFWMouseAndKeyboardInput : public Input {
        public:
            GLFWMouseAndKeyboardInput();
            ~GLFWMouseAndKeyboardInput() override;

            bool         isKeyDown(int key) const;
            bool         isKeyUp(int key) const;
            bool         isKeyHeld(int key) const;
            bool         isMouseGrabbedAndHidden() const;
            bool         isMouseHidden() const;
            bool         isCursorInWindow() const;
            float        getMouseX() const;
            float        getMouseY() const;
            float        getScrollOffsetX() const;
            float        getScrollOffsetY() const;
            float        getMouseX1() const;
            void         setMouseX(float mouse_x);
            float        getMouseY1() const;
            void         setMouseY(float mouse_y);
            virtual void update() override;
            virtual void initInput() override;

            void setKeyDown(int key);
            void setKeyUp(int key);

            void setMouseButtonDown(int btn);
            void setMouseButtonUp(int btn);

            void setScrollOffsetX(float scroll_offset_x);
            void setScrollOffsetY(float scroll_offset_y);

        private:
            std::set<int> keysDown;

            /**
             * @brief Keys held will only clear if the key is lifted,
             * therefore once the user presses a key it will be added to this set,
             * and it will only be removed if the key is released.
            */
            std::set<int> keysHeldDown;
            std::set<int> mouseButtonsHeldDown;

            std::set<int> keysUp;
            std::set<int> mouseButtonsDown;
            std::set<int> mouseButtonsUp;

            bool  mouseGrabbedAndHidden;
            bool  mouseHidden;
            bool  cursorInWindow;
            float mouseX;
            float mouseY;
            float scrollOffsetX;
            float scrollOffsetY;
    };
}
