set(EXAMPLE_HEADER_FILES
        base/example.h
        menu-example.h)

set(EXAMPLE_SOURCE_FILES
        menu-example.cpp)

add_library(example ${EXAMPLE_SOURCE_FILES} ${EXAMPLE_HEADER_FILES})