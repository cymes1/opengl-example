#ifndef MENU_EXAMPLE_H
#define MENU_EXAMPLE_H

#include "base/example.h"

namespace OpenGlExample::Example
{
    class MenuExample : public Example
    {
    public:
        MenuExample();
        ~MenuExample() override;

        void tick() override;
        void render() override;
        void renderImGui() override;
    };
}

#endif