#include <windows.h>
#include <iostream>
#include <string>

// Compiles to tools/UI_Inspector.exe
// Usage: UI_Inspector.exe --highlight-bounds

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    char windowTitle[256];
    GetWindowTextA(hwnd, windowTitle, sizeof(windowTitle));

    std::string title(windowTitle);
    
    // Target the specific Project Rebirth unanchored presentation layers
    if (title.find("Windows 12 Presentation Shell") != std::string::npos || 
        title.find("TaskbarFloat") != std::string::npos) {
        
        RECT rect;
        if (GetWindowRect(hwnd, &rect)) {
            std::cout << "[UI_Inspector] Found Target Element: " << title << "\n";
            std::cout << " -> Bounds: X=" << rect.left << ", Y=" << rect.top 
                      << ", W=" << (rect.right - rect.left) 
                      << ", H=" << (rect.bottom - rect.top) << "\n";

            // Verify minimum 40px touch boundary compliance
            if ((rect.right - rect.left) < 40 || (rect.bottom - rect.top) < 40) {
                std::cout << "    [WARNING] Element fails 40px touch geometry guidelines!\n";
            }
        }
    }
    return TRUE;
}

int main(int argc, char* argv[]) {
    std::cout << "========================================\n";
    std::cout << " Project Rebirth UI Geometry Inspector\n";
    std::cout << "========================================\n\n";

    if (argc > 1 && std::string(argv[1]) == "--highlight-bounds") {
        std::cout << "[UI_Inspector] Scanning display pipelines for WinUI 3 nodes...\n\n";
        EnumWindows(EnumWindowsProc, 0);
    } else {
        std::cout << "Usage: UI_Inspector.exe --highlight-bounds\n";
    }

    return 0;
}
