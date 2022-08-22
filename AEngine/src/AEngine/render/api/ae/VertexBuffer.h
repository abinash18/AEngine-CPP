#pragma once
#include "Buffer.h"

namespace AEngine {
    class VertexBuffer : public Buffer {
        public:
            virtual      ~VertexBuffer() override = default;
            virtual void addData() = 0;
            //virtual void         bind() const override = 0;
            //virtual void         unBind() const override;
            static VertexBuffer* create(void* verticies, uint32_t size);
    };
}
