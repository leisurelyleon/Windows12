#pragma once
#include <thread>
#include <atomic>
#include <chrono>
#include <memory>

namespace CorePC::TimeTravel {

    class SnapshotDaemon {
    public:
        SnapshotDaemon();
        ~SnapshotDaemon();

        // Daemon lifecycle controls
        bool StartDaemon();
        bool StopDaemon();
        
        void SetInterval(std::chrono::milliseconds interval);
        [[nodiscard]] bool IsRunning() const;

    private:
        void DaemonLoop();

        std::atomic<bool> m_isRunning{false};
        std::chrono::milliseconds m_interval{100}; // Default 100ms interval for precision tracing
        std::thread m_workerThread;
    };

} // namespace CorePC::TimeTravel
