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

if(RSVisa_FOUND)
    target_link_libraries(mvisa PUBLIC rsvisa::visa)
    message("found lib visa!")
else()
    message("Lib visa not found!")
endif()

add_executable(
    VisaDemo 
    main.cpp
)

target_link_libraries(VisaDemo PRIVATE mvisa)

install(TARGETS VisaDemo
    DESTINATION bin)

install(TARGETS mvisa 
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib/myproject)

install (FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/base.h 
    DESTINATION include)
