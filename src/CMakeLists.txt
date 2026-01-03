set(SRC_LIB_NAME GameLib)
set(INC_LIB_NAME include)
set(GAME_RUNNER_NAME GameRunner)

add_executable(${GAME_RUNNER_NAME} GameRunner.cpp Game.cpp)
add_library(${SRC_LIB_NAME} Game.cpp)
add_library(GameLib_ForTesting Game.cpp GameRunner_ForTesting.cpp)

target_sources(${SRC_LIB_NAME} PRIVATE ${INC_LIB_NAME}/Game.h)
target_sources(GameLib_ForTesting PRIVATE ${INC_LIB_NAME}/Game.h ${INC_LIB_NAME}/GameRunner_ForTesting.h)
target_sources(${GAME_RUNNER_NAME} PRIVATE ${INC_LIB_NAME}/Game.h)

target_include_directories(${SRC_LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/${INC_LIB_NAME})
target_include_directories(GameLib_ForTesting PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/${INC_LIB_NAME})
target_include_directories(${GAME_RUNNER_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/${INC_LIB_NAME})