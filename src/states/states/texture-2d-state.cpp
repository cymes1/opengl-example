#include "texture-2d-state.h"
#include <imgui.h>
#include <gtc/matrix_transform.hpp>
#include <states/states/menu-state.h>
#include <renderer.h>

namespace OpenGlExample::States
{
    Texture2DState::Texture2DState(Root& root)
            : State(root),
            proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)),
            view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
            translationA(200, 200, 0),
            translationB(400, 200, 0),
			scaleA(1, 1, 1),
			scaleB(1, 1, 1),
			indicesCount(6)
    {
        float positions[] = {
            -50.0f, -50.0f, 0.0f, 0.0f,
             50.0f, -50.0f, 1.0f, 0.0f,
             50.0f,  50.0f, 1.0f, 1.0f,
            -50.0f,  50.0f, 0.0f, 1.0f
        };

        unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
        };

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, 4 * 4 * sizeof(float), positions, GL_STATIC_DRAW);

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);


		GLsizei stride = 4 * 4;
		GLuint offset = 0;
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, false, stride, reinterpret_cast<const void*>(offset));
		offset += 2 * 4;
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, false, stride, reinterpret_cast<const void*>(offset));


		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesCount * sizeof(GLuint), indices, GL_STATIC_DRAW);

		texture = std::make_unique<Texture>("res/texture/test-texture.png");
        shader = std::make_unique<Shader>("res/shader/texture-2d/basic-texture.shader");
        shader->bind();
        shader->setUniform1i("u_Texture", 0);
    }

    Texture2DState::~Texture2DState()
    {
		shader->unbind();
		glDeleteBuffers(1, &ibo);
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
	}

    void Texture2DState::render()
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        texture->bind();

        {
            glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
            glm::mat4 mvp = proj * view * model;
			mvp = glm::scale(mvp, scaleA);
            shader->bind();
            shader->setUniformMat4f("u_MVP", mvp);
			shader->bind();
			glBindVertexArray(vao);
			glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, nullptr);
        }
        {
            glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB);
            glm::mat4 mvp = proj * view * model;
			mvp = glm::scale(mvp, scaleB);
            shader->bind();
            shader->setUniformMat4f("u_MVP", mvp);
			shader->bind();
			glBindVertexArray(vao);
			glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, nullptr);
		}
    }

    void Texture2DState::renderImGui()
    {
        ImGui::Begin("Texture 2D");
        if(ImGui::Button("<-"))
        {
            root.createState<MenuState>();
        }
        ImGui::SliderFloat3("Translation A", &translationA.x, 0.0f, 960.0f);
        ImGui::SliderFloat3("Translation B", &translationB.x, 0.0f, 960.0f);
		ImGui::SliderFloat3("Scale A", &scaleA.x, 0.1f, 3.0f);
		ImGui::SliderFloat3("Scale B", &scaleB.x, 0.1f, 3.0f);
	}
}