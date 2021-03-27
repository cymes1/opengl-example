#ifndef IROOT_H
#define IROOT_H

#include <memory>
#include <states/base/state.h>

namespace OpenGlExample
{
    class IRoot
    {
    protected:
        std::unique_ptr<States::State> currentState;

    public:
        virtual ~IRoot() = default;

        template <class TNewState>
        void initialize();

        virtual void tick() const = 0;
        virtual void render() const = 0;
        virtual void renderImGui() const = 0;
        virtual const States::State* getCurrentState() const = 0;

        template <class TNewState>
        void createState();
    };

    template <class TNewState>
    void IRoot::initialize()
    {
        createState<TNewState>();
    }

    template <class TNewState>
    void IRoot::createState()
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