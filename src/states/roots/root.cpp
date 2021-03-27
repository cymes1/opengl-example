#include "root.h"

namespace OpenGlExample
{
    Root::Root()
    {
        std::cout << "root constructor" << std::endl;
    }

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