#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../enums/state-id.h"

namespace OpenGlExample::States
{
    class State
    {
    protected:
        const StateId id;

    protected:
        explicit State(StateId id) : id(id) {}

    public:
        virtual ~State() = default;

        virtual void initialize() = 0;
        virtual void tick() = 0;
        virtual void render() = 0;
        virtual void renderImGui() = 0;
        virtual void dispose() = 0;

        int getId() const { return id; }
    };
}

#endif