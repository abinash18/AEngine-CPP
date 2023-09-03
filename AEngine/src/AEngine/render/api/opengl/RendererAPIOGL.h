#pragma once
#include "AEngine/render/api/ae/IndexBuffer.h"
#include "AEngine/render/api/ae/RendererAPI.h"
#include "AEngine/render/api/ae/VertexArrayObject.h"
#include "AEngine/render/api/ae/VertexBuffer.h"
#include "AEngine/render/shader/Shader.h"

namespace AEngine {
    class RendererAPIOGL : public RendererAPI {
        public:
            RendererAPIOGL();
            ~RendererAPIOGL() override;
            virtual void printAPIInfo() override;
            //void render() override;
            //void update() override;
            virtual void drawIndexed(const std::shared_ptr<VertexArrayObject>& vao) override;
            virtual void initAPI() override;
            virtual void SetClearColor(const glm::vec4& color) override;
            virtual void Clear() override;
            //void init();
        private:
            /*unsigned int                       vertexArrayBuffer;
            std::shared_ptr<VertexArrayObject> vao;
            std::shared_ptr<VertexBuffer>      vertexBuffer;
            std::shared_ptr<IndexBuffer>       indexBuffer;
            std::unique_ptr<Shader>            shader;
            std::unique_ptr<Shader>            squareShader;
            std::shared_ptr<VertexArrayObject> squareVAO;*/

    };
}
