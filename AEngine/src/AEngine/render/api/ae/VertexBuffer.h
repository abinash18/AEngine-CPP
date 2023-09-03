#pragma once
#include "Buffer.h"

namespace AEngine {
    class VertexBuffer : public Buffer {
        public:
            ~VertexBuffer() override = default;
            static VertexBuffer* create(void* verticies, uint32_t size);
    };
}
