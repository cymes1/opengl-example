set(STATES_HEADER_FILES
        enums/state-id.h
        roots/base/iroot.h
        roots/root.h
        states/base/state.h
        states/menu-state.h
        states/clear-color-state.h
        states/texture-2d-state.h
        )

set(STATES_SOURCE_FILES
        roots/root.cpp
        states/base/state.cpp
        states/menu-state.cpp
        states/clear-color-state.cpp
        states/texture-2d-state.cpp
        )

add_library(${STATES_LIB} ${STATES_SOURCE_FILES} ${STATES_HEADER_FILES})

target_include_directories(${STATES_LIB} PUBLIC ${PROJECT_SOURCE_DIR}/lib/imgui)
target_include_directories(${STATES_LIB} PUBLIC ${PROJECT_SOURCE_DIR}/lib/glm)
target_include_directories(${STATES_LIB} PUBLIC ${PROJECT_SOURCE_DIR}/lib/stb_image)
target_include_directories(${STATES_LIB} PUBLIC ${PROJECT_SOURCE_DIR}/src)
