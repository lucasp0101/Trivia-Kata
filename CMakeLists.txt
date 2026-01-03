cmake_minimum_required(VERSION 3.23)

project(TriviaGame)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

option(BUILD_APPROVAL_TESTS_WITH_GTEST "Compile with sanitizers" OFF)
option(ENABLE_COVERAGE "Enable code coverage" OFF)

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


set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option -O0 -g -Werror")

if (ENABLE_COVERAGE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
endif()

if (USE_SANITIZERS)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=undefined -fsanitize=leak")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address -fsanitize=undefined -fsanitize=leak")
endif()

include(CTest)
enable_testing()
add_subdirectory(src)
add_subdirectory(test)
