cmake_minimum_required(VERSION 3.1.0)
project(myChess)

set(CMAKE_CXX_STANDARD 11)

set(SRC_DIRECTORY src)
set(INCLUDE_DIRECTORY headers)

set(SOURCES
    ${SRC_DIRECTORY}/Board.cpp
    ${SRC_DIRECTORY}/ParentPiece.cpp
    ${SRC_DIRECTORY}/Pieces.cpp
    ${SRC_DIRECTORY}/Helper.cpp
)

include_directories(${INCLUDE_DIRECTORY})
add_executable(${PROJECT_NAME}
    ${SRC_DIRECTORY}/main.cpp
    ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    sfml-system
    sfml-window
    sfml-graphics)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
