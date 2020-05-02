cmake_minimum_required(VERSION 3.5.0)

project(ufazGameOfLife LANGUAGES C)


add_subdirectory(game)
add_subdirectory(console)

set(SRC main.c)

add_executable(${PROJECT_NAME} main.c)

target_sources(${PROJECT_NAME} PUBLIC ${SRC} )

target_link_libraries(${PROJECT_NAME} PUBLIC game)
target_link_libraries(${PROJECT_NAME} PUBLIC console)

install(TARGETS ${PROJECT_NAME}  RUNTIME DESTINATION buildCMake)


