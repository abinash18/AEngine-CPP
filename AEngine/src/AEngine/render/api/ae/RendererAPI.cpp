#include "aepch.h"
#include "RendererAPI.h"
#include "RenderAPI.h"
#include "RenderEngine.h"

#include "AEngine/render/api/opengl/RendererAPIOGL.h"

namespace AEngine {
    RendererAPI* RendererAPI::create() {
        switch (RenderEngine::getAPI()) {
            case RenderAPI::NONE: {
                AE_CORE_ASSERT(false, "RenderAPI::NONE not supported");
                return nullptr;
            }
            case RenderAPI::OPEN_GL: { return new RendererAPIOGL(); }
        }

        AE_CORE_ASSERT(false, "Invalid RenderAPI");
        return nullptr;
    }
}
