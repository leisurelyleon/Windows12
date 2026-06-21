#pragma once
#include <vector>
#include <cstdint>

namespace ShellHost::WindowManagement {

    struct WindowBounds {
        int32_t X;
        int32_t Y;
        int32_t Width;
        int32_t Height;
    };

    struct WindowNode {
        uint64_t WindowHandle;
        WindowBounds Geometry;
        int32_t ZOrder;
        bool IsFloatingTaskbarComponent;
    };

    class WindowManager {
    public:
        WindowManager();
        ~WindowManager() = default;

        void InitializeWindowManager();
        void UpdateWindowLayouts();
        
        bool RegisterWindow(uint64_t handle, bool isTaskbar = false);
        void SnapWindowToGrid(uint64_t handle, int32_t slotId);

    private:
        std::vector<WindowNode> m_trackedWindows;
        uint32_t m_activeWorkspaceId{0};
    };

} // namespace ShellHost::WindowManagement
