#ifndef ROOT_H
#define ROOT_H

#include <memory>
#include "../base/iroot.h"

namespace OpenGlExample
{
    class Root : public IRoot
    {
    public:
        Root();

        void tick() const override;
        void render() const override;
        void renderImGui() const override;

        const States::State* getCurrentState() const override { return currentState.get(); }
    };
}

#endif