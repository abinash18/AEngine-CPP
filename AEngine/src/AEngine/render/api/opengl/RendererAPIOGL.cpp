#include "aepch.h"
#include "RendererAPIOGL.h"

#include <glad/glad.h>

#include "AEngine/render/api/ae/IndexBuffer.h"

namespace AEngine {
    RendererAPIOGL::RendererAPIOGL() { }

    RendererAPIOGL::~RendererAPIOGL() { }

    void RendererAPIOGL::printAPIInfo() {
        GLint min, maj;
        glGetIntegerv(GL_MINOR_VERSION, &min);
        glGetIntegerv(GL_MAJOR_VERSION, &maj);

        AE_CORE_INFO("\033[1;3;5;93;100mUsing AE_OpenGL_RenderEngine:");
        AE_CORE_INFO("\033[1;3;5;93;100mOpenGL Version Number: MINOR: {0} MAJOR: {1} ", min, maj);
        AE_CORE_INFO("\033[1;3;5;93;100mOpenGL Renderer: {0} ", glGetString(GL_RENDERER));
        AE_CORE_INFO("\033[1;3;5;93;100mOpenGL Version: {0} ", glGetString(GL_VERSION));
        AE_CORE_INFO("\033[1;3;5;93;100mOpenGL GLSL Shader Version: {0} ", glGetString(GL_SHADING_LANGUAGE_VERSION));
    }

    void RendererAPIOGL::drawIndexed(const std::shared_ptr<VertexArrayObject>& vao) {
        glDrawElements(GL_TRIANGLES,
                       vao->getIbs()->getCount(),
                       GL_UNSIGNED_INT,
                       nullptr
                      );
    }

    void RendererAPIOGL::initAPI() {}

    void RendererAPIOGL::SetClearColor(const glm::vec4& color) {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void RendererAPIOGL::Clear() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    //void RendererAPIOGL::render() {
    //    glClearColor(0.1f, 0.1f, 0.1f, 1);
    //    glClear(GL_COLOR_BUFFER_BIT);
    //    squareVAO->bind();
    //    squareShader->bind();


    //    glDrawElements(GL_TRIANGLES,
    //                   6,
    //                   GL_UNSIGNED_INT,
    //                   nullptr
    //                  );
    //    vao->bind();
    //    shader->bind();

    //    //glBindVertexArray(vertexArrayBuffer);
    //    glDrawElements(GL_TRIANGLES,
    //                   indexBuffer->getCount(),
    //                   GL_UNSIGNED_INT,
    //                   nullptr
    //                  );
    //}

    //void RendererAPIOGL::update() { }

    //void RendererAPIOGL::init() {
    //    // Initialize OpenGL units
    //    /*glGenVertexArrays(1, &vertexArrayBuffer);
    //    glBindVertexArray(vertexArrayBuffer);*/
    //
    //    vao.reset(VertexArrayObject::create());
    //    vao->bind();
    //    //glGenBuffers(1, &vertexBuffer);
    //    //glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    //
    //    /* float vertices[3 * 3] = {
    //         -0.5f, -0.5f, 0.0f,
    //         0.5f, -0.5f, 0.0f,
    //         0.0f, 0.5f, 0.0f,
    //     };*/
    //
    //    float vertices[3 * 7] = {
    //        -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
    //        0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
    //        0.0f, 0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
    //    };
    //
    //    float colors[3 * 4] = {
    //        0.8f, 0.2f, 0.8f, 1.0f,
    //        0.2f, 0.3f, 0.8f, 1.0f,
    //        0.8f, 0.8f, 0.2f, 1.0f
    //    };
    //
    //    vertexBuffer.reset(VertexBuffer::create(vertices, sizeof(vertices)));
    //    //glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);
    //
    //    // This destroys the local variables after the scope ends.
    //    BufferLayout layout = {
    //        { AEDataType::FLOAT3, "a_Position" },
    //        { AEDataType::FLOAT4, "a_Colors" }
    //    };
    //
    //    vertexBuffer->setBufferLayout(layout);
    //
    //    vao->addVertexBuffer(vertexBuffer);
    //
    //    /* uint32_t i = 0;
    //     for (const auto& el : vertexBuffer->getLayout().getElements()) {
    //         glEnableVertexAttribArray(i);
    //         glVertexAttribPointer(i,
    //                               AETypeElementCount(el.type),
    //                               AETypeToGLType(el.type),
    //                               el.normalized ? GL_FALSE : GL_TRUE,
    //                               vertexBuffer->getLayout().getStride(),
    //                               (const void*) el.offset);
    //         i++;
    //     }*/
    //
    //    //glEnableVertexAttribArray(0);
    //    //glVertexAttribPointer(0,
    //    //                      AETypeElementCount(vertexBuffer->getLayout().getElements().at(0).type),
    //    //                      AETypeToGLType(vertexBuffer->getLayout().getElements().at(0).type),
    //    //                      vertexBuffer->getLayout().getElements().at(0).normalized ? GL_FALSE : GL_TRUE,
    //    //                      vertexBuffer->getLayout().getStride(),
    //    //                      (const void*) vertexBuffer->getLayout().getElements().at(0).offset);
    //
    //    //vertexBuffer2 = VertexBuffer::create(colors, sizeof(colors));
    //    //{
    //    //    // This destroys the local variables after the scope ends.
    //    //    BufferLayout layout = {
    //    //        { AEDataType::FLOAT4, "a_Colors" },
    //    //    };
    //
    //    //    vertexBuffer2->setBufferLayout(layout);
    //    //}
    //
    //    //glEnableVertexAttribArray(1);
    //    //glVertexAttribPointer(1,
    //    //                      AETypeElementCount(vertexBuffer2->getLayout().getElements().at(0).type),
    //    //                      AETypeToGLType(vertexBuffer2->getLayout().getElements().at(0).type),
    //    //                      vertexBuffer2->getLayout().getElements().at(0).normalized ? GL_FALSE : GL_TRUE,
    //    //                      vertexBuffer2->getLayout().getStride(),
    //    //                      (const void*) vertexBuffer2->getLayout().getElements().at(0).offset);
    //
    //    //glGenBuffers(1, &indexBuffer);
    //    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    //
    //
    //    unsigned int ind[3] = { 0, 1, 2 };
    //    indexBuffer.reset(IndexBuffer::create(ind, sizeof(ind), sizeof(ind) / sizeof(uint32_t)));
    //    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(ind), ind, GL_STATIC_DRAW);
    //
    //
    //    vao->addIndexBuffer(indexBuffer);
    //
    //    std::string vertexsrc = R"(
    //    #version 330 core
    //		layout(location = 0) in vec3 a_Position;
    //		layout(location = 1) in vec4 a_Color;
    //		out vec3 v_Position;
    //		out vec4 v_Color;
    //		void main()
    //		{
    //			v_Position = a_Position;
    //			v_Color = a_Color;
    //			gl_Position = vec4(a_Position, 1.0);	
    //		}
    //    )";
    //    std::string fragsrc   = R"(
    //    #version 330 core
    //		layout(location = 0) out vec4 color;
    //		in vec3 v_Position;
    //		in vec4 v_Color;
    //		void main()
    //		{
    //			color = vec4(v_Position * 0.5 + 0.5, 1.0);
    //			color = v_Color;
    //		}
    //    )";
    //    shader.reset(new Shader(vertexsrc, fragsrc));
    //
    //    std::string squareVert = R"(
    //    #version 330 core
    //		layout(location = 0) in vec3 a_Position;
    //		out vec3 v_Position;
    //		void main()
    //		{
    //			v_Position = a_Position;
    //			gl_Position = vec4(a_Position, 1.0);	
    //		}
    //    )";
    //    std::string squareFrag = R"(
    //    #version 330 core
    //		layout(location = 0) out vec4 color;
    //		in vec3 v_Position;
    //		void main()
    //		{
    //			color = vec4(0.1, 0.5,1,1);
    //		}
    //    )";
    //    squareShader.reset(new Shader(squareVert, squareFrag));
    //
    //    squareVAO.reset(VertexArrayObject::create());
    //    squareVAO->bind();
    //    float squareVertices[3 * 4] = {
    //        -0.75f, -0.75f, 0.0f,
    //        0.75f, -0.75f, 0.0f,
    //        0.75f, 0.75f, 0.0f,
    //        -0.75f, 0.75f, 0.0f
    //    };
    //
    //    std::shared_ptr<VertexBuffer> squareVB;
    //
    //    squareVB.reset(VertexBuffer::create(squareVertices, sizeof(squareVertices)));
    //    squareVB->setBufferLayout({
    //                                  { AEDataType::FLOAT3, "a_Position" },
    //                              });
    //    squareVAO->addVertexBuffer(squareVB);
    //
    //    unsigned int squareIndicies[6] = { 0, 1, 2, 2, 3, 0 };
    //
    //    std::shared_ptr<IndexBuffer> squareIB;
    //    squareIB.reset(IndexBuffer::create(squareIndicies,
    //                                       sizeof(squareIndicies),
    //                                       sizeof(squareIndicies) / sizeof(uint32_t)));
    //    squareVAO->addIndexBuffer(squareIB);
    //
    //
    //}
}
