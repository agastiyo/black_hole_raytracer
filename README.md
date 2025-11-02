# black_hole_raytracer

A simple 3-D raytracing engine to visualize Black Holes with customizable spacetime metrics.

## Prerequisites

To build and run this project, you'll need:

- CMake (version 3.15 or higher)
- A C++17 compatible compiler:
  - GCC 7+ on Linux
  - Clang 8+ on macOS
  - MSVC 2019+ on Windows
- Git (for cloning the repository)

## Getting Started

### Clone the Repository

```bash
git clone https://github.com/agastiyo/black_hole_raytracer.git
cd black_hole_raytracer
```

### Build the Project

```bash
# Create and enter build directory
mkdir -p build
cd build

# Configure the project
cmake ..

# Build
cmake --build .
```

### Run the Program

```bash
# From the build directory
./bin/black_hole_raytracer
```

The program will generate a PPM image file at `output/image.ppm` showing the raytraced scene.

## Common Development Tasks

### Adding New Files

When adding new source files:

1. Add your `.h` and `.cpp` files to the appropriate directory under `src/`
2. Reconfigure CMake to detect the new files:

   ```bash
   cd build
   cmake ..
   cmake --build .
   ```

### Modifying Existing Files

When only modifying existing files:

1. Make your changes
2. Rebuild (no need to reconfigure CMake):

   ```bash
   cd build
   cmake --build .
   ```

### Clean Build

If you need to start fresh:

```bash
# From project root
rm -rf build/*
mkdir -p build
cd build
cmake ..
cmake --build .
```

## Output

The program generates a PPM (Portable Pixmap) format image file. You can:

- View it directly with image viewers that support PPM
- Convert it to other formats using tools like ImageMagick:

  ```bash
  convert output/image.ppm output/image.png
  ```
