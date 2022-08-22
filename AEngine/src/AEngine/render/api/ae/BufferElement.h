#pragma once
#include "AEDataType.h"

namespace AEngine {
    struct BufferElement {
        std::string name;
        AEDataType  type;
        uint32_t    size;
        uint32_t    offset;
        // weather the data in the element is already normalized.
        bool normalized;

        BufferElement() {
        };

        BufferElement(AEDataType _type, const std::string& _name, bool _normalized = false)
            : type(_type), name(_name),
              normalized(_normalized), size(AETypeSize(type)), offset(0) {
        }
    };
}
