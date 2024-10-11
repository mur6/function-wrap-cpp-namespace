cmake_minimum_required(VERSION 3.29)

project(simple_opencv_test)

find_package(OpenCV 4 REQUIRED)

set(CMAKE_CXX_STANDARD 17)

if (EMSCRIPTEN)
    add_link_options(-l nodefs.js)
    add_link_options(-sNODERAWFS)
    add_link_options(-sALLOW_MEMORY_GROWTH)

    add_compile_options(-fexceptions)
    add_link_options(-fexceptions)
endif()

include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(main main.cpp)
target_link_libraries(main ${OpenCV_LIBS})
