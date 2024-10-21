cmake_minimum_required(VERSION 3.16)

project(convolution-tool VERSION 0.1 LANGUAGES CXX)

# Enable testing support
include(CTest)
enable_testing()

# Qt-specific settings
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt libraries, including QML and Quick for QML support
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets Quick Qml QuickLayouts)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Quick Qml QuickLayouts)

# Setup Conan
include(${CMAKE_BINARY_DIR}/conan/conan_toolchain.cmake)

set(CMAKE_PREFIX_PATH "/Users/eloughlin/Qt/6.8.0/macos/lib/cmake/Qt6")

# Add subdirectories for modular components
add_subdirectory(src)

# Define the main application target
set(PROJECT_SOURCES
    src/UI/main.cpp
    src/UI/qml.qrc  # Include the QML resource file
)

# Define the application target
qt_add_executable(convolution-tool
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

# Link necessary Qt libraries, including QML modules
target_link_libraries(convolution-tool PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets 
    Qt${QT_VERSION_MAJOR}::Quick 
    Qt${QT_VERSION_MAJOR}::Qml
)

# Set target properties for macOS bundles
set_target_properties(convolution-tool PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.convolution-tool  # Moved here for clarity
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Installation rules
include(GNUInstallDirs)
install(TARGETS convolution-tool
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finalize the Qt executable for Qt 6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(convolution-tool)
endif()
