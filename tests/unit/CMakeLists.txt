# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

include(CMakePrintHelpers)

add_executable(cpp23_test Bitmap1_test.cpp Bitmap2_test.cpp)

find_package(GTest)
target_link_libraries(cpp23_test 
        PRIVATE cpp23
        gtest::gtest)

include(GoogleTest)
gtest_discover_tests(cpp23_test)
