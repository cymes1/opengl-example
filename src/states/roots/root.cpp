#include "root.h"

namespace OpenGlExample
{
    void Root::tick() const
    {
        currentState->tick();
    }

    void Root::render() const
    {
        currentState->render();
    }

    void Root::renderImGui() const
    {
        currentState->renderImGui();
    }
}