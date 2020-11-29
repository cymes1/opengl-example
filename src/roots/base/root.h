#ifndef ROOT_H
#define ROOT_H

#include <memory>
#include "iroot.h"

namespace OpenGlExample
{
    template <class TFirstState>
    class Root : public IRoot
    {
    public:
        Root();

        void tick() const override;
        void render() const override;
        void renderImGui() const override;

        const States::State* getCurrentState() const override { return currentState.get(); }
    };

    template <class TFirstState>
    Root<TFirstState>::Root()
    {
        std::cout << "root constructor" << std::endl;
    }

    template <class TFirstState>
    void Root<TFirstState>::tick() const
    {
        std::cout << "root tick" << std::endl;
        currentState->tick();
    }

    template <class TFirstState>
    void Root<TFirstState>::render() const
    {
        std::cout << "root render" << std::endl;
        currentState->render();
    }

    template <class TFirstState>
    void Root<TFirstState>::renderImGui() const
    {
        std::cout << "root renderImGui" << std::endl;
        currentState->renderImGui();
    }
}

#endif