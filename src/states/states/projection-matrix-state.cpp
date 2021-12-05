#include "projection-matrix-state.h"
#include <imgui.h>
#include <gtc/matrix_transform.hpp>
#include <states/states/menu-state.h>
#include <renderer.h>

namespace OpenGlExample::States
{
    ProjectionMatrixState::ProjectionMatrixState(Root& root)
            : State(root),
              view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
            //proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)),
              translationA(0, 0, 0),
              translationB(0, 120, -130),
              left(-480),
              right(480),
              bottom(-270),
              top(270),
              near(2),
              far(1000),
              fovy(45),
              vecView(0, 0, 500),
              vecCenter(0, 0, -1),
              vecHead(0, 1, 0)
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

        glEnable(GL_DEPTH_TEST);

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
        glDisable(GL_DEPTH_TEST);
    }

    void ProjectionMatrixState::render()
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if(isPerspective)
        {
            float aspectRatio = (right - left) / (top - bottom);
            proj = glm::perspective(glm::radians(fovy), aspectRatio, near, far);
        }
        else
        {
            proj = glm::ortho(left, right, bottom, top, near, far);
        }

        view = glm::lookAt(
                vecView,
                vecView + vecCenter,
                vecHead
                );

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

        ImGui::DragFloat("left", &left, 1.0f, -1000.0f, 1000.0f);
        ImGui::DragFloat("right", &right, 1.0f, -1000.0f, 1000.0f);
        ImGui::DragFloat("bottom", &bottom, 1.0f, -1000.0f, 1000.0f);
        ImGui::DragFloat("top", &top, 1.0f, -1000.0f, 1000.0f);
        ImGui::DragFloat("near", &near, 0.001f, -1000.0f, 1000.0f);
        ImGui::DragFloat("far", &far, 0.01f, -1000.0f, 1000.0f);
        ImGui::DragFloat("fovy", &fovy, 1.0f, 0.0f, 180.0f);
        ImGui::Checkbox("IsPerspective", &isPerspective);
        ImGui::DragFloat3("Translation A", &translationA.x, 1.0f, -960.0f, 960.0f);
        ImGui::DragFloat3("Translation B", &translationB.x, 1.0f, -960.0f, 960.0f);
        ImGui::DragFloat3("View", &vecView.x, 1.0f, -960.0f, 960.0f);
        ImGui::DragFloat3("Center", &vecCenter.x, 1.0f, -960.0f, 960.0f);
        ImGui::DragFloat3("Head", &vecHead.x, 1.0f, -960.0f, 960.0f);
    }
}
