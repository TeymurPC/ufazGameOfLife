cmake_minimum_required(VERSION 3.5.0)

project(game LANGUAGES C)

add_library(${PROJECT_NAME} SHARED "")

target_sources(${PROJECT_NAME} PUBLIC game.c game.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} )

target_compile_definitions(${PROJECT_NAME} PUBLIC USING_LIB=${VALUE})

install(FILES game.h DESTINATION include)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib)

