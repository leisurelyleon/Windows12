# Native Universal Package System (NUPS) Blueprint

## Architecture Core Overview
The Native Universal Package System replaces legacy, chaotic setup routines. It establishes an atomic deployment paradigm that standardizes Win32, UWP, and native Linux binaries into structural package envelopes managed via `NUPS_Manager.cpp`.

## Manifest Blueprint Schema
Every application envelope must carry an immutable, self-contained root manifest. The layout avoids system registration bindings entirely:

```json
{
  "PackageIdentity": "Microsoft.DevWorkspace.Shell",
  "Version": "1.0.0",
  "TargetArchitecture": ["x64", "ARM64"],
  "VirtualFileSystem": {
    "IsolatedRoot": "%SystemDrive%/Packages/Isolated/DevWorkspaceShell",
    "SandboxRegistryOverrides": true
  },
  "Dependencies": {
    "UniversalC_Runtime": ">=14.40.33810"
  }
}
```

## System Isolation Safeguards

- **Zero System Registry Reliance:** Applications compile into an isolated virtual directory space. Modification queries targeting system folders are dynamically routed into the package's private local container.

- **Residue-Free Uninstallation Engine:** Removal commands delete only the specified isolated file block. This prevents leftover file corruption, system registry rot, and lingering background startup processes.
