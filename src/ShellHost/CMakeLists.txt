# Automatically find all C++ source files in ShellHost and subdirectories
file(GLOB_RECURSE SHELLHOST_SOURCES "*.cpp")

# ShellHost Presentation Layer Executable
add_executable(ShellHostMain ${SHELLHOST_SOURCES})
target_include_directories(ShellHostMain PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
