cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(main)

include_directories(${PROJECT_SOURCE_DIR}/inc)
file(GLOB a_start_SRC CONFIGURE_DEPENDS "*.h" "src/*.cpp")

add_executable(main src/main.cpp ${a_star_SRC})

install(TARGETS main)

enable_testing()
add_test(NAME main COMMAND main)
