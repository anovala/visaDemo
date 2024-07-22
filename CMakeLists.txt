cmake_minimum_required(VERSION 3.21)
project(visa VERSION 1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
list(APPEND CMAKE_PREFIX_PATH "C:/Program Files (x86)/IVI Foundation/VISA/WinNT")

file(GLOB_RECURSE HEADERS "src/*.h" "global/global.h")
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_library(mvisa SHARED 
    ${HEADERS}
    ${SOURCES}
)

target_compile_definitions(
    mvisa 
    PRIVATE
    M_PLUGIN_LIB
)

find_package(RSVisa CONFIG REQUIRED)
target_link_libraries(mvisa PUBLIC rsvisa::visa)

add_executable(
    VisaDemo 
    main.cpp
)

target_link_libraries(VisaDemo PRIVATE mvisa)
