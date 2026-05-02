#version 330 core
out vec4 FragColor;

// Variabel penerima dari main.cpp
uniform vec4 objectColor;
uniform bool isLantai; 

void main() {
    if (isLantai && !gl_FrontFacing) {
        // Khusus lantai: bagian bawah tetap hitam pekat
        FragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);
    } else {
        // Untuk bagian atas lantai, kandang, dan ayam
        FragColor = objectColor;
    }
}