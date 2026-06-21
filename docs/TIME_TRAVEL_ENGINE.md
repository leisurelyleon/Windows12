# Universal Time-Travel Computing Engine

## Functional Mechanics
The Time-Travel Engine operates as an uninterrupted background state-tracking daemon (`SnapshotDaemon.cpp`). Unlike primitive sector backups or standard restore snapshots, this engine works directly at the virtual block abstraction layer, managing real-time transactional system logs.

## Low-Level Operations
1. **Copy-on-Write Memory Architecture:** When a system modification occurs (e.g., directory changes, hardware initialization states), the `DeltaStorageLayer` captures only the modified memory page offsets.
2. **State Graph Construction:** Changes are saved as chronological, cryptographic delta blocks in a directed acyclic graph (DAG). This allows users to reverse modifications down to the exact millisecond without corrupting unaffected components.
3. **Zero-Inference System Rollback:** Restorations executed through the `RollbackController` perform a hot swap of systemic data pages. The operating system reverts instantly to a prior verifiable state without necessitating a lengthy machine reboot cycle.

## Threading Performance Controls
The engine runs on restricted CPU affinities, isolated entirely from frontend interactive execution threads. This ensures background state tracing never induces UI micro-stutters or frame-pacing degradation on 144Hz displays.
