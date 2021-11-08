cmake_minimum_required(VERSION 3.20)
project(sample1 C)

set(CMAKE_C_STANDARD 11)

# Find dependencies
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
link_directories(${GTK3_LIBRARY_DIRS})
add_compile_options(${GTK3_CFLAGS_OTHER})
set(LIBRARIES ${LIBRARIES} ${GTK3_LIBRARIES})

set(FLAGS "-I${GTK3_INCLUDE_DIRS}")
message(STATUS "Flags: ${FLAGS}")
string(REPLACE ";" " -I" FLAGS "${FLAGS}")
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} ${GTK3_FLAGS} ${FLAGS})

# Compile
add_executable(main ${PROJECT_SOURCE_DIR}/sample1/main.c)
target_link_libraries(main ${LIBRARIES})