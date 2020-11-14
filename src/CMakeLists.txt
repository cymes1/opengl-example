add_executable(opengl-test
        main.cpp
        index-buffer.cpp
        renderer.cpp
        shader.cpp
        texture.cpp
        vertex-buffer.cpp
        vertex-array.cpp
        vertex-buffer-layout.cpp
        utils.cpp)

target_link_libraries(opengl-test GLEW)
target_link_libraries(opengl-test glfw)
target_link_libraries(opengl-test OpenGL::GL)
target_link_libraries(opengl-test glm)
target_link_libraries(opengl-test imgui)
target_link_libraries(opengl-test imgui_impl_glfw)
target_link_libraries(opengl-test imgui_impl_opengl3)
target_link_libraries(opengl-test stb_image)

target_include_directories(opengl-test PUBLIC ${PROJECT_SOURCE_DIR}/lib/glm)
target_include_directories(opengl-test PUBLIC ${PROJECT_SOURCE_DIR}/lib/imgui)
target_include_directories(opengl-test PUBLIC ${PROJECT_SOURCE_DIR}/lib/stb_image)
