#include "aepch.h"
#include "VertexBufferOGL.h"

#include <glad/glad.h>

namespace AEngine {
    VertexBufferOGL::VertexBufferOGL(void* verts, uint32_t size) {
        glCreateBuffers(1, &id);
        glBindBuffer(GL_ARRAY_BUFFER, id);
        glBufferData(GL_ARRAY_BUFFER, size, verts, GL_STATIC_DRAW);
    }

    VertexBufferOGL::~VertexBufferOGL() {
        BufferOGL::destroy();
    }

    void VertexBufferOGL::bind() const {
        BufferOGL::bind();
    }

    void VertexBufferOGL::destroy() {
        BufferOGL::destroy();
    }

    void VertexBufferOGL::unBind() const {
        BufferOGL::unBind();
    }

    void VertexBufferOGL::setBufferLayout(const BufferLayout& _layout) {
        BufferOGL::setBufferLayout(_layout);
    }

    BufferLayout& VertexBufferOGL::getLayout() {
        return BufferOGL::getLayout();
    }
}
