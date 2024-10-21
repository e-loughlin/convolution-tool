# Add test executable
add_executable(Test_ImageData Test_ImageData.cpp)

# Link the Google Test library and other dependencies
target_link_libraries(Test_ImageData gtest gtest_main)

# Register the test with CTest
add_test(NAME Test_ImageData COMMAND Test_ImageData)
