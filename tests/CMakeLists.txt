# Add executable target
add_executable(test_solver test_solver.cpp ../src/sat_solver.cpp ../src/utils.cpp)

# Manually specify the Google Test include directory and library paths
set(GTest_INCLUDE_DIRS /opt/homebrew/Cellar/googletest/1.15.2/include)
set(GTest_LIBRARIES 
    /opt/homebrew/Cellar/googletest/1.15.2/lib/libgtest.a
    /opt/homebrew/Cellar/googletest/1.15.2/lib/libgtest_main.a
)

# Display debug information
message(STATUS "GTest FOUND: 1")
message(STATUS "GTest_INCLUDE_DIRS: ${GTest_INCLUDE_DIRS}")
message(STATUS "GTest_LIBRARIES: ${GTest_LIBRARIES}")

# Include Google Test headers
target_include_directories(test_solver PRIVATE ${GTest_INCLUDE_DIRS})

# Link Google Test libraries
target_link_libraries(test_solver PRIVATE ${GTest_LIBRARIES})

# Add test to run
add_test(NAME SolverTest COMMAND test_solver)
