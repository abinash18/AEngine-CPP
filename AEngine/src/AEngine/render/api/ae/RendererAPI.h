#pragma once
#include <glm/vec4.hpp>

#include "RenderAPI.h"
#include "VertexArrayObject.h"

namespace AEngine {
    class RendererAPI {
        public:
            RendererAPI() {};
            virtual      ~RendererAPI() {};
            virtual void drawIndexed(const std::shared_ptr<VertexArrayObject>& vao) = 0;
            virtual void printAPIInfo() = 0;
            virtual void initAPI() = 0;
            virtual void SetClearColor(const glm::vec4& color) = 0;
            virtual void Clear() = 0;

            /**
             * @brief Uses the value set in the render engine to return a graphics api.
             * @return 
            */
            static RendererAPI* create();
    };
}
