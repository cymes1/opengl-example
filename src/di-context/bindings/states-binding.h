#ifndef STATES_BINDING_H
#define STATES_BINDING_H

#include <di/di.hpp>

namespace OpenGlExample
{
    class IRoot;
    class ExampleRoot;
}

auto statesBinding()
{
    return boost::di::make_injector(
        boost::di::bind<OpenGlExample::IRoot>.to<OpenGlExample::ExampleRoot>().in(boost::di::singleton)
    );
}

#endif
