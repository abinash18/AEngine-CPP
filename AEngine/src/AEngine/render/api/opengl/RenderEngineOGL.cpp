#include <aepch.h>
#include "RenderEngineOGL.h"

#include <glad/glad.h>

#include "AEngine/render/api/ae/BufferLayout.h"
#include "AEngine/render/api/ae/IndexBuffer.h"
#include "AEngine/render/api/ae/VertexBuffer.h"

namespace AEngine {
    RenderEngineOGL::RenderEngineOGL() { }

    RenderEngineOGL::~RenderEngineOGL() {
        delete vertexBuffer;
        delete indexBuffer;
    }

    void RenderEngineOGL::printAPIInfo() {
        GLint min, maj;
        glGetIntegerv(GL_MINOR_VERSION, &min);
        glGetIntegerv(GL_MAJOR_VERSION, &maj);
        AE_CORE_INFO("Using AE_OpenGL_RenderEngine:");
        AE_CORE_INFO("OpenGL Version Number: MINOR: {0} MAJOR: {1} ", min, maj);
        AE_CORE_INFO("OpenGL Renderer: {0} ", glGetString(GL_RENDERER));
        AE_CORE_INFO("OpenGL Version: {0} ", glGetString(GL_VERSION));
        AE_CORE_INFO("OpenGL GLSL Shader Version: {0} ", glGetString(GL_SHADING_LANGUAGE_VERSION));
    }

    void RenderEngineOGL::render() {
        glClearColor(0.1f, 0.1f, 0.1f, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        shader->bind();
        glBindVertexArray(vertexArrayBuffer);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
    }

    void RenderEngineOGL::update() { }

    void RenderEngineOGL::init() {
        // Initialize OpenGL units
        glGenVertexArrays(1, &vertexArrayBuffer);
        glBindVertexArray(vertexArrayBuffer);

        //glGenBuffers(1, &vertexBuffer);
        //glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

        /*float vert[3 * 3] = {
            -0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f,
        };*/

        float vertices[3 * 7] = {
            -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
            0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
            0.0f, 0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
        };

        vertexBuffer = VertexBuffer::create(vertices, sizeof(vertices));
        //glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);

        {
            // This destroys the local variables after the scope ends.
            BufferLayout layout = {
                { AEDataType::FLOAT3, "a_Position" },
                { AEDataType::FLOAT4, "a_Color" }
            };

            vertexBuffer->setBufferLayout(layout);
        }
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
        //glGenBuffers(1, &indexBuffer);
        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);


        unsigned int ind[3] = { 0, 1, 2 };
        indexBuffer         = IndexBuffer::create(ind, sizeof(ind));
        //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(ind), ind, GL_STATIC_DRAW);


        std::string vertexsrc = R"(
        #version 330 core
        layout(location = 0) in vec3 a_Position;

        void main() {
        gl_Position = vec4(a_Position, 1.0);
        }
        )";
        std::string fragsrc   = R"(
        #version 330 core
        layout(location = 0) out vec4 color;

        void main() {
        color = vec4(0.8, 0.2, 0.3, 1.0);
        }
        )";

        shader.reset(new Shader(vertexsrc, fragsrc));
    }
}
