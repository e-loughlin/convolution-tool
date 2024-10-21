add_library(ImageManager 
    I_ImageManager.h
    ImageManager.cpp
    ImageManager.h
)

find_package(OpenCV REQUIRED)

target_link_libraries(ImageManager ${OpenCV_LIBS})

target_include_directories(ImageManager PUBLIC 
    ${OpenCV_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}
)
