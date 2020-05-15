cmake_minimum_required(VERSION 3.5.0)
cmake_policy(SET CMP0076 NEW)

project(ufazGameOfLife LANGUAGES C)


add_subdirectory(game)
add_subdirectory(console)

#add_library(${PROJECT_NAME} SHARED "")

set(SRC main.c)

add_executable(${PROJECT_NAME} "" )

target_sources(${PROJECT_NAME} PUBLIC ${SRC} )

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC gcov)
target_compile_options(${PROJECT_NAME} PUBLIC "--coverage")

set(Game_Test libtest )
add_executable(${Game_Test} "" )
target_sources(${Game_Test} PUBLIC game_test.c)
target_link_libraries(${Game_Test} PUBLIC game cunit)

enable_testing()
add_test(NAME "Game_Test" COMMAND ${Game_Test})

add_custom_target(cover
COMMAND cmake --build . --target libtest 
COMMAND gcovr -r ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} $<TARGET_FILE:${Game_Test}>
WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_custom_target(cover_html
COMMAND cmake --build . --target libtest 
COMMAND gcovr  --html --html-details -o GameOfLife.html -r ${CMAKE_SOURCE_DIR}${CMAKE_BINARY_DIR} $<TARGET_FILE:${Game_Test}>
WORKING_DIRECTORY ${CMAKE_BINARY_DIR})


target_link_libraries(${PROJECT_NAME} PUBLIC game console)

install(TARGETS ${PROJECT_NAME}  DESTINATION bin)


