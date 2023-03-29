cmake_minimum_required(VERSION 3.22.1)

set(ThisTest ExampleTests)

set(SourcesTest
    ExampleTests.cpp
)

#add_executable(KRET KRET.cpp)
add_executable(ExampleTests ExampleTests.cpp)

target_link_libraries(ExampleTests PUBLIC
    gtest_main
    KRET
)

add_test(
    NAME ExampleTests
    COMMAND ExampleTests
)