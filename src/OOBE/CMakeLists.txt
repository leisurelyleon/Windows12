# OOBE Orchestrator Backend Module
add_library(OOBE_Orchestrator SHARED
    SetupOrchestrator.cpp
)

target_include_directories(OOBE_Orchestrator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
