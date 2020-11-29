#ifndef DI_CONTEXT_H
#define DI_CONTEXT_H

#include <di/di.hpp>
#include "bindings/states-binding.h"

auto injector = boost::di::make_injector(
    statesBinding()
);

#endif
