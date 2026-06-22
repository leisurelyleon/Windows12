#include <gtest/gtest.h>
#include "../../src/CorePC/TimeTravelEngine/SnapshotDaemon.h"

using namespace CorePC::TimeTravel;

// Explicitly declare the external function to fix Error C3861
namespace CorePC::TimeTravel {
    extern bool VerifyDeltaIntegrity();
}

class TimeTravelTestFixture : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(TimeTravelTestFixture, DaemonInitializationTest) {
    SnapshotDaemon daemon;
    EXPECT_FALSE(daemon.IsRunning());

    bool startSuccess = daemon.StartDaemon();
    EXPECT_TRUE(startSuccess);
    EXPECT_TRUE(daemon.IsRunning());

    daemon.StopDaemon();
    EXPECT_FALSE(daemon.IsRunning());
}

TEST_F(TimeTravelTestFixture, DeltaIntegrityValidation) {
    // Call the newly declared external function
    bool integrityValid = CorePC::TimeTravel::VerifyDeltaIntegrity();
    EXPECT_TRUE(integrityValid);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
