#include <aepch.h>
#include "RenderEngine.h"

namespace AEngine {

    RenderAPI RenderEngine::s_render_api = RenderAPI::OPEN_GL;

    RenderEngine::RenderEngine() { }

    RenderEngine::~RenderEngine() {
        delete renderer;
    }

    void RenderEngine::init() {
        renderer = RendererAPI::create();

        renderer->initAPI();
        renderer->printAPIInfo();

        // Initialize OpenGL units
        /*glGenVertexArrays(1, &vertexArrayBuffer);
        glBindVertexArray(vertexArrayBuffer);*/

        vao.reset(VertexArrayObject::create());
        vao->bind();
        //glGenBuffers(1, &vertexBuffer);
        //glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

        /* float vertices[3 * 3] = {
             -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.0f, 0.5f, 0.0f,
         };*/

        float vertices[3 * 7] = {
            -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
            0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
            0.0f, 0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
        };

        float colors[3 * 4] = {
            0.8f, 0.2f, 0.8f, 1.0f,
            0.2f, 0.3f, 0.8f, 1.0f,
            0.8f, 0.8f, 0.2f, 1.0f
        };

        vertexBuffer.reset(VertexBuffer::create(vertices, sizeof(vertices)));
        //glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);

        // This destroys the local variables after the scope ends.
        BufferLayout layout = {
            { AEDataType::FLOAT3, "a_Position" },
            { AEDataType::FLOAT4, "a_Colors" }
        };

        vertexBuffer->setBufferLayout(layout);

        vao->addVertexBuffer(vertexBuffer);

        /* uint32_t i = 0;
         for (const auto& el : vertexBuffer->getLayout().getElements()) {
             glEnableVertexAttribArray(i);
             glVertexAttribPointer(i,
                                   AETypeElementCount(el.type),
                                   AETypeToGLType(el.type),
                                   el.normalized ? GL_FALSE : GL_TRUE,
                                   vertexBuffer->getLayout().getStride(),
                                   (const void*) el.offset);
             i++;
         }*/

        //glEnableVertexAttribArray(0);
        //glVertexAttribPointer(0,
        //                      AETypeElementCount(vertexBuffer->getLayout().getElements().at(0).type),
        //                      AETypeToGLType(vertexBuffer->getLayout().getElements().at(0).type),
        //                      vertexBuffer->getLayout().getElements().at(0).normalized ? GL_FALSE : GL_TRUE,
        //                      vertexBuffer->getLayout().getStride(),
        //                      (const void*) vertexBuffer->getLayout().getElements().at(0).offset);

        //vertexBuffer2 = VertexBuffer::create(colors, sizeof(colors));
        //{
        //    // This destroys the local variables after the scope ends.
        //    BufferLayout layout = {
        //        { AEDataType::FLOAT4, "a_Colors" },
        //    };

        //    vertexBuffer2->setBufferLayout(layout);
        //}

        //glEnableVertexAttribArray(1);
        //glVertexAttribPointer(1,
        //                      AETypeElementCount(vertexBuffer2->getLayout().getElements().at(0).type),
        //                      AETypeToGLType(vertexBuffer2->getLayout().getElements().at(0).type),
        //                      vertexBuffer2->getLayout().getElements().at(0).normalized ? GL_FALSE : GL_TRUE,
        //                      vertexBuffer2->getLayout().getStride(),
        //                      (const void*) vertexBuffer2->getLayout().getElements().at(0).offset);

        //glGenBuffers(1, &indexBuffer);
        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);


        unsigned int ind[3] = { 0, 1, 2 };
        indexBuffer.reset(IndexBuffer::create(ind, sizeof(ind), sizeof(ind) / sizeof(uint32_t)));
        //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(ind), ind, GL_STATIC_DRAW);


        vao->addIndexBuffer(indexBuffer);

        std::string vertexsrc = R"(
        #version 330 core
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;
			out vec3 v_Position;
			out vec4 v_Color;
			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = vec4(a_Position, 1.0);	
			}
        )";
        std::string fragsrc   = R"(
        #version 330 core
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			in vec4 v_Color;
			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
        )";
        shader.reset(new Shader(vertexsrc, fragsrc));

        std::string squareVert = R"(
        #version 330 core
			layout(location = 0) in vec3 a_Position;
			out vec3 v_Position;
			void main()
			{
				v_Position = a_Position;
				gl_Position = vec4(a_Position, 1.0);	
			}
        )";
        std::string squareFrag = R"(
        #version 330 core
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			void main()
			{
				color = vec4(0.1, 0.5,1,1);
			}
        )";
        squareShader.reset(new Shader(squareVert, squareFrag));

        squareVAO.reset(VertexArrayObject::create());
        squareVAO->bind();
        float squareVertices[3 * 4] = {
            -0.75f, -0.75f, 0.0f,
            0.75f, -0.75f, 0.0f,
            0.75f, 0.75f, 0.0f,
            -0.75f, 0.75f, 0.0f
        };

        std::shared_ptr<VertexBuffer> squareVB;

        squareVB.reset(VertexBuffer::create(squareVertices, sizeof(squareVertices)));
        squareVB->setBufferLayout({
                                      { AEDataType::FLOAT3, "a_Position" },
                                  });
        squareVAO->addVertexBuffer(squareVB);

        unsigned int squareIndicies[6] = { 0, 1, 2, 2, 3, 0 };

        std::shared_ptr<IndexBuffer> squareIB;
        squareIB.reset(IndexBuffer::create(squareIndicies,
                                           sizeof(squareIndicies),
                                           sizeof(squareIndicies) / sizeof(uint32_t)));
        squareVAO->addIndexBuffer(squareIB);

        renderer->SetClearColor({ 0.1, 0.1, 0.1, 1 });

    }

    void RenderEngine::render() {
        /*glClearColor(0.1f, 0.1f, 0.1f, 1);
        glClear(GL_COLOR_BUFFER_BIT);*/
        renderer->Clear();
        squareVAO->bind();
        squareShader->bind();

        renderer->drawIndexed(squareVAO);

        /*glDrawElements(GL_TRIANGLES,
                       6,
                       GL_UNSIGNED_INT,
                       nullptr
                      );*/
        vao->bind();
        shader->bind();
        renderer->drawIndexed(vao);
        //glBindVertexArray(vertexArrayBuffer);
        /* glDrawElements(GL_TRIANGLES,
                        indexBuffer->getCount(),
                        GL_UNSIGNED_INT,
                        nullptr
                       );*/
    }

    void RenderEngine::update() {}
    void RenderEngine::submit(const std::shared_ptr<VertexArrayObject>& vertexArray) { }

}
