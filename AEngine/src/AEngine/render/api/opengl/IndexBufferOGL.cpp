#include <aepch.h>
#include "IndexBufferOGL.h"

#include "glad/glad.h"

namespace AEngine {
    IndexBufferOGL::IndexBufferOGL(void* verticies, uint32_t size) {
        glCreateBuffers(1, &id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, verticies, GL_STATIC_DRAW);
    }

    IndexBufferOGL::~IndexBufferOGL() { }

    void IndexBufferOGL::bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    }

    void IndexBufferOGL::unBind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void IndexBufferOGL::addData() { }

    void IndexBufferOGL::destroy() { BufferOGL::destroy(); }

    void          IndexBufferOGL::setBufferLayout(const BufferLayout& _layout) { BufferOGL::setBufferLayout(_layout); }
    BufferLayout& IndexBufferOGL::getLayout() { return BufferOGL::getLayout(); }
}
