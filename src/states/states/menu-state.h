#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <vector>
#include <functional>
#include <states/roots/base/iroot.h>
#include <states/states/base/state.h>

namespace OpenGlExample::States
{
    class MenuState : public State
    {
    private:
        std::vector<std::pair<std::string, std::function<void(IRoot&)>>> examples;

    public:
        explicit MenuState(IRoot& root);
        ~MenuState() override = default;

        void initialize() override;
        void renderImGui() override;

    private:
        template<typename T>
        void registerTest(const std::string& name)
        {
            examples.push_back(std::make_pair(name, [](IRoot& root) { root.createState<T>(); }));
        }
    };
}

#endif