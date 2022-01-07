set(EXECUTABLE opengl-example)

set(HEADER_FILES
        debug/debug-callback.h
        renderer/basic-renderer.h
        renderer/sprite.h
        utils/keys.h
        )

set(SOURCE_FILES main.cpp
        debug/debug-callback.cpp
        renderer/basic-renderer.cpp
        renderer/sprite.cpp
        )

add_executable(${EXECUTABLE} ${SOURCE_FILES}
        index-buffer.cpp
        renderer.cpp
        shader.cpp
        texture.cpp
        vertex-buffer.cpp
        vertex-array.cpp
        vertex-buffer-layout.cpp
        utils.cpp
        ${HEADER_FILES})

add_subdirectory(states)

target_link_libraries(${EXECUTABLE} GLEW)
target_link_libraries(${EXECUTABLE} glfw)
target_link_libraries(${EXECUTABLE} OpenGL::GL)
target_link_libraries(${EXECUTABLE} glm)
target_link_libraries(${EXECUTABLE} imgui)
target_link_libraries(${EXECUTABLE} stb_image)
target_link_libraries(${EXECUTABLE} ${STATES_LIB})

target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_SOURCE_DIR}/lib/glm)
target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_SOURCE_DIR}/lib/imgui)
target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_SOURCE_DIR}/lib/stb_image)
target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_SOURCE_DIR}/lib/boost)
