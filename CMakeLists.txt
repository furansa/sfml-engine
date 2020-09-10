cmake_minimum_required(VERSION 3.1)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -pedantic")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/usr/lib/x86_64-linux-gnu/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(PoC Main.cpp Game.cpp Window.cpp)

target_link_libraries(PoC sfml-graphics)