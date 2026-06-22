# CorePC Backend Subsystem Library
add_library(CorePC STATIC
    DevWorkspaceMode/DevModeToggle.cpp
    DevWorkspaceMode/TelemetrySuppressor.cpp
    DevWorkspaceMode/ServiceSuspender.cpp
    DevWorkspaceMode/KernelProfilerHooks.cpp
    PackageUnified/NUPS_Manager.cpp
    PackageUnified/DependencyResolver.cpp
    PackageUnified/Win32Bridge.cpp
    PackageUnified/UWPContainer.cpp
    PackageUnified/LinuxBinLayer.cpp
    TimeTravelEngine/SnapshotDaemon.cpp
    TimeTravelEngine/StateTracker.cpp
    TimeTravelEngine/DeltaStorageLayer.cpp
    TimeTravelEngine/RollbackController.cpp
)

target_include_directories(CorePC PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
