# Dear ImGUI Template to Start

## Modules

- GLFW
- GLAD
- ImGui
- ImPlot

## Software Dependencies

- OpenGL3 (should be already installed)
- CMake
- Unix: GCC, Clang
- Windows: MSVC x86 Compiler

### Installation

#### Windows

Cmake: <https://cmake.org/download/>  
MSVC Compiler: <https://visualstudio.microsoft.com/de/downloads/?q=build+tools>  

#### Linux

```bash
sudo apt-get install cmake
```

#### MacOS

```bash
brew install cmake
```

## Extra Settings

```json
  "clang-tidy.compilerArgsBefore": [
    "-Iexternal/imgui",
    "-D_CRT_SECURE_NO_WARNINGS"
  ],
  "clang-tidy.compilerArgs": [
    "-std=c++17"
  ]
```
