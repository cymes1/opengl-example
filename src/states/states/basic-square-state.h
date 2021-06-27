#ifndef BASIC_SQUARE_STATE_H
#define BASIC_SQUARE_STATE_H

#include <GL/glew.h>
#include <states/states/base/state.h>
#include <shader.h>

namespace OpenGlExample::States
{
    class BasicSquareState : public State
    {
    private:
        GLuint vertexBufferId;
        GLuint vertexArrayId;
        Shader shader;

    public:
        explicit BasicSquareState(Root& root);
        ~BasicSquareState() override;

        void render() override;
        void renderImGui() override;
    };
}

#endif