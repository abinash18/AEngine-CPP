#pragma once

#include "IndexBuffer.h"
#include "VertexBuffer.h"

namespace AEngine {
    class VertexArrayObject {
        public:
            virtual      ~VertexArrayObject() {};
            virtual void bind() const = 0;
            virtual void unBind() const = 0;

            virtual void addVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) = 0;
            virtual void addIndexBuffer(const std::shared_ptr<IndexBuffer>& vertexBuffer) = 0;


            virtual const std::vector<std::shared_ptr<VertexBuffer>>& getVbs() const = 0;
            //virtual const std::vector<std::shared_ptr<IndexBuffer>>&  getIbs() const = 0;
            virtual const std::shared_ptr<IndexBuffer>& getIbs() const = 0;

            static VertexArrayObject* create();
    };
}
