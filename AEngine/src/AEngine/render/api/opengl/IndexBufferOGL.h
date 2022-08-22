#pragma once
#include "BufferOGL.h"

#include "AEngine/render/api/ae/IndexBuffer.h"

namespace AEngine {
    class IndexBufferOGL : public IndexBuffer, public BufferOGL {
        public:
            IndexBufferOGL(void* verticies, uint32_t size);
            ~IndexBufferOGL() override;
            void          bind() const override;
            void          unBind() const override;
            void          addData() override;
            void          destroy() override;
            void          setBufferLayout(const BufferLayout& _layout) override;
            BufferLayout& getLayout() override;
    };
}
