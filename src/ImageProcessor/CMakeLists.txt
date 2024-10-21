# find_package(OpenCV REQUIRED)

# Add the ImageProcessor library
add_library(ImageProcessor 
    I_ImageProcessor.h
    ImageProcessor.cpp
    ImageProcessor.h
)

# # Include OpenCV headers
# target_include_directories(ImageProcessor PUBLIC ${OpenCV_INCLUDE_DIRS})
#
# # Link OpenCV libraries to the ImageProcessor library
# target_link_libraries(ImageProcessor PUBLIC ${OpenCV_LIBS})

# Add the Test directory and include the tests
add_subdirectory(Test)
