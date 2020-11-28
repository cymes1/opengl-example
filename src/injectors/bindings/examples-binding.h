#ifndef EXAMPLES_BINDING_H
#define EXAMPLES_BINDING_H

#include <di/di.hpp>
#include <example/menu-example.h>

using namespace OpenGlExample::Example;

auto menuExampleBinding()
{
    return boost::di::make_injector(
        boost::di::bind<class OpenGlExample::TInitialExample>().to<MenuExample>()
    );
}

#endif
