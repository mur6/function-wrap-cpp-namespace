cmake_minimum_required(VERSION 3.30)

project(simple_opencv_test)

find_package(OpenCV 4 REQUIRED)

# c++17
set(CMAKE_CXX_STANDARD 17)

if (EMSCRIPTEN)
    add_link_options(-l nodefs.js)
    add_link_options(-sNODERAWFS)
    add_link_options(-sALLOW_MEMORY_GROWTH)
    add_compile_options(-fexceptions)
    add_link_options(-fexceptions)
else()
    # fail build process
    message(FATAL_ERROR "This project is only for Emscripten")
endif()

include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(main src/main.cpp)
target_link_libraries(main ${OpenCV_LIBS})

option(USE_LINKER_WRAP_FUNC "Use linker wrap function" OFF)
message(STATUS "USE_LINKER_WRAP_FUNC: ${USE_LINKER_WRAP_FUNC}")
if (USE_LINKER_WRAP_FUNC)
    add_link_options("-fuse-ld=lld")
    add_link_options("-Wl,--wrap=cv_imread")
endif()
