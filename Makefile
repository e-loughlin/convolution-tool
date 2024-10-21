# Directories
BUILD_DIR = build
INSTALL_DIR = $(BUILD_DIR)/release
CONAN_DIR = $(BUILD_DIR)
APP_NAME = convolution-tool

# Conan options
CONAN_OPTIONS = -of=${CONAN_DIR} --build=missing ./conan/conanfile.py

# CMake options
CMAKE_OPTIONS = -DCMAKE_BUILD_TYPE=Release -S . -B $(INSTALL_DIR) -DCMAKE_TOOLCHAIN_FILE=${CONAN_DIR}/conan_toolchain.cmake

.PHONY: all build conan install clean run clean-all

# Default target, runs build
all: clean build

# Run Conan install, generates files in the build/conan/ directory
conan:
	@echo "Running Conan install..."
	@{ test -f ./conan/conanfile.py; } || { echo "conanfile.py not found!"; exit 1; }
	conan install $(CONAN_OPTIONS)

# Run CMake configure step and build the project
build: conan
	@echo "Configuring with CMake..."
	@cmake --version || { echo "CMake is not installed!"; exit 1; }
	cmake $(CMAKE_OPTIONS) 
	cmake --build $(INSTALL_DIR) --verbose

# Install the built project (you can customize where to install)
install: build
	@echo "Installing the application..."
	cmake --install $(INSTALL_DIR)

# Clean the build directories
clean:
	@echo "Cleaning build directory..."
	rm -rf $(BUILD_DIR)

# Clean all build artifacts
clean-all: clean
	@echo "Cleaning all artifacts..."

run:
	@echo "Running the application..."
	./${INSTALL_DIR}/${APP_NAME}.app/Contents/MacOS/${APP_NAME}
