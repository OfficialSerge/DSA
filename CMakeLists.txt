cmake_minimum_required(VERSION 3.14)
project(LeetCodePractice VERSION 0.0.1 DESCRIPTION "Leetcode" LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Tell cmake to make compile_commands.json
# this helps clang auto complete and is SUPER important!
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Update submodules here to use latest gtest version
include(cmake/UpdateSubmodules.cmake)

# Enable testing for this project
enable_testing()
include(CTest)
include(GoogleTest)

# 1. Add dependencies
add_subdirectory(external/googletest)

function(register_topic_tests TOPIC_NAME)
    set(SRC_DIR ${CMAKE_SOURCE_DIR}/src/${TOPIC_NAME})
    set(TEST_DIR ${CMAKE_SOURCE_DIR}/tests/${TOPIC_NAME})
    file(GLOB TEST_FILES "${TEST_DIR}/*_test.cpp")

    foreach(TEST_FILE ${TEST_FILES})
        get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
        string(REPLACE "_test" "" IMPL_NAME ${TEST_NAME})
        set(IMPL_FILE "${SRC_DIR}/${IMPL_NAME}.cpp")
        if(EXISTS "${IMPL_FILE}")
            add_executable(${TEST_NAME} ${IMPL_FILE} ${TEST_FILE})
            target_include_directories(${TEST_NAME} PRIVATE ${SRC_DIR})
            target_link_libraries(${TEST_NAME} PRIVATE GTest::gtest_main)
            gtest_discover_tests(${TEST_NAME})
        else()
            message(WARNING "Missing implementation for test: ${TEST_NAME}")
        endif()
    endforeach()
endfunction()


# 2. Register tests
register_topic_tests(arrays)
register_topic_tests(lists)
register_topic_tests(heaps)
register_topic_tests(recursion)
