cmake_minimum_required(VERSION 3.0)

project(pi_drone)

add_executable(pi_drone main.cpp)

install(TARGETS pi_drone RUNTIME DESTINATION bin)

find_library(wiringPi_LIB wiringPi)
add_library(pi_sock SHARED pi_sock.cpp pi_sock.hpp)
add_library(pi_motorctl SHARED pi_motorctl.cpp pi_motorctl.hpp)
target_link_libraries(pi_drone PUBLIC  pi_sock pi_motorctl  ${wiringPi_LIB} )

