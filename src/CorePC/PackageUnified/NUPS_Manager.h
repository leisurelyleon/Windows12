#pragma once
#include <string_view>
#include <vector>
#include <string>
#include <memory>

namespace CorePC::PackageUnified {

    enum class PackageType {
        Win32Sandboxed,
        UWPNative,
        LinuxBinary,
        WebAppIsolated
    };

    struct PackageMetadata {
        std::string PackageId;
        std::string Version;
        PackageType Type;
        std::string IsolatedRootPath;
    };

    class NUPS_Manager {
    public:
        NUPS_Manager();
        ~NUPS_Manager() = default;

        // Core lifecycle operations
        bool InstallPackage(std::string_view packageManifestPath);
        bool UninstallPackage(std::string_view packageId);
        bool VerifyPackageIntegrity(std::string_view packageId);
        
        std::vector<PackageMetadata> GetInstalledPackages() const;

    private:
        bool ExtractPackageEnvelope(std::string_view source, std::string_view destination);
        void RegisterIsolatedEnvironment(const PackageMetadata& meta);
        void UnregisterIsolatedEnvironment(std::string_view packageId);
    };

} // namespace CorePC::PackageUnified
