cmake_minimum_required(VERSION 3.7.2)
project(projet_c___client)
find_package(Threads)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Client.cpp Client.h)
add_executable(projet_c___client ${SOURCE_FILES})
target_link_libraries(projet_c___client ${CMAKE_THREAD_LIBS_INIT})
