#include "WindowManager/WindowManager.h"
#include "Compositor/CompositorEngine.h"
#include "RetroShell/RetroShellManager.h"
#include <iostream>
#include <memory>
#include <chrono>
#include <thread>

int main(int argc, char* argv[]) {
    // Establish high-priority thread allocation for the window compositor
    std::cout << "[ShellHost] Initializing Windows 12 Presentation Layer Engine..." << std::endl;

    auto compositor = std::make_unique<ShellHost::Compositor::CompositorEngine>();
    auto windowManager = std::make_unique<ShellHost::WindowManagement::WindowManager>();
    auto retroShell = std::make_unique<ShellHost::Retro::RetroShellManager>();

    // 1. Initialize the graphics composition pipelines (Targeting 144Hz panels)
    if (!compositor->InitializeDisplayPipeline()) {
        std::cerr << "[ShellHost CRITICAL] Failed to initialize display pipeline." << std::endl;
        return -1;
    }

    // 2. Attach the low-level window event hooks
    windowManager->InitializeWindowManager();

    // 3. Scan system boot parameters for legacy skin injection overrides
    if (argc > 1 && std::string_view(argv[1]) == "--retro-mode") {
        retroShell->EngageRetroLayer(true);
    }

    std::cout << "[ShellHost] Shell environment successfully drawn. Entering main engine message thread." << std::endl;

    // Main presentation loop tracking user input and display synchronizations
    while (compositor->IsPipelineActive()) {
        windowManager->UpdateWindowLayouts();
        compositor->RenderFrame();
        
        // Prevent micro-stuttering while maintaining execution cycle efficiency
        std::this_thread::sleep_for(std::chrono::microseconds(6944)); // Calibrated for ~144Hz execution pacing
    }

    return 0;
}
