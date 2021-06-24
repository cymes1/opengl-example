#ifndef STATE_H
#define STATE_H

#include <iostream>

namespace OpenGlExample
{
    class Root;
}

namespace OpenGlExample::States
{
    class State
    {
    protected:
        Root& root;

    protected:
        explicit State(Root& root);

    public:
        virtual ~State() = default;

        virtual void initialize();
        virtual void tick();
        virtual void render();
        virtual void renderImGui();
        virtual void dispose();
    };
}

#endif