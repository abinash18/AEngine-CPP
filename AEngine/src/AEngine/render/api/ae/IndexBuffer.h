#pragma once
#include "Buffer.h"

namespace AEngine {
    class IndexBuffer : public Buffer {
        public:
            virtual      ~IndexBuffer() override = default;
            virtual void addData() = 0;
            //virtual void        bind() const override;
            //virtual void        unBind() const override;
            static IndexBuffer* create(void* verticies, uint32_t size);
    };

}
