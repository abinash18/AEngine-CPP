#pragma once
#include "BufferOGL.h"

#include "AEngine/render/api/ae/IndexBuffer.h"

namespace AEngine {
    class IndexBufferOGL : public IndexBuffer, public BufferOGL {
        public:
            IndexBufferOGL(void* verticies, uint32_t size, uint32_t _count);
            ~IndexBufferOGL() override;
            void          bind() const override;
            void          unBind() const override;
            void          destroy() override;
            void          setBufferLayout(const BufferLayout& _layout) override;
            BufferLayout& getLayout() override;
            uint32_t      getCount() const override { return count; }
        private:
            uint32_t count;
    };
}
