#pragma once
#include "BufferElement.h"

namespace AEngine {
    class BufferLayout {
        public:
            BufferLayout() {};
            BufferLayout(const std::initializer_list<BufferElement>& _elements);

            const std::vector<BufferElement>& getElements() const { return elements; }
            uint32_t                          getStride() const { return stride; }

            std::vector<BufferElement>::iterator       begin() { return elements.begin(); }
            std::vector<BufferElement>::iterator       end() { return elements.end(); }
            std::vector<BufferElement>::const_iterator begin() const { return elements.begin(); }
            std::vector<BufferElement>::const_iterator end() const { return elements.end(); }
        private:
            void calculateLayout();

            std::vector<BufferElement> elements;
            uint32_t                   stride = 0;
    };
}
