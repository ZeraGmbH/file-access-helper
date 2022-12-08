add_test(NAME    file-access-helper-unittest
         COMMAND file-access-helper-unittest)

file(GLOB UNITTESTS
    tests/gtest/unittest-*.cpp
)

add_executable(file-access-helper-unittest
    ${UNITTESTS}
)

target_include_directories(file-access-helper-unittest
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

target_link_libraries(file-access-helper-unittest
    PUBLIC
    gtest
    gtest_main
    file-access-helper-lib
)
