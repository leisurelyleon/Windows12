# Fetch GoogleTest safely
include(FetchContent)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

# Use CMake's built-in GoogleTest integration to automatically resolve executable paths
include(GoogleTest)

# Compile TimeTravel Unit Tests
file(GLOB_RECURSE TIMETRAVEL_TESTS "CorePCTests/*.cpp")
add_executable(TimeTravelTests ${TIMETRAVEL_TESTS})
target_link_libraries(TimeTravelTests GTest::gtest_main CorePC)
gtest_discover_tests(TimeTravelTests)

# Compile PackageUnified Unit Tests
file(GLOB_RECURSE PACKAGE_TESTS "PackageUnifiedTests/*.cpp")
add_executable(CleanInstallTests ${PACKAGE_TESTS})
target_link_libraries(CleanInstallTests GTest::gtest_main CorePC)
gtest_discover_tests(CleanInstallTests)
