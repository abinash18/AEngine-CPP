#pragma once
#include "Buffer.h"

namespace AEngine {
    class IndexBuffer : public Buffer {
        public:
            ~IndexBuffer() override = default;
            virtual uint32_t    getCount() const = 0;
            static IndexBuffer* create(void* verticies, uint32_t size, uint32_t _count);

    };
}
