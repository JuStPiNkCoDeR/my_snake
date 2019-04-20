cmake_minimum_required(VERSION 3.13)
project(Console_Snake)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(EXECUTABLE_NAME "MySnake")
add_executable(${EXECUTABLE_NAME} main.cpp Headers/game_field.h Functional/game_field.cpp Headers/relative_designer.h Functional/relative_designer.cpp Headers/wall.h Functional/wall.cpp Headers/snake.h Functional/snake.cpp Headers/Logs.h Functional/Logs.cpp Headers/Body.h Functional/Body.cpp)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()