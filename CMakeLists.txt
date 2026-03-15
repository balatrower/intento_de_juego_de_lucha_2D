cmake_minimum_required(VERSION 4.1)
project(juegoPegarse2D)

# establcer standard de c++ y enforcarlo
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#decir a el ejecutable va a la carpeta build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../build)

#todo para que cmpile la libreria externa de SFML la primera vez que corre
include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG        3.0.2
)

FetchContent_MakeAvailable(SFML)

# listar archivos para la compilacion de el ejecutable
add_executable(
        juegoPegarse2D
        src/Main.cpp
        src/core/Game.cpp
        include/core/Game.h
        src/entities/Player.cpp
        include/entities/Player.h
        include/core/InputManager.h
        src/core/InputManager.cpp
)

# cambiar el path de los include en la carpeta include para los header files
target_include_directories(juegoPegarse2D PRIVATE include)

# linkear libreria SFML
target_link_libraries(juegoPegarse2D PRIVATE SFML::Graphics SFML::Window SFML::System)