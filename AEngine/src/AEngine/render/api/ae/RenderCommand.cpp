#include "aepch.h"

#include "RenderCommand.h"

namespace AEngine {
    void RenderCommand::setClearColor(glm::vec4 color) {}
    void RenderCommand::setClearColor(float _r, float _g, float _b, float _a) {}
    void RenderCommand::drawIndexed(const std::shared_ptr<VertexArrayObject>& vao) {}
    void RenderCommand::clear() {}
}
