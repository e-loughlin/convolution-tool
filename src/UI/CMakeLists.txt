add_library(UI
    main.cpp
    qml.qrc
)

# Include directories
target_include_directories(UI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link with Qt Quick and other required libraries
target_link_libraries(UI Qt${QT_VERSION_MAJOR}::Quick)
