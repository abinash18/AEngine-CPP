#pragma once

#include "AEngine/core/Core.h"

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
            virtual ~Input();

            virtual void initInput() = 0;

            virtual void update() = 0;

    };
}
