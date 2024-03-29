#ifndef TEXTURE_2D_STATE_H
#define TEXTURE_2D_STATE_H

#include <memory>
#include <glm.hpp>
#include <vertex-array.h>
#include <index-buffer.h>
#include <shader.h>
#include <texture.h>
#include <states/states/base/state.h>

namespace OpenGlExample::States
{
    class Texture2DState : public State
    {
    private:
        std::unique_ptr<Shader> shader;
        std::unique_ptr<Texture> texture;
        glm::mat4 proj;
        glm::mat4 view;
        glm::vec3 translationA;
        glm::vec3 translationB;
		glm::vec3 scaleA;
		glm::vec3 scaleB;
		GLuint vbo;
		GLuint vao;
		GLuint ibo;
		GLsizei indicesCount;
    public:
        explicit Texture2DState(Root& root);
        ~Texture2DState() override;

        void render() override;
        void renderImGui() override;
    };
}

#endif