#version 330 core
layout (location = 0) in vec3 aPos; // Mengambil input posisi dari C++

void main() {
    // gl_Position adalah variabel bawaan untuk menentukan posisi akhir vertex
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}