# Simulasi Peternakan Ayam Petelur (OpenGL 3.3)

Simulasi Peternakan Ayam Petelur adalah proyek mata kuliah **Grafika Komputer** berupa simulasi 3D alur kerja peternakan ayam petelur: visualisasi kandang, populasi ayam, proses pemberian makan, hingga pemanenan telur menggunakan gerobak roda satu.

> **Catatan:** Repo ini memakai **C++ + OpenGL 3.3 Core Profile** dan dibangun dengan **CMake**.

## Tim

* **Farhan** — Leader
* **Nopal**
* **Hapis**
* **Rehan**

## Tujuan & Alur Simulasi

1. Lingkungan kandang ditampilkan dalam scene 3D.
2. Terdapat **±300 ayam** (dirender efisien dengan **hardware instancing**).
3. Proses **pemberian pakan** memicu perubahan state (mis. animasi/reaksi) dan memunculkan telur.
4. **Gerobak roda satu** digunakan untuk **mengambil/memanen telur**.

## Teknologi

* **Bahasa:** C++17
* **Graphics API:** OpenGL 3.3 (Core Profile)
* **Windowing & Input:** GLFW
* **OpenGL Loader:** GLAD
* **Model Loading:** Assimp
* **Math Library:** GLM
* **Build System:** CMake

## Prasyarat

* GPU/driver yang mendukung **OpenGL 3.3 Core Profile**
* CMake ≥ 3.10
* Compiler C++ yang mendukung C++17 (GCC/Clang atau MinGW-w64)

## Struktur Folder

Struktur saat ini (ringkas):

```text
.
├─ CMakeLists.txt
├─ README.md
├─ src/
│  ├─ main.cpp
│  └─ glad.c
└─ build/                # hasil build (generated)
```

> Jika Anda menambahkan aset (model/texture/shader), direkomendasikan membuat folder `assets/` seperti:
>
> ```text
> assets/
> ├─ models/
> ├─ textures/
> └─ shaders/
> ```

## Instalasi Dependensi

### Linux (Ubuntu/Debian/Parrot) via `apt`

1) Update index paket:

```bash
sudo apt update
```

2) Install toolchain + library yang dibutuhkan:

```bash
sudo apt install -y \
	build-essential \
	cmake \
	pkg-config \
	libgl1-mesa-dev \
	libglfw3-dev \
	libglm-dev \
	libassimp-dev \
	libglad-dev
```

**Jika instalasi GLFW di mesin Anda meminta dependensi X11 tambahan**, pasang juga:

```bash
sudo apt install -y xorg-dev
```

> **Tentang GLAD:** Proyek ini meng-compile `src/glad.c` dan membutuhkan header `glad/glad.h` dari paket `libglad-dev` (atau alternatifnya, Anda bisa memasukkan header GLAD ke repo pada folder `include/`).

### Windows (disarankan MSYS2/MinGW + VS Code)

1) Install **MSYS2**: https://www.msys2.org/

2) Buka **MSYS2 MinGW 64-bit** dan install toolchain + dependensi:

```bash
pacman -Syu
pacman -S --needed \
	mingw-w64-x86_64-toolchain \
	mingw-w64-x86_64-cmake \
	mingw-w64-x86_64-make \
	mingw-w64-x86_64-glfw \
	mingw-w64-x86_64-assimp \
	mingw-w64-x86_64-glm \
	mingw-w64-x86_64-glad
```

3) VS Code: install extension berikut:

* **CMake Tools** (ms-vscode.cmake-tools)
* **C/C++** (ms-vscode.cpptools)

4) Buka folder proyek di VS Code, pilih kit compiler MinGW-w64, lalu Configure/Build via CMake Tools.

## Build & Run (Terminal)

Langkah standar (Linux/Windows MSYS2):

1) Buat folder build:

```bash
mkdir -p build
```

2) Generate build files:

```bash
cd build
cmake ..
```

3) Compile:

```bash
make -j
```

4) Jalankan program:

```bash
./SimulasiPeternakan
```

## Spesifikasi Teknis: Hardware Instancing (300 Ayam)

Untuk merender ratusan objek ayam secara efisien, proyek ini menargetkan teknik **hardware instancing**:

* Satu mesh ayam (vertex/index buffer) dipakai ulang.
* Data per-instance (mis. posisi/rotasi/scale atau matriks model) disimpan di **instance buffer**.
* Attribute per-instance diatur menggunakan `glVertexAttribDivisor(…, 1)`.
* Render dilakukan dengan satu (atau sedikit) draw call, seperti `glDrawElementsInstanced(...)`.

Keuntungan utama: **mengurangi overhead CPU** akibat banyak draw call, sehingga populasi **±300 ayam** lebih stabil dirender.

## Troubleshooting

* **"Gagal inisialisasi GLFW" / window tidak muncul**: pastikan driver GPU terpasang dan OpenGL 3.3 tersedia.
* **Error missing `glad/glad.h`**: install `libglad-dev` (Linux) / `mingw-w64-x86_64-glad` (MSYS2), atau commit header GLAD ke repo.
* **Linker error OpenGL**: pastikan `libgl1-mesa-dev` terpasang (Linux).

## Lisensi

Untuk kebutuhan tugas kuliah. Jika Anda memakai aset pihak ketiga (model/texture), pastikan mencantumkan lisensi/atribusi masing-masing aset.