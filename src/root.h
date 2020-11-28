#ifndef ROOT_H
#define ROOT_H

#include <memory>
#include <example/base/example.h>

namespace OpenGlExample
{
    template<class T = class TInitialExample>
    class Root
    {
    private:
        std::unique_ptr<T> currentExample;

    public:
        Root();

        void initialize() const;
        void tick() const;
        void dispose() const;
    };

    template <typename T>
    Root<T>::Root()
        : currentExample(std::make_unique<T>())
    {}

    template <typename T>
    void Root<T>::initialize() const
    {}

    template <typename T>
    void Root<T>::tick() const
    {
        currentExample->tick();
    }

    template <typename T>
    void Root<T>::dispose() const
    {}
}


#endif