cmake_minimum_required(VERSION 3.5.0)


project(ufazGameOfLife LANGUAGES C)

add_executable(${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PUBLIC main.c game.c print_to_console.c)


