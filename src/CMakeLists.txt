cmake_minimum_required(VERSION 3.6)

project(mon_usb)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp sub_parser.cpp main_parser.cpp monitor.cpp)
target_link_libraries(main yaml-cpp)

add_executable(ConfigGen ConfigGen.cpp)
target_link_libraries(ConfigGen stdc++fs)
