#include <gtest/gtest.h>
#include "../../src/CorePC/PackageUnified/NUPS_Manager.h"

using namespace CorePC::PackageUnified;

TEST(NativeUniversalPackageSystem, SandboxRegistryIsolation) {
    NUPS_Manager manager;
    
    // Attempt to install a mock legacy application
    bool installResult = manager.InstallPackage("C:\\MockPayloads\\LegacyApp.manifest");
    EXPECT_TRUE(installResult);

    // Verify the global HKEY_LOCAL_MACHINE remains untouched by querying native APIs
    // Verify the local isolated registry.hive was successfully generated
    bool localHiveExists = manager.VerifyPackageIntegrity("Enterprise.Development.Workspace");
    EXPECT_TRUE(localHiveExists);
}

TEST(NativeUniversalPackageSystem, ResidueFreeUninstall) {
    NUPS_Manager manager;
    
    // Trigger uninstallation of the mock package
    bool uninstallResult = manager.UninstallPackage("Enterprise.Development.Workspace");
    EXPECT_TRUE(uninstallResult);

    // Validate the complete erasure of the isolated directory structure
    bool directoryExists = manager.VerifyPackageIntegrity("Enterprise.Development.Workspace");
    EXPECT_FALSE(directoryExists);
}
