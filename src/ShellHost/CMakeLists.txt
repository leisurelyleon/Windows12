# ShellHost Presentation Layer Executable
add_executable(ShellHostMain
    ShellHostMain.cpp
    Compositor/SunsetGradientRenderer.cpp
    Compositor/GlassMicaEngine.cpp
    Compositor/AnimationController.cpp
    RetroShell/LegacyThemeEngine.cpp
    RetroShell/XPSkinMapper.cpp
    RetroShell/AeroGlassSimulator.cpp
    WindowManager/ModularSnap.cpp
    WindowManager/FloatingContainer.cpp
)

target_include_directories(ShellHostMain PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
