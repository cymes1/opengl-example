#include "root.h"
#include <imgui.h>
#include <opengl3/imgui_impl_opengl3.h>
#include <glfw/imgui_impl_glfw.h>

namespace OpenGlExample
{
    void Root::tick() const
    {
        currentState->tick();
    }

    void Root::render() const
    {
        currentState->render();
    }

    void Root::renderImGui() const
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        currentState->renderImGui();
        ImGui::Separator();
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
}