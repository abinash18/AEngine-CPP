#include <aepch.h>
#include "IndexBuffer.h"
#include "AEngine/render/api/ae/RenderEngine.h"

#include "AEngine/render/api/opengl/IndexBufferOGL.h"

namespace AEngine {
    IndexBuffer* IndexBuffer::create(void* verticies, uint32_t size, uint32_t _count) {
        switch (RenderEngine::getAPI()) {
            case RenderAPI::NONE: {
                AE_CORE_ASSERT(false, "RenderAPI::NONE not supported");
                return nullptr;
            }

            case RenderAPI::OPEN_GL: { return new IndexBufferOGL(verticies, size, _count); }
        }

        AE_CORE_ASSERT(false, "Invalid RenderAPI");
        return nullptr;
    }
}
