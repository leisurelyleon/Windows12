# Fetch GoogleTest directly for automated CI environments
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

# Automatically map the test files to prevent pathing failures
file(GLOB_RECURSE TIMETRAVEL_TESTS "CorePCTests/*.cpp")
add_executable(TimeTravelTests ${TIMETRAVEL_TESTS})
target_link_libraries(TimeTravelTests GTest::gtest_main CorePC)

file(GLOB_RECURSE PACKAGE_TESTS "PackageUnifiedTests/*.cpp")
add_executable(CleanInstallTests ${PACKAGE_TESTS})
target_link_libraries(CleanInstallTests GTest::gtest_main CorePC)

# Register with CTest
add_test(NAME TimeTravel_UnitTests COMMAND TimeTravelTests)
add_test(NAME NUPS_CleanInstallTests COMMAND CleanInstallTests)
