---
name: System Bug Report
about: Report a technical defect or regression within the Windows 12 codebase.
title: '[BUG]: '
labels: bug, unverified
assignees: ''
---

**Subsystem Component**
Identify which architectural layer is experiencing the defect (e.g., CorePC/TimeTravelEngine, ShellHost/Compositor, OOBE).

**System Environment Context**
* Host CPU Architecture: [e.g., x64, ARM64]
* Hardware Profile: [e.g., Intel Core i5-13420H / RTX 4050 / 16GB RAM]
* Build Configuration: [e.g., Debug, Release]

**Description of the Defect**
Provide a concise, precise summary of the unexpected behavior observed.

**Step-by-Step Replication Protocol**
1. Initialize the environment via...
2. Invoke the specific subsystem hook by...
3. Observe the system degradation sequence...

**Expected Behavior**
Describe exactly what the system state should look like under normal, non-defective operating parameters.

**Diagnostic Logging Data**
Paste any relevant system stack traces, terminal outputs, or UFS Explorer verification diagnostics below:
