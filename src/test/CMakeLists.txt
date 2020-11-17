add_library(test test.cpp
        test-menu.cpp
        test-clear-color.cpp
        test-texture2d.cpp)

target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/lib/glm)
target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/lib/imgui)
target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/lib/stb_image)
