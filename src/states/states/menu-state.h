#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <vector>
#include <functional>
#include <states/roots/root.h>
#include <states/states/base/state.h>

namespace OpenGlExample::States
{
    class MenuState : public State
    {
    private:
        std::vector<std::pair<std::string, std::function<void(Root&)>>> examples;

    public:
        explicit MenuState(Root& root);
        ~MenuState() override = default;

        void initialize() override;
        void renderImGui() override;

    private:
        template<typename T>
        void registerTest(const std::string& name)
        {
            examples.push_back(std::make_pair(name, [](Root& root) { root.createState<T>(); }));
        }
    };
}

#endif