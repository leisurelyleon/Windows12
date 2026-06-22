# Local AI and NPU Compute Hooks
add_library(LocalAI_Engine STATIC
    CopilotShellHook.cpp
    NPU_InferenceLayer.cpp
)

target_include_directories(LocalAI_Engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
