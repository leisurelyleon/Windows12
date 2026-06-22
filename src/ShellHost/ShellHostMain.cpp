#include <iostream>
#include <thread>
#include <chrono>

namespace ShellHost {
    extern void InitializeSunsetCompositor();
    extern void InitializeRetroEngine();
    extern void InitializeWindowManager();
    extern bool IsShellRunning();
    extern void TickAnimationPipeline();
}

int main(int argc, char* argv[]) {
    std::cout << "[ShellHost] Initializing Windows 12 Presentation Shell (Project Rebirth)..." << std::endl;

    // 1. Boot the unanchored window management layer
    ShellHost::InitializeWindowManager();

    // 2. Initialize the primary hardware-accelerated compositor
    ShellHost::InitializeSunsetCompositor();

    // 3. Scan for legacy environmental flags
    bool loadRetroMode = false;
    for (int i = 1; i < argc; ++i) {
        if (std::string_view(argv[i]) == "--retro-shell") {
            loadRetroMode = true;
        }
    }

    if (loadRetroMode) {
        ShellHost::InitializeRetroEngine();
    }

    std::cout << "[ShellHost] Shell rendering pipeline active. Entering 144Hz compositor loop." << std::endl;

    // The primary 144Hz synchronized message and render loop
    while (ShellHost::IsShellRunning()) {
        ShellHost::TickAnimationPipeline();
        std::this_thread::sleep_for(std::chrono::microseconds(6944)); // Lock pipeline to ~144 frames per second
    }

    return 0;
}
