#include <aepch.h>
#include "BufferLayout.h"

namespace AEngine {

    BufferLayout::BufferLayout(const std::initializer_list<BufferElement>& _elements) : elements(_elements) {
        calculateLayout();
    };

    void BufferLayout::calculateLayout() {
        uint32_t _offset = 0;
        stride           = 0;
        for (auto& _element : elements) {
            _element.offset = _offset;
            _offset += _element.size;
            stride += _element.size;
        }
    }
}
