#include "state.h"

namespace OpenGlExample::States
{
    State::State(Root& root)
            : root(root) {}

    void State::initialize()
    {}

    void State::tick()
    {}

    void State::render()
    {}

    void State::renderImGui()
    {}

    void State::dispose()
    {}
}