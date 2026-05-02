cmake_minimum_required(VERSION 3.10)

# Nama proyek kalian
project(SimulasiPeternakan)

# Gunakan standar C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Cari package yang dibutuhkan
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(assimp REQUIRED)

# Tambahkan stb_image.cpp ke dalam daftar source code
add_executable(SimulasiPeternakan 
    src/main.cpp 
    src/glad.c
    src/stb_image.cpp 
)
# Tautkan library ke executable
target_link_libraries(SimulasiPeternakan 
    glfw 
    OpenGL::GL 
    assimp 
)

# Include directories (opsional, jika kamu pakai folder include khusus)
target_include_directories(SimulasiPeternakan PRIVATE src)