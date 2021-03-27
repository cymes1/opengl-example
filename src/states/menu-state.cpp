#include "menu-state.h"
#include <iostream>
#include <imgui.h>
#include "base/iroot.h"
#include "enums/state-id.h"

namespace OpenGlExample::States
{
    MenuState::MenuState(IRoot& root)
            : State(StateId::MENU), root(root)
    {
        std::cout << "constructor" << std::endl;
    }

    MenuState::~MenuState()
    {
        std::cout << "destructor" << std::endl;
    }

    void MenuState::initialize()
    {
        std::cout << "initialize" << std::endl;
    }

    void MenuState::tick()
    {}

    void MenuState::render()
    {}

    void MenuState::renderImGui()
    {
        ImGui::Begin("Menu");
        if(ImGui::Button("<-"))
        {
            std::cout << "click" << std::endl;
            root.createState<MenuState>();
        }
    }

    void MenuState::dispose()
    {
        std::cout << "dispose" << std::endl;
    }
}