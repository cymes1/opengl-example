set(EXECUTABLE opengl-test)

set(HEADER_FILES
        )

set(SOURCE_FILES main.cpp
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
add_subdirectory(test)

target_link_libraries(${EXECUTABLE} GLEW)
target_link_libraries(${EXECUTABLE} glfw)
target_link_libraries(${EXECUTABLE} OpenGL::GL)
target_link_libraries(${EXECUTABLE} glm)
target_link_libraries(${EXECUTABLE} imgui)
target_link_libraries(${EXECUTABLE} stb_image)
target_link_libraries(${EXECUTABLE} test)
target_link_libraries(${EXECUTABLE} ${STATES_LIB})

target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_SOURCE_DIR}/lib/glm)
target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_SOURCE_DIR}/lib/imgui)
target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_SOURCE_DIR}/lib/stb_image)
target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_SOURCE_DIR}/lib/boost)
