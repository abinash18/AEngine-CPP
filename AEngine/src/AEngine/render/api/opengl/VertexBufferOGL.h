#pragma once
#include "BufferOGL.h"

#include "AEngine/render/api/ae/VertexBuffer.h"

namespace AEngine {
    class VertexBufferOGL : public VertexBuffer, public BufferOGL {
        public:
            VertexBufferOGL(void* verts, uint32_t size);
            ~VertexBufferOGL() override;
            virtual void          bind() const override;
            virtual void          destroy() override;
            virtual void          unBind() const override;
            virtual void          setBufferLayout(const BufferLayout& _layout) override;
            virtual BufferLayout& getLayout() override;
        private:
    };
}
