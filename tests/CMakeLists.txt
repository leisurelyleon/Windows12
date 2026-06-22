# Fetch GoogleTest directly for automated CI environments
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

# Compile TimeTravel Unit Tests
add_executable(TimeTravelTests CorePCTests/TimeTravel_UnitTests.cpp)
target_link_libraries(TimeTravelTests GTest::gtest_main CorePC)

# Compile PackageUnified Unit Tests
add_executable(CleanInstallTests PackageUnifiedTests/CleanInstallTests.cpp)
target_link_libraries(CleanInstallTests GTest::gtest_main CorePC)

# Register with CTest
add_test(NAME TimeTravel_UnitTests COMMAND TimeTravelTests)
add_test(NAME NUPS_CleanInstallTests COMMAND CleanInstallTests)
