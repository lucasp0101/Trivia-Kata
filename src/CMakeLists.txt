set(SRC_LIB_NAME GameLib)
set(TESTING_LIB_NAME GameLib_ForTesting)

set(GAME_RUNNER_NAME GameRunner)

set(INC_LIB_NAME include)

add_library(${SRC_LIB_NAME} Game.cpp Player.cpp)
target_sources(${SRC_LIB_NAME} PRIVATE ${INC_LIB_NAME}/Game.h ${INC_LIB_NAME}/Player.h ${INC_LIB_NAME}/Question.h)
target_include_directories(${SRC_LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/${INC_LIB_NAME})

add_executable(${GAME_RUNNER_NAME} GameRunner.cpp)
target_link_libraries(${GAME_RUNNER_NAME} ${SRC_LIB_NAME})
target_sources(${GAME_RUNNER_NAME} PRIVATE ${INC_LIB_NAME}/Game.h)
target_include_directories(${GAME_RUNNER_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/${INC_LIB_NAME})

add_library(${TESTING_LIB_NAME} GameRunner_ForTesting.cpp)
target_link_libraries(${TESTING_LIB_NAME} ${SRC_LIB_NAME})
target_sources(${TESTING_LIB_NAME} PRIVATE ${INC_LIB_NAME}/Game.h ${INC_LIB_NAME}/GameRunner_ForTesting.h)
target_include_directories(${TESTING_LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/${INC_LIB_NAME})