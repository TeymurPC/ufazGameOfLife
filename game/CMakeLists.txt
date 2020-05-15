cmake_minimum_required(VERSION 3.5.0)

project(game LANGUAGES C)

add_library(${PROJECT_NAME} SHARED "")


target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC gcov)
target_compile_options(${PROJECT_NAME} PUBLIC "--coverage")

install(FILES game.h DESTINATION include)

install(TARGETS ${PROJECT_NAME} DESTINATION lib)

