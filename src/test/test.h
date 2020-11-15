#ifndef TEST_H
#define TEST_H

namespace test {

    class Test
    {
    public:
        Test();
        virtual ~Test();

        virtual void onUpdate(float deltaTime);
        virtual void onRender();
        virtual void onImGuiRender();
    };

}


#endif