cmake_minimum_required(VERSION 3.23)

project(TriviaGame)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(FetchContent)
FetchContent_Declare(
    catch2 
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.0
    GIT_SHALLOW TRUE
  )

FetchContent_Declare(
    approval_tests 
    GIT_REPOSITORY https://github.com/approvals/ApprovalTests.cpp
    GIT_TAG v.10.13.0
    GIT_SHALLOW TRUE
  )
FetchContent_MakeAvailable(catch2 approval_tests)

set(CMAKE_CXX_FLAGS "--coverage -O0 -g")

include(CTest)
enable_testing()
add_subdirectory(src)
add_subdirectory(test)
