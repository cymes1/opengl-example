#ifndef TEST_MENU_H
#define TEST_MENU_H

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include "test.h"

namespace test {

    class TestMenu : public Test
    {
    private:
        std::vector<std::pair<std::string, std::function<Test*()>>> tests;
        Test*& currentTest;

    public:
        TestMenu(Test*& currentTest);

        void onImGuiRender() override;

        template<typename T>
        void registerTest(const std::string& name)
        {
            std::cout << "Registering test: " << name << std::endl;
            tests.push_back(std::make_pair(name, []() { return new T(); }));
        }
    };

}


#endif