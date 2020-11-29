set(EXECUTABLE opengl-test-test)

set(SOURCE_FILES main-test.cpp
                 root/root-test.cpp)

set(HEADER_FILES )

add_executable(${EXECUTABLE} ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${EXECUTABLE} GLEW)
target_link_libraries(${EXECUTABLE} glfw)
target_link_libraries(${EXECUTABLE} OpenGL::GL)
target_link_libraries(${EXECUTABLE} glm)
target_link_libraries(${EXECUTABLE} imgui)
target_link_libraries(${EXECUTABLE} stb_image)
target_link_libraries(${EXECUTABLE} test)
target_link_libraries(${EXECUTABLE} gtest)
target_link_libraries(${EXECUTABLE} ${STATES_LIB})

target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_SOURCE_DIR}/lib/glm)
target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_SOURCE_DIR}/lib/imgui)
target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_SOURCE_DIR}/lib/stb_image)
target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_SOURCE_DIR}/lib/boost)
target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_SOURCE_DIR}/lib/googletest/googletest/include)
