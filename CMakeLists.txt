# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

cmake_minimum_required(VERSION 3.23)

project(cpp23 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

option(WITH_TESTS "build tests?" ON)

add_library(cpp23 src/cpp23.cpp)
target_include_directories(cpp23 PUBLIC include)

if(WITH_TESTS)
  list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")
  enable_testing()
  add_subdirectory(tests)
endif()
