#include "aepch.h"
#include "VertexBuffer.h"

#include "AEngine/render/api/ae/RenderEngine.h"

#include "AEngine/render/api/opengl/VertexBufferOGL.h"

namespace AEngine {
    VertexBuffer* VertexBuffer::create(void* verticies, uint32_t size) {
        switch (RenderEngine::getAPI()) {
            case RenderAPI::NONE: {
                AE_CORE_ASSERT(false, "RenderAPI::NONE not supported");
                return nullptr;
            }
            case RenderAPI::OPEN_GL: { return new VertexBufferOGL(verticies, size); }
        }

        AE_CORE_ASSERT(false, "Invalid RenderAPI");
        return nullptr;
    }
}
