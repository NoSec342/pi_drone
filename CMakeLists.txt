cmake_minimum_required(VERSION 3.0)

project(pi_drone)

add_executable(pi_drone main.cpp)

install(TARGETS pi_drone RUNTIME DESTINATION bin)
add_library(pi_sock SHARED pi_sock.cpp pi_sock.hpp)
add_library(pi_serial SHARED pi_serial.cpp pi_serial.hpp)
target_link_libraries(pi_drone PUBLIC pi_sock pi_serial)
