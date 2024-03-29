set(STATES_HEADER_FILES
        roots/root.h
        states/base/state.h
        states/menu-state.h
        states/clear-color-state.h
        states/projection-matrix-state.h
        states/texture-2d-state.h
        states/basic-square-state.h
        states/basic-renderer-state.h
        )

set(STATES_SOURCE_FILES
        roots/root.cpp
        states/base/state.cpp
        states/menu-state.cpp
        states/clear-color-state.cpp
        states/projection-matrix-state.cpp
        states/texture-2d-state.cpp
        states/basic-square-state.cpp
        states/basic-renderer-state.cpp
        )

add_library(${STATES_LIB} ${STATES_SOURCE_FILES} ${STATES_HEADER_FILES})

target_link_libraries(${STATES_LIB} imgui)

target_include_directories(${STATES_LIB} PUBLIC ${PROJECT_SOURCE_DIR}/lib/imgui)
target_include_directories(${STATES_LIB} PUBLIC ${PROJECT_SOURCE_DIR}/lib/glm)
target_include_directories(${STATES_LIB} PUBLIC ${PROJECT_SOURCE_DIR}/lib/stb_image)
target_include_directories(${STATES_LIB} PUBLIC ${PROJECT_SOURCE_DIR}/src)
