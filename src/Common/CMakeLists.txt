set(SOURCES
    ImageData.cpp
    Kernel.cpp
    PixelData.cpp
)

set(HEADERS
    ImageData.h
    Kernel.h
    PixelData.h
)

add_library(Common STATIC ${SOURCES} ${HEADERS})

add_subdirectory(Test)
