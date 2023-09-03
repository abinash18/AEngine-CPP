#pragma once
#include "BufferOGL.h"

#include "AEngine/render/api/ae/IndexBuffer.h"

namespace AEngine {
    class IndexBufferOGL : public IndexBuffer, public BufferOGL {
        public:
            IndexBufferOGL(void* verticies, uint32_t size, uint32_t _count);
            ~IndexBufferOGL() override;
            virtual void          bind() const override;
            virtual void          unBind() const override;
            virtual void          destroy() override;
            virtual void          setBufferLayout(const BufferLayout& _layout) override;
            virtual BufferLayout& getLayout() override;

            virtual uint32_t getCount() const override {
                return count;
            }

        private:
            uint32_t count;
    };
}
