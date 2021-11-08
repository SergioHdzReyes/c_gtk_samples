cmake_minimum_required(VERSION 3.20)
project(sample1 C)

set(CMAKE_C_STANDARD 11)

add_executable(sample1
        sample1/main.c)

set(SOURCE_FILES sample1/main.c)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})