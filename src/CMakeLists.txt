add_executable(opengl-test
        main.cpp
        renderer.cpp
        vertex-buffer.cpp
        index-buffer.cpp)

target_link_libraries(opengl-test GLEW)
target_link_libraries(opengl-test glfw)
target_link_libraries(opengl-test OpenGL::GL)
