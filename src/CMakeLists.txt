# Enable testing support for this directory
include(CTest)

# Find the Google Test package
find_package(GTest REQUIRED)

# Create an executable for the tests
add_executable(Test_ImageProcessor Test_ImageProcessor.cpp)

# Link the ImageProcessor library to the test executable
target_link_libraries(Test_ImageProcessor PRIVATE ImageProcessor GTest::GTest GTest::Main)

# Include directories for the test
target_include_directories(Test_ImageProcessor
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..
)

# Add a test for CTest
add_test(NAME Test_ImageProcessor COMMAND Test_ImageProcessor)
