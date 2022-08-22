#include <aepch.h>
#include "IndexBuffer.h"
#include "AEngine/render/RenderEngine.h"

#include "AEngine/render/api/opengl/IndexBufferOGL.h"

namespace AEngine {
    IndexBuffer* IndexBuffer::create(void* verticies, uint32_t size) {
        switch (RenderEngine::getAPI()) {
            case RenderAPI::NONE: {
                AE_CORE_ASSERT(false, "RenderAPI::NONE not supported");
                return nullptr;
            }

            case RenderAPI::OPEN_GL: { return new IndexBufferOGL(verticies, size); }
        }

        AE_CORE_ASSERT(false, "Invalid RenderAPI");
        return nullptr;
    }
}
