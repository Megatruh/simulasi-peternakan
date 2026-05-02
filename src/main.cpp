#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    // 1. Inisialisasi GLFW
    if (!glfwInit()) {
        std::cerr << "Gagal inisialisasi GLFW" << std::endl;
        return -1;
    }
    
    // Konfigurasi agar menggunakan OpenGL versi 3.3 Core Profile (Standar Modern)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 2. Buat Jendela (Window)
    GLFWwindow* window = glfwCreateWindow(800, 600, "Simulasi Peternakan Ayam", NULL, NULL);
    if (!window) {
        std::cerr << "Gagal membuat jendela GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // 3. Inisialisasi GLAD (Menggantikan GLEW)
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Gagal inisialisasi GLAD" << std::endl;
        return -1;
    }

    std::cout << "Versi OpenGL yang didukung: " << glGetString(GL_VERSION) << std::endl;

    // 4. Render Loop (Terus berjalan sampai jendela ditutup)
    while (!glfwWindowShouldClose(window)) {
        // Bersihkan layar dengan warna biru langit
        glClearColor(0.5f, 0.8f, 0.9f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Tukar buffer dan periksa event
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 5. Bersihkan memori saat selesai
    glfwTerminate();
    return 0;
}