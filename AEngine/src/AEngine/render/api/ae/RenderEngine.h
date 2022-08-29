#pragma once
#include "RenderAPI.h"
#include "RendererAPI.h"

#include "AEngine/render/shader/Shader.h"

namespace AEngine {
    class RenderEngine {
        public:
            RenderEngine();

            virtual ~RenderEngine();
            /*virtual void init() = 0;
            virtual void render() = 0;
            virtual void update() = 0;*/
            virtual void init();
            virtual void render();
            virtual void update();
            virtual void submit(const std::shared_ptr<VertexArrayObject>& vertexArray);

            static RenderAPI getAPI() {
                return s_render_api;
            };

        private:
            static RenderAPI s_render_api;
            RendererAPI*     renderer = nullptr;

            unsigned int                       vertexArrayBuffer;
            std::shared_ptr<VertexArrayObject> vao;
            std::shared_ptr<VertexBuffer>      vertexBuffer;
            std::shared_ptr<IndexBuffer>       indexBuffer;
            std::unique_ptr<Shader>            shader;
            std::unique_ptr<Shader>            squareShader;
            std::shared_ptr<VertexArrayObject> squareVAO;
    };
}
