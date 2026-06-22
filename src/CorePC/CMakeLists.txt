# Automatically find all C++ source files in CorePC and subdirectories
file(GLOB_RECURSE COREPC_SOURCES "*.cpp")

# CorePC Backend Subsystem Library
add_library(CorePC STATIC ${COREPC_SOURCES})
target_include_directories(CorePC PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
