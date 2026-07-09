# 1. Definimos la versión mínima de CMake instalada en el sistema
cmake_minimum_required(VERSION 3.10)

# 2. Le damos un nombre oficial a este nuevo proyecto
project(ControlAccesoInteligent_CA LANGUAGES CXX)

# 3. Le indicamos a C++ que trabaje con el estándar moderno C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 4. Le decimos a CMake dónde ir a buscar los planos (.h)
include_directories(include)

# 5. Creamos el ejecutable final enlazando el main con nuestra lógica
add_executable(Acceso_App 
    main.cpp
    src/Usuario.cpp
    src/Relay.cpp
)