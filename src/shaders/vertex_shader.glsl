#version 330 core
layout (location = 0) in vec3 aPos;

// Matriks transformasi yang dikirim dari C++
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    // Urutan perkalian matriks: Projection x View x Model x Posisi
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}