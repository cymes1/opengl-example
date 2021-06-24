#include "menu-state.h"
#include <imgui.h>
#include <states/states/clear-color-state.h>
#include <states/states/texture-2d-state.h>

namespace OpenGlExample::States
{
    MenuState::MenuState(Root& root)
            : State(root)
    {}

    void MenuState::initialize()
    {
        registerTest<OpenGlExample::States::ClearColorState>("Clear Color");
        registerTest<OpenGlExample::States::Texture2DState>("Texture 2D");
    }

    void MenuState::renderImGui()
    {
        ImGui::Begin("Menu");
        for(auto& test : examples)
        {
            if(ImGui::Button(test.first.c_str()))
                test.second(root);
        }
    }
}