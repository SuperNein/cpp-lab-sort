cmake_minimum_required(VERSION 3.16)
project(lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Default: Debug
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type: Debug | Release | RelWithDebInfo" FORCE)
endif()

add_library(compiler_warnings INTERFACE)
if(MSVC)
    target_compile_options(compiler_warnings INTERFACE /W4 /Zi)
    target_link_options(compiler_warnings INTERFACE /DEBUG)
else()
    target_compile_options(compiler_warnings INTERFACE -Wall -Wextra -Wpedantic -Werror -g)
endif()

# Source files
file(GLOB SRC_FILES CONFIGURE_DEPENDS src/*.cpp)
set(LIB_SRC_FILES ${SRC_FILES})
list(REMOVE_ITEM LIB_SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

# Build
add_executable(lab ${SRC_FILES})
target_include_directories(lab PRIVATE include)
target_link_libraries(lab PRIVATE compiler_warnings)

# Google Test
include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.15.2
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

# Test files
file(GLOB TEST_FILES CONFIGURE_DEPENDS tests/*.cpp)
add_executable(lab_tests
    ${TEST_FILES}
    ${LIB_SRC_FILES}
)

target_include_directories(lab_tests PRIVATE include)
target_link_libraries(lab_tests PRIVATE 
    compiler_warnings 
    GTest::gtest_main
)

gtest_discover_tests(lab_tests)
