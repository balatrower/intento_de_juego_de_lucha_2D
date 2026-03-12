cmake_minimum_required(VERSION 4.1)
project(juegoPegarse2D)

set(CMAKE_CXX_STANDARD 26)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
)

FetchContent_MakeAvailable(SFML)

add_executable(juegoPegarse2D main.cpp)

target_link_libraries(juegoPegarse2D PRIVATE sfml-graphics sfml-window sfml-system)