#include "DevModeToggle.h"
#include <iostream>

namespace CorePC::DevWorkspace {

    // Forward declarations bridging to our specialized module components
    extern void SuppressTelemetry(bool activate);
    extern void SuspendConsumerServices(bool activate);
    extern void ConfigureKernelProfiler(bool activate);

    DevModeToggle& DevModeToggle::GetInstance() {
        static DevModeToggle instance;
        return instance;
    }

    bool DevModeToggle::EnableDevMode() {
        // Prevent duplicate execution if already active
        if (m_isActive.exchange(true)) return true; 

        // Execute sequential high-performance state transition
        SuppressTelemetry(true);
        SuspendConsumerServices(true);
        ConfigureKernelProfiler(true);

        return true;
    }

    bool DevModeToggle::DisableDevMode() {
        // Prevent duplicate execution if already inactive
        if (!m_isActive.exchange(false)) return true;

        // Restore standard consumer OS functionality in reverse order
        ConfigureKernelProfiler(false);
        SuspendConsumerServices(false);
        SuppressTelemetry(false);

        return true;
    }

    bool DevModeToggle::IsDevModeActive() const {
        return m_isActive.load(std::memory_order_acquire);
    }

} // namespace CorePC::DevWorkspace
