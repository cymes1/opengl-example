#include "clear-color-state.h"
#include <imgui.h>
#include <states/states/menu-state.h>
#include <utils.h>

namespace OpenGlExample::States
{
    ClearColorState::ClearColorState(Root& root)
        : State(root),
        clearColor { 0.2f, 0.3f, 0.8f, 1.0f }
    {}

    void ClearColorState::render()
    {
        GLCall(glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]));
        GLCall(glClear(GL_COLOR_BUFFER_BIT));
    }

    void ClearColorState::renderImGui()
    {
        ImGui::Begin("ClearColor");
        if(ImGui::Button("<-"))
        {
            root.createState<MenuState>();
        }
        ImGui::ColorEdit4("Clear Color", clearColor);
    }
}