#ifndef ROOT_H
#define ROOT_H

#include <memory>
#include <states/states/base/state.h>

namespace OpenGlExample
{
    class Root
    {
    private:
        std::unique_ptr<States::State> currentState;

    public:
        Root() = default;
        ~Root() = default;

        void tick() const;
        void render() const;
        void renderImGui() const;

        template <class TNewState>
        void initialize();
        template <class TNewState>
        void createState();
    };

    template <class TNewState>
    void Root::initialize()
    {
        createState<TNewState>();
    }

    template <class TNewState>
    void Root::createState()
    {
        if(currentState != nullptr)
        {
            currentState->dispose();
            currentState.reset();
        }
        currentState = std::make_unique<TNewState>(*this);
        currentState->initialize();
    }
}

#endif