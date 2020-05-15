cmake_minimum_required(VERSION 3.5.0)
cmake_policy(SET CMP0076 NEW)

project(game LANGUAGES C)

add_library(${PROJECT_NAME} SHARED "")


target_sources(${PROJECT_NAME} PUBLIC game.c game.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

install(FILES game.h DESTINATION include)

install(TARGETS ${PROJECT_NAME}  DESTINATION lib)

