#ifndef TEST_CLEAR_COLOR_H
#define TEST_CLEAR_COLOR_H

#include <utils.h>
#include "test.h"

namespace test {

    class TestClearColor : public Test
    {
    private:
        float clearColor[4];
    public:
        TestClearColor();
        ~TestClearColor();

        void onUpdate(float deltaTime) override;
        void onRender() override;
        void onImGuiRender() override;
    };

}


#endif