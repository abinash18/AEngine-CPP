#pragma once
#include "Buffer.h"

namespace AEngine {
    class VertexBuffer : public Buffer {
        public:
            virtual              ~VertexBuffer() override = default;
            static VertexBuffer* create(void* verticies, uint32_t size);
    };
}
