#include "NUPS_Manager.h"
#include <iostream>
#include <filesystem>

namespace CorePC::PackageUnified {

    extern bool ResolveDependencies(std::string_view manifestPath);

    // FIX: Using a local relative path so the GitHub Actions CI runner has permission to read/write without Admin rights.
    const std::string ISOLATED_ROOT = "Mock_Isolated_Packages\\";

    NUPS_Manager::NUPS_Manager() {
        std::filesystem::create_directories(ISOLATED_ROOT);
    }

    bool NUPS_Manager::InstallPackage(std::string_view packageManifestPath) {
        if (!ResolveDependencies(packageManifestPath)) {
            return false;
        }

        PackageMetadata targetPackage{
            .PackageId = "Enterprise.Development.Workspace",
            .Version = "2027.1.0",
            .Type = PackageType::Win32Sandboxed,
            .IsolatedRootPath = ISOLATED_ROOT + "Enterprise.Development.Workspace"
        };

        std::string sourceZip = std::string(packageManifestPath) + ".envelope";
        if (!ExtractPackageEnvelope(sourceZip, targetPackage.IsolatedRootPath)) {
            return false;
        }

        RegisterIsolatedEnvironment(targetPackage);
        return true;
    }

    bool NUPS_Manager::UninstallPackage(std::string_view packageId) {
        std::string targetDirectory = ISOLATED_ROOT + std::string(packageId);
        UnregisterIsolatedEnvironment(packageId);
        
        if (std::filesystem::exists(targetDirectory)) {
            std::filesystem::remove_all(targetDirectory);
            return true;
        }
        return false;
    }

    bool NUPS_Manager::VerifyPackageIntegrity(std::string_view packageId) {
        std::string targetDirectory = ISOLATED_ROOT + std::string(packageId);
        return std::filesystem::exists(targetDirectory);
    }

    bool NUPS_Manager::ExtractPackageEnvelope(std::string_view source, std::string_view destination) {
        std::filesystem::create_directories(destination);
        return true;
    }

    void NUPS_Manager::RegisterIsolatedEnvironment(const PackageMetadata& meta) {}
    void NUPS_Manager::UnregisterIsolatedEnvironment(std::string_view packageId) {}

} // namespace CorePC::PackageUnified
