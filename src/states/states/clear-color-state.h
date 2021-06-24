#ifndef CLEAR_COLOR_STATE_H
#define CLEAR_COLOR_STATE_H

#include <states/states/base/state.h>

namespace OpenGlExample::States
{
    class ClearColorState : public State
    {
    private:
        float clearColor[4];

    public:
        explicit ClearColorState(Root& root);
        ~ClearColorState() override = default;

        void render() override;
        void renderImGui() override;
    };
}

#endif