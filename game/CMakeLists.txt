cmake_minimum_required(VERSION 3.5.0)

project(game LANGUAGES C)

add_library(${PROJECT_NAME} SHARED "")

target_sources(${PROJECT_NAME} PUBLIC game.c game.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC gcov)
target_compile_options(${PROJECT_NAME} PUBLIC "--coverage")

set(Game_Test libtest )
add_executable(${Game_Test} "")
target_sources(${Game_Test} PUBLIC game_test.c)
target_link_libraries(${Game_Test} PUBLIC ${Project_Name} cunit)


enable_testing()
add_test(NAME "Game_Test" COMMAND ${Game_Test})

add_custom_target(cover
COMMAND cmake --build  . --target test 
COMMAND gcovr -r ${CMAKE_BINARY_DIR} $<TARGET_FILE:${Game_Test}>
WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_custom_target(cover_html
COMMAND cmake --build  . --target test 
COMMAND gcovr --hrml --html-detail -o index.html -r ${CMAKE_BINARY_DIR} $<TARGET_FILE:${Game_Test}>
WORKING_DIRECTORY ${CMAKE_BINARY_DIR})



install(FILES game.h DESTINATION include)

install(TARGETS ${PROJECT_NAME} DESTINATION lib)

