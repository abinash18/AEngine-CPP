#pragma once
#include <glm/vec4.hpp>

#include "VertexArrayObject.h"

namespace AEngine {

    class RenderWorkflow {
        public:
            

            RenderWorkflow() = default;
            virtual ~RenderWorkflow();
            //virtual void renderScene(Scene scene) = 0;
            //virtual void renderScene(const std::shared_ptr<VertexArrayObject>& vao) = 0;
            virtual void drawIndexed(const std::shared_ptr<VertexArrayObject>& vao) = 0;
            virtual void setClearColor(glm::vec4 color) = 0;
            virtual void setClearColor(float _r, float _g, float _b, float _a) = 0;
            virtual void clear() = 0;

        private:
            
    };

}
