#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "base/state.h"

namespace OpenGlExample
{
    class IRoot;
}

namespace OpenGlExample::States
{
    class MenuState : public State
    {
    private:
        IRoot& root;

    public:
        explicit MenuState(IRoot& root);
        ~MenuState() override;

        void initialize() override;
        void tick() override;
        void render() override;
        void renderImGui() override;
        void dispose() override;
    };
}

#endif