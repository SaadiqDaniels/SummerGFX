# SummerGFX
A summer static graphics library

## Project Goals
The goal of this project is to be able to write identical-interface graphics libraries that can be swapped out depending on the desired underlying implementation with zero problems during switching.
The reason for this is two-fold, it may be easier to support some graphics libraries on some platforms. 
DirectX12 was made for Windows but straight up does not work on OSX. 
By tackling the challenges of platform agnostic code, I will learn to be a better programmer.
Additionally, I do not know enough about the graphics pipeline to call myself a graphics programmer, with this project I will be able to study all four major graphics implementations and learn each of their quirks/use cases.

## Targeted Graphics Libraries
The four target graphics libraries are:
- OpenGL
- Vulkan
- DirectX12
- DirectX9

These four will allow me to understand both simple graphics libraries and more complex libraries.

## General Code
The main graphics implementation code will be stored in the `operations::gfx` namespace. 
Following the guidelines of separating data and operations, the functional graphics library calls will be separated from the data-storage side of graphics implementations. 
Everything in the `operations::gfx` namespace will be standard while the code in the `operations::opengl` or corresponding namespaces will be specific to that implementation. 
While it is good to have standardized operations, completely discarding the strengths of each graphics implementation would be counter-intuitive to learning everything about each graphics library.

## Standardized operations across each implementation
Inside of the "standard" directory there are header files that define standard operations across each implementation.
Within each specific implementation folder, there are header files that define implementation specific functionality.
The standardized operations that every implementation will provide includes:
- Ability to pause executable operation until the next frame of the user's monitor
- Ability to unload all currently loaded assets on shutdown
- Ability to map buffers from the GPU's memory into the CPU's memory
- Mesh:
    - Ability to load and unload multiple mesh objects
- Texture:
    - Ability to load and unload multiple textures
- Font:
    - Ability to load and unload multiple true-type fonts
- Rendering:
    - Required for all renderable objects:
        - Mesh
        - Transformation matrix (column major)
        - Standard camera object (see `standard/camera.h`)
    - Optional:
        - Viewport
- Shader files:
    - Ability to load and unload specific shader files
    - Ability to set shader-specific variables (per frame, per use, per render object instance)

## Building from command line
From the source directory:
```bash
cmake -DCMAKE_BUILD_TYPE=Debug -DGFX_TYPE=OpenGL
```
With `Debug` being swappable with `Release`, `RelWithDebInfo`, or `MinSizeRel`.
And `OpenGL` being swappable with `Vulkan`, `DirectX12`, or `DirectX9`.
If the project expands in scope, I may add more graphics implementations.
