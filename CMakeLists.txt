cmake_minimum_required(VERSION 3.22)
project(PAC_MAN)

set(CMAKE_CXX_STANDARD 17)

add_executable(PAC_MAN main.cpp Game.cpp Character.cpp Pacman.cpp Maze.cpp)

set(SFML_DIR SFML/lib/cmake/SFML)
find_package(SFML 2.5 COMPONENTS graphics)
target_link_libraries(PAC_MAN sfml-graphics)

if(WIN32)
    file(GLOB BINARY_DEP_DLLS SFML/bin/*.dll)
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
