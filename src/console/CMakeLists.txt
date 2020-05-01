cmake_minimum_required(VERSION 3.5.0)

project(console LANGUAGES C)

add_library(${PROJECT_NAME} SHARED "")

target_sources(${PROJECT_NAME} PUBLIC print_to_console.c print_to_console.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(${PROJECT_NAME} PUBLIC USING_LIB=${VALUE})

install(FILES print_to_console.h DESTINATION include)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib)