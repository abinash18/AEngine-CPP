#include "aepch.h"
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

        vao.reset(VertexArrayObject::create());
        vao->bind();
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

        // This destroys the local variables after the scope ends.
        BufferLayout layout = {
            { AEDataType::FLOAT3, "a_Position" },
            { AEDataType::FLOAT4, "a_Colors" }
        };

        vertexBuffer->setBufferLayout(layout);

        vao->addVertexBuffer(vertexBuffer);

        unsigned int ind[3] = { 0, 1, 2 };
        indexBuffer.reset(IndexBuffer::create(ind, sizeof(ind), sizeof(ind) / sizeof(uint32_t)));

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
        renderer->Clear();
        squareShader->bind();
        submit(squareVAO);
        shader->bind();
        submit(vao);
    }

    void RenderEngine::update() {}

    void RenderEngine::submit(const std::shared_ptr<VertexArrayObject>& _vertex_array) {
        _vertex_array->bind();
        renderer->drawIndexed(_vertex_array);
    }

}
