#pragma once
#include "BufferLayout.h"

namespace AEngine {
    class Buffer {
        public:
            virtual               ~Buffer() = default;
            virtual void          bind() const = 0;
            virtual void          unBind() const = 0;
            virtual void          setBufferLayout(const BufferLayout& _layout) = 0;
            virtual BufferLayout& getLayout() = 0;
            virtual void          destroy() = 0;
    };
}
