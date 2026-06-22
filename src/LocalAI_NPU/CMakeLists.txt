# Automatically find all C++ source files in LocalAI_NPU
file(GLOB_RECURSE LOCALAI_SOURCES "*.cpp")

# Local AI and NPU Compute Hooks
add_library(LocalAI_Engine STATIC ${LOCALAI_SOURCES})
target_include_directories(LocalAI_Engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
