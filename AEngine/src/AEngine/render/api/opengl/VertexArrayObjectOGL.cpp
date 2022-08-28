#include <aepch.h>
#include "VertexArrayObjectOGL.h"

#include <glad/glad.h>

namespace AEngine {
    VertexArrayObjectOGL::VertexArrayObjectOGL() {
        glCreateVertexArrays(1, &id);
    }

    VertexArrayObjectOGL::~VertexArrayObjectOGL() {
        glDeleteVertexArrays(1, &id);
    }

    void VertexArrayObjectOGL::bind() const {
        glBindVertexArray(id);
    }

    void VertexArrayObjectOGL::unBind() const {
        glBindVertexArray(0);
    }

    // TODO: Make it so the vao when it adds a buffer sets the buffers parent (a variable in the buffer) to this vao,
    // TODO: therefore if the user changes the data inside or the layout the parent can be therefore alerted and the proper changes can be made.
    void VertexArrayObjectOGL::addVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) {
        glBindVertexArray(id);
        vertexBuffer->bind();

        AE_CORE_ASSERT(vertexBuffer->getLayout().getElements().size(), "VERTEX BUFFER HAS NO LAYOUTS");

        uint32_t i = 0;
        for (const auto& el : vertexBuffer->getLayout().getElements()) {
            glEnableVertexAttribArray(i);
            glVertexAttribPointer(i,
                                  AETypeElementCount(el.type),
                                  AETypeToGLType(el.type),
                                  el.normalized ? GL_FALSE : GL_TRUE,
                                  vertexBuffer->getLayout().getStride(),
                                  (const void*) el.offset);
            i++;
        }

        vbs.push_back(vertexBuffer);
        glBindVertexArray(0);
    }

    void VertexArrayObjectOGL::addIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) {
        glBindVertexArray(id);
        indexBuffer->bind();

        //ibs.push_back(indexBuffer);
        ibs = indexBuffer;
    }

}
