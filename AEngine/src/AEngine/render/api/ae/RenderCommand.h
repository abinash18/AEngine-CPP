#pragma once
#include <glm/vec4.hpp>

namespace AEngine {

    class RenderCommand {
        public:
            virtual void setClearColor(glm::vec4 color) = 0;
            virtual void setClearColor(float _r, float _g, float _b, float _a) = 0;
            virtual void clear() = 0;
    };

}
