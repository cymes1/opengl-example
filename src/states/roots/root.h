#ifndef ROOT_H
#define ROOT_H

#include <memory>
#include <states/roots/base/iroot.h>

namespace OpenGlExample
{
    class Root : public IRoot
    {
    public:
        Root() = default;

        void tick() const override;
        void render() const override;
        void renderImGui() const override;

        const States::State* getCurrentState() const override { return currentState.get(); }
    };
}

#endif