# Fetch GoogleTest directly for automated CI environments
include(FetchContent)

# Force static linking for GTest to prevent missing DLL errors at runtime
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

# Compile TimeTravel Unit Tests
file(GLOB_RECURSE TIMETRAVEL_TESTS "CorePCTests/*.cpp")
add_executable(TimeTravelTests ${TIMETRAVEL_TESTS})
target_link_libraries(TimeTravelTests GTest::gtest_main CorePC)

# Compile PackageUnified Unit Tests
file(GLOB_RECURSE PACKAGE_TESTS "PackageUnifiedTests/*.cpp")
add_executable(CleanInstallTests ${PACKAGE_TESTS})
target_link_libraries(CleanInstallTests GTest::gtest_main CorePC)

# Register with CTest using Generator Expressions to resolve MSVC Debug/Release subdirectories
add_test(NAME TimeTravel_UnitTests COMMAND $<TARGET_FILE:TimeTravelTests>)
add_test(NAME NUPS_CleanInstallTests COMMAND $<TARGET_FILE:CleanInstallTests>)
