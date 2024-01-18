cmake_minimum_required(VERSION 3.5)

project(hw-005)

set(SOURCES src/main.cpp)

set(LIB     src/lib/IStatistics.h)

add_executable(hw-005   ${SOURCES})

set_target_properties(hw-005 PROPERTIES     CXX_STANDARD 17
                                            CXX_STANDARD_REQUIRED ON)