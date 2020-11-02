add_executable(opengl-test
        main.cpp
        utils.cpp
        renderer.cpp
        vertex-buffer.cpp
        vertex-array.cpp
        vertex-buffer-layout.cpp
        index-buffer.cpp
        shader.cpp)

target_link_libraries(opengl-test GLEW)
target_link_libraries(opengl-test glfw)
target_link_libraries(opengl-test OpenGL::GL)
