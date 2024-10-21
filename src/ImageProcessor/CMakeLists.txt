# Add the ImageProcessor library
add_library(ImageProcessor 
    I_ImageProcessor.h
    ImageProcessor.cpp
    ImageProcessor.h
)

# Set include directory for the headers
target_include_directories(ImageProcessor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link any required libraries (if applicable)
# e.g., target_link_libraries(ImageProcessor PRIVATE some_dependency)

# Add the Test directory and include the tests
add_subdirectory(Test)
