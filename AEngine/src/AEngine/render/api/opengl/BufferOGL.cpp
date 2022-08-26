#include <aepch.h>
#include "BufferOGL.h"

#include <glad/glad.h>

namespace AEngine {
    void BufferOGL::bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, id);
    }

    void BufferOGL::unBind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    //TODO: idk
    void BufferOGL::destroy() {
        glDeleteBuffers(1, &id);
    }
}
