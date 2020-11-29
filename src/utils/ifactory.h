#ifndef OPENGL_EXAMPLE_FACTORY
#define OPENGL_EXAMPLE_FACTORY

namespace OpenGlExample
{
    <template class T>
    class IFactory
    {
        virtual T create() const = 0;
    };
}

#endif