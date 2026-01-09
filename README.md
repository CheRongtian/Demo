# Particle Heart

A cross-platform C++17 implementation of the popular "Particle Heart" animation often seen videos, like Bilibili(suitable for **Saint Valentine's Day** (˵¯͒〰¯͒˵) ).

This project ports the legacy Windows-only code (originally based on ```<graphics.h>``` and ```<conio.h>```) to modern C++ using ```raylib.h```:
```bash
brew install raylib
```
It is designed to run natively on macOS(M3).

I also added bgm from famous Japanese Anime: *Inuyasha: A Feudal Fairy Tale*, which is also suitable for the topic

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
    mv GreatVibes-Regular.ttf "Inuyasha - To Love's End - Erhu Cover by Eliott Tordo_MP3.mp3" build/
    ```

3.  **Compile with CMake**
    ```bash
    cmake ..
    make
    ```

4.  **Run the application**
    ```bash
    ./heart
    ```
## Web Version
You can check that version: https://github.com/CheRongtian/Demo/tree/web-version, and there is also a github page deployment~
