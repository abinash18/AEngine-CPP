#pragma once
#include "BufferOGL.h"

#include "AEngine/render/api/ae/VertexBuffer.h"

namespace AEngine {
    class VertexBufferOGL : public VertexBuffer, public BufferOGL {
        public:
            VertexBufferOGL(void* verts, uint32_t size);
            ~VertexBufferOGL() override;
            void          bind() const override;
            void          destroy() override;
            void          unBind() const override;
            void          addData() override;
            void          setBufferLayout(const BufferLayout& _layout) override;
            BufferLayout& getLayout() override;
        private:
            uint32_t id;
    };
}
