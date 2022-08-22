#pragma once
#include "AEngine/render/RenderEngine.h"
#include "AEngine/render/shader/Shader.h"
#include "AEngine/render/api/ae/VertexBuffer.h"
#include "AEngine/render/api/ae/IndexBuffer.h"

namespace AEngine {
    class RenderEngineOGL : public RenderEngine {
        public:
            RenderEngineOGL();
            ~RenderEngineOGL();
            void printAPIInfo() override;
            void render() override;
            void update() override;
            void init() override;
        private:
            unsigned int            vertexArrayBuffer;
            VertexBuffer*           vertexBuffer;
            IndexBuffer*            indexBuffer;
            std::unique_ptr<Shader> shader;
    };
}
