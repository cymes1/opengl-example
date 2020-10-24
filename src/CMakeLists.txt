add_executable(opengl-test main.cpp)

target_link_libraries(opengl-test GLEW)
target_link_libraries(opengl-test glfw)
target_link_libraries(opengl-test OpenGL::GL)
