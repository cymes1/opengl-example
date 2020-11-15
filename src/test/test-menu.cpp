#include "test-menu.h"
#include <imgui.h>

namespace test {

    TestMenu::TestMenu(Test*& currentTest)
        : currentTest(currentTest)
    {
    }

    void TestMenu::onImGuiRender()
    {
        for(auto& test : tests)
        {
            if(ImGui::Button(test.first.c_str()))
                currentTest = test.second();
        }
    }

}