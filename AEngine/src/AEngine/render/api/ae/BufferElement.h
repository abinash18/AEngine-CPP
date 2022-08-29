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

        BufferElement() { };


        BufferElement(AEDataType _type, const std::string& _name, bool _normalized = false)
            : name(_name), type(_type),
              size(AETypeSize(type)), offset(0), normalized(_normalized) { }
    };
}
