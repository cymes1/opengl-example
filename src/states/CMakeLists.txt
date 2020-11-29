set(STATES_HEADER_FILES
        base/state.h
        enums/state-id.h
        menu-state.h)

set(STATES_SOURCE_FILES
        menu-state.cpp)

add_library(${STATES_LIB} ${STATES_SOURCE_FILES} ${STATES_HEADER_FILES})

target_include_directories(${STATES_LIB} PUBLIC ${PROJECT_SOURCE_DIR}/lib/imgui)
target_include_directories(${STATES_LIB} PUBLIC ${PROJECT_SOURCE_DIR}/src)
