# Windows 12 Architecture Specification

## Subsystem Decoupling Model
Project Rebirth rejects the monolith model of legacy operating systems. The foundational architecture enforces a rigid boundary between low-level state orchestration (`CorePC`) and the presentation layer (`ShellHost`). Communication across these boundaries occurs exclusively via strongly-typed, asynchronous Inter-Process Communication (IPC) channels running over high-speed local loopbacks.

```text
+---------------------------------------------------------+
|                      SHELLHOST UI                       |
|   (WinUI 3 / XAML Compositor / Touch-Optimized Layer)   |
+---------------------------------------------------------+
                            │
                            ▼ Asynchronous IPC (C++/WinRT)
+---------------------------------------------------------+
|                    COREPC SUBSYSTEM                     |
| (C++23 Kernel Layer / Time Travel / NUPS Package Engine)|
+---------------------------------------------------------+
```

## Hardware and Execution Policies
1. **Isolated Execution Domains:** Low-level features like the Native Universal Package System (NUPS) compile to isolated containerized environments. They interact directly with hardware device nodes, bypassing traditional, fragile OS registries entirely.
2. **NPU Optimization Standards:** Direct processing offloading targets local execution contexts. The user's hardware handles tasks without pinging cloud infrastructures, preventing external metric harvesting.
3. **Memory Allotment Guidelines:** Memory consumption defaults to zero-leak allocation pools. Host modules leverage custom C++ allocators to ensure immediate collection of garbage heaps during heavy workloads.
