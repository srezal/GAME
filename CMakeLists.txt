cmake_minimum_required(VERSION 3.24)
project(GAME)

set(CMAKE_CXX_STANDARD 17)

add_executable(GAME main.cpp Player.cpp PlayerManager.cpp Player.h PlayerManager.h Direction.h Vector.h Vector.cpp)
