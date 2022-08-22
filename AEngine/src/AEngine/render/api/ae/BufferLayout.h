#pragma once
#include "BufferElement.h"

namespace AEngine {
    class BufferLayout {
        public:
            BufferLayout() {};
            BufferLayout(const std::initializer_list<BufferElement>& _elements);

            const std::vector<BufferElement>& getElements() const { return elements; }
            uint32_t                          getStride() const { return stride; }
        private:
            void calculateLayout();

            std::vector<BufferElement> elements;
            uint32_t                   stride = 0;
    };
}
