cmake_minimum_required(VERSION 3.10)

# Nama proyek kalian
project(SimulasiPeternakan)

# Gunakan standar C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Tambahkan src/glad.c di sini
add_executable(SimulasiPeternakan src/main.cpp src/glad.c)

# Hubungkan (link) library OpenGL, GLFW, dan Assimp
target_link_libraries(SimulasiPeternakan
    GL
    glfw
    dl
    assimp
)