cmake_minimum_required(VERSION 3.25)

# Initialize Project Rebirth (Windows 12)
project(Windows12_Rebirth VERSION 1.0.0 LANGUAGES CXX)

# Enforce strict modern C++ standards for deep system hooks
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

# Set global compiler flags for high-performance MSVC builds
if(MSVC)
    add_compile_options(/W4 /WX /EHsc /std:c++latest /permissive-)
    add_compile_definitions(_UNICODE UNICODE)
endif()

# ---------------------------------------------------------
# Subsystem Includes (C++ Core Native Only)
# ---------------------------------------------------------

# Low-level system abstractions (Time Travel, Dev Workspace, NUPS)
add_subdirectory(src/CorePC)

# Window Manager, Compositor, and Retro-Shell compatibility layer
add_subdirectory(src/ShellHost)

# Out-of-Box Experience (Bloat-Free Installer)
add_subdirectory(src/OOBE)

# Direct Hardware Acceleration Logic
add_subdirectory(src/LocalAI_NPU)

# ---------------------------------------------------------
# Development Tools & Unit Tests
# ---------------------------------------------------------
enable_testing()
add_subdirectory(tests)
