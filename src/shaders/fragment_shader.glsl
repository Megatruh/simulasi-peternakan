#version 330 core
out vec4 FragColor;

void main() {
    // gl_FrontFacing bernilai true jika kita melihat sisi depan poligon
    if (gl_FrontFacing) {
        // Warna cokelat tanah untuk bagian atas
        FragColor = vec4(0.45f, 0.30f, 0.15f, 1.0f);
    } else {
        // Warna hitam pekat untuk bagian bawah
        FragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);
    }
}