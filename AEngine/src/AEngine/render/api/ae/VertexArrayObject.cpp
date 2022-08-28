#include "aepch.h"

#include "IndexBuffer.h"
#include "VertexArrayObject.h"
#include "VertexBuffer.h"

#include "AEngine/render/api/ae/RenderEngine.h"
#include "AEngine/render/api/opengl/VertexArrayObjectOGL.h"

namespace AEngine {
    void VertexArrayObject::addVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) { }

    void VertexArrayObject::addIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) { }

    VertexArrayObject* VertexArrayObject::create() {
        switch (RenderEngine::getAPI()) {
            case RenderAPI::NONE: {
                AE_CORE_ASSERT(false, "RenderAPI::NONE not supported");
                return nullptr;
            }
            case RenderAPI::OPEN_GL: { return new VertexArrayObjectOGL(); }
        }

        AE_CORE_ASSERT(false, "Invalid RenderAPI");
        return nullptr;
    }
}
