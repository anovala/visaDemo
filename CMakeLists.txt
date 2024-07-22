cmake_minimum_required(VERSION 3.21)
project(VisaDemo VERSION 1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
list(APPEND CMAKE_PREFIX_PATH "C:/Program Files (x86)/IVI Foundation/VISA/WinNT")

add_executable(
    VisaDemo 
    src/main.cpp
    src/base.h
    src/base.cpp
)

find_package(RSVisa CONFIG REQUIRED)

target_include_directories(VisaDemo PRIVATE "C:/Program Files (x86)/IVI Foundation/VISA/WinNT/Include")
target_link_directories(VisaDemo PRIVATE "C:/Program Files (x86)/IVI Foundation/VISA/WinNT/Lib_x64/msc")
target_link_libraries(VisaDemo PRIVATE rsvisa::visa)