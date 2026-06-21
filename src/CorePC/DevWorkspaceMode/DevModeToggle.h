#pragma once
#include <atomic>

namespace CorePC::DevWorkspace {
    
    // Master controller for the Microsoft Dev Workspace OS Mode
    class DevModeToggle {
    public:
        static DevModeToggle& GetInstance();

        // State transition hooks
        bool EnableDevMode();
        bool DisableDevMode();
        
        [[nodiscard]] bool IsDevModeActive() const;

    private:
        DevModeToggle() = default;
        ~DevModeToggle() = default;
        
        // Prevent copying to maintain strict singleton integrity
        DevModeToggle(const DevModeToggle&) = delete;
        DevModeToggle& operator=(const DevModeToggle&) = delete;

        std::atomic<bool> m_isActive{false};
    };

} // namespace CorePC::DevWorkspace
