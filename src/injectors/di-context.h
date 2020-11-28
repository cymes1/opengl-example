#ifndef DI_CONTEXT_H
#define DI_CONTEXT_H

#include <di/di.hpp>
#include "bindings/examples-binding.h"

auto installBindings()
{
    return boost::di::make_injector(
            menuExampleBinding()
    );
}

#endif
