cmake_minimum_required(VERSION 3.29)

project(simple-cpp-project)

set(CMAKE_CXX_STANDARD 20)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic -fno-math-errno -fno-trapping-math")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-implicitly-unsigned-literal")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -fsanitize=address -fsanitize=undefined -fsanitize=bounds")

include(CMakePrintHelpers)
cmake_print_variables(CMAKE_CXX_FLAGS_DEBUG)
cmake_print_variables(CMAKE_BUILD_TYPE)

add_executable(main main.cpp)

# target_compile_options(main PRIVATE -Wall -Wextra -Werror -Wpedantic)

# target_compile_options(main PRIVATE -fsanitize=undefined,address)
# target_link_options(main PRIVATE -fsanitize=undefined,address)
