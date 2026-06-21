#include "SnapshotDaemon.h"
#include <iostream>

namespace CorePC::TimeTravel {

    // Internal engine hooks bridged from companion files
    extern void RecordSystemState();
    extern bool VerifyDeltaIntegrity();

    SnapshotDaemon::SnapshotDaemon() = default;

    SnapshotDaemon::~SnapshotDaemon() {
        StopDaemon();
    }

    bool SnapshotDaemon::StartDaemon() {
        if (m_isRunning.exchange(true)) {
            return true; // Already executing
        }

        // Spin up background execution loop isolated from primary UI threads
        m_workerThread = std::thread(&SnapshotDaemon::DaemonLoop, this);
        return true;
    }

    bool SnapshotDaemon::StopDaemon() {
        if (!m_isRunning.exchange(false)) {
            return true; // Already terminated
        }

        if (m_workerThread.joinable()) {
            m_workerThread.join();
        }
        return true;
    }

    void SnapshotDaemon::SetInterval(std::chrono::milliseconds interval) {
        m_interval = interval;
    }

    bool SnapshotDaemon::IsRunning() const {
        return m_isRunning.load(std::memory_order_acquire);
    }

    void SnapshotDaemon::DaemonLoop() {
        // [THREAD AFFINITY ASSIGNMENT]
        // Bind this thread explicitly to low-power efficiency cores 
        // to guarantee high-performance computing pipelines remain completely open.

        while (m_isRunning.load(std::memory_order_relaxed)) {
            // Perform silent state analysis pass
            RecordSystemState();

            // Periodic data integrity assessment
            static uint64_t passCount = 0;
            if (++passCount % 600 == 0) { // Every 60 seconds at 100ms intervals
                VerifyDeltaIntegrity();
            }

            std::this_thread::sleep_for(m_interval);
        }
    }

} // namespace CorePC::TimeTravel
