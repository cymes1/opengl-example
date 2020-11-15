add_library(test test.cpp
        test-menu.cpp
        test-clear-color.cpp)

target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/lib/imgui)
