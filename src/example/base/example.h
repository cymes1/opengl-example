#ifndef OPENGL_TEST_EXAMPLE_H
#define OPENGL_TEST_EXAMPLE_H

namespace OpenGlExample::Example
{
    class Example
    {
    public:
        virtual ~Example() = default;

        virtual void tick() = 0;
        virtual void render() = 0;
        virtual void renderImGui() = 0;
    };
}

#endif