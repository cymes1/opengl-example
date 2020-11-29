#ifndef EXAMPLE_ROOT_H
#define EXAMPLE_ROOT_H

#include <states/menu-state.h>
#include "base/root.h"

namespace OpenGlExample
{
    class ExampleRoot : public Root<States::MenuState>
    {};
}

#endif