cmake_minimum_required(VERSION 3.30)

project(simple_opencv_test)

find_package(OpenCV 4 REQUIRED)

# c++17
set(CMAKE_CXX_STANDARD 17)

if (EMSCRIPTEN)
    # add_link_options(-l nodefs.js)
    # add_link_options(-sNODERAWFS)
    add_link_options(-sALLOW_MEMORY_GROWTH)
    add_compile_options(-fexceptions)
    add_link_options(-fexceptions)
else()
    # fail build process
    message(FATAL_ERROR "This project is only for Emscripten")
endif()

include_directories(${OpenCV_INCLUDE_DIRS})

# set $TARGET var is "main"
set(TARGET main)


add_executable(${TARGET} main.cpp)
# set_property(TARGET ${TARGET} APPEND_STRING PROPERTY LINK_FLAGS " -fuse-ld=${MY_LD}")
target_link_libraries(${TARGET} ${OpenCV_LIBS})
add_link_options("-fuse-ld=lld")
# target_link_options(main PRIVATE -Wl,--wrap=cv_imread)
# # add_link_options(-Wl)
add_link_options("-Wl,--wrap=cv_imread")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--wrap=cv_imread")
