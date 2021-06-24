#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <states/enums/state-id.h>

namespace OpenGlExample
{
    class Root;
}

namespace OpenGlExample::States
{
    class State
    {
    protected:
        const StateId id;
        Root& root;

    protected:
        explicit State(StateId id, Root& root);

    public:
        virtual ~State() = default;

        virtual void initialize();
        virtual void tick();
        virtual void render();
        virtual void renderImGui();
        virtual void dispose();

        int getId() const { return id; }
    };
}

#endif