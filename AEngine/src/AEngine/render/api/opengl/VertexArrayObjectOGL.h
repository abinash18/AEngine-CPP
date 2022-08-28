#pragma once
#include "AEngine/render/api/ae/VertexArrayObject.h"

namespace AEngine {
    class VertexArrayObjectOGL : public VertexArrayObject {
        public:
            VertexArrayObjectOGL();
            virtual      ~VertexArrayObjectOGL() override;
            virtual void bind() const override;
            virtual void unBind() const override;
            virtual void addVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;
            virtual void addIndexBuffer(const std::shared_ptr<IndexBuffer>& vertexBuffer) override;

            virtual const std::vector<std::shared_ptr<VertexBuffer>>& getVbs() const override {
                return vbs;
            }

            //virtual const std::vector<std::shared_ptr<IndexBuffer>>&  getIbs() const override { return ibs; }
            virtual const std::shared_ptr<IndexBuffer>& getIbs() const override {
                return ibs;
            }

        private:
            std::vector<std::shared_ptr<VertexBuffer>> vbs;
            //std::vector<std::shared_ptr<IndexBuffer>>  ibs;
            std::shared_ptr<IndexBuffer> ibs;
            uint32_t                     id;
    };
}
