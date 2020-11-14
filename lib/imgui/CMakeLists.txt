add_library(imgui imgui.cpp
        imgui_demo.cpp
        imgui_draw.cpp
        imgui_widgets.cpp)

add_subdirectory(glfw)
add_subdirectory(opengl3)