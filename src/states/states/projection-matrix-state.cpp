#include "projection-matrix-state.h"
#include <imgui.h>
#include <gtc/matrix_transform.hpp>
#include <states/states/menu-state.h>
#include <renderer.h>

namespace OpenGlExample::States
{
    ProjectionMatrixState::ProjectionMatrixState(Root& root)
            : State(root),
              proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)),
              view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
              translationA(200, 200, 0),
              translationB(400, 200, 0)
    {
        float positions[] = {
            -50.0f, -50.0f,
             50.0f, -50.0f,
             50.0f,  50.0f,
            -50.0f,  50.0f
        };

        unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
        };

        GLCall(glEnable(GL_BLEND));
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));


        vertexBuffer = std::make_unique<VertexBuffer>(positions, 4 * 2 * sizeof(float));
        VertexBufferLayout layout;
        layout.push<float>(2);
        vertexArray = std::make_unique<VertexArray>();
        vertexArray->addBuffer(*vertexBuffer, layout);
        indexBuffer = std::make_unique<IndexBuffer>(indices, 6);

        shader = std::make_unique<Shader>("res/shader/projection-matrix/projection.shader");
        shader->bind();
    }

    ProjectionMatrixState::~ProjectionMatrixState()
    {
        shader->unbind();
    }

    void ProjectionMatrixState::render()
    {
        GLCall(glClearColor(0.0f, 0.0f, 0.0f, 0.0f));
        GLCall(glClear(GL_COLOR_BUFFER_BIT));

        Renderer renderer;

        {
            glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
            glm::mat4 mvp = proj * view * model;
            shader->bind();
            shader->setUniformMat4f("u_MVP", mvp);
            shader->setUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);
            renderer.draw(*vertexArray, *indexBuffer, *shader);
        }
        {
            glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB);
            glm::mat4 mvp = proj * view * model;
            shader->bind();
            shader->setUniformMat4f("u_MVP", mvp);
            shader->setUniform4f("u_Color", 0.0f, 1.0f, 0.0f, 1.0f);
            renderer.draw(*vertexArray, *indexBuffer, *shader);
        }
    }

    void ProjectionMatrixState::renderImGui()
    {
        ImGui::Begin("Texture 2D");
        if(ImGui::Button("<-"))
        {
            root.createState<MenuState>();
        }
        ImGui::SliderFloat3("Translation A", &translationA.x, 0.0f, 960.0f);
        ImGui::SliderFloat3("Translation B", &translationB.x, 0.0f, 960.0f);
    }
}
