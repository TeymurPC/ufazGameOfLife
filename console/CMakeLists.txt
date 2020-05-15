cmake_minimum_required(VERSION 3.5.0)
cmake_policy(SET CMP0076 NEW)

project(console LANGUAGES C)

add_library(${PROJECT_NAME} SHARED "")

target_sources(${PROJECT_NAME} PUBLIC print_to_console.c print_to_console.h )

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )


install(FILES print_to_console.h DESTINATION include)

install(TARGETS ${PROJECT_NAME} DESTINATION lib)