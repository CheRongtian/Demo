# Particle Heart

A cross-platform C++17 implementation of the popular "Particle Heart" animation often seen videos, like Bilibili(suitable for **Saint Valentine's Day** (˵¯͒〰¯͒˵) ).

This project ports the legacy Windows-only code (originally based on ```<graphics.h>``` and ```<conio.h>```) to modern C++ using ```raylib.h```:
```bash
brew install raylib
```
It is designed to run natively on macOS(M3).

I also added bgm from famous Japanese Anime: *Inuyasha: A Feudal Fairy Tale*, *To Love's End*, which is also suitable for the topic

## Features

- **Cross-Platform**: Built with [Raylib](https://www.raylib.com/), replacing the obsolete Windows GDI dependency. Runs smoothly on macOS.
- **Modern Build System**: Uses CMake for easy compilation and dependency management.
- **Optimized**: Refactored to use standard C++ containers (`std::vector`) and pre-rendered textures for better performance.

## Requirements

To build and run this project, you need the following installed on your system:

- C++ Compiler, like Clang, GCC, or MSVC (I use clang)
- CMake (Version 3.10 or higher)
- Raylib


## Build & Run

Follow these steps to compile and run the animation:

1.  **Clone the repository**
    ```bash
    git clone https://github.com/CheRongtian/Demo.git
    cd Demo
    ```

2.  **Create a build directory**
    ```bash
    mkdir build
    cd build
    ```

3.  **Compile with CMake**
    ```bash
    emcmake cmake ..
    make
    ```

4.  **Run the application**
    ```bash
    python3 -m http.server
    ```

5.  **Open the test web**

    Open browser, then go to http://localhost:8000/heart.html, click the screen to hear the bgm
    use ```control``` + ```C``` in the shell to end the program

## Link
Visit the link to check the final outcome
https://cherongtian.github.io/Demo/, and do not forget to click to unlock the bgm.