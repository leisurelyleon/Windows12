# Automatically find all C++ source files in OOBE
file(GLOB_RECURSE OOBE_SOURCES "*.cpp")

# OOBE Orchestrator Backend Module
add_library(OOBE_Orchestrator SHARED ${OOBE_SOURCES})
target_include_directories(OOBE_Orchestrator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
