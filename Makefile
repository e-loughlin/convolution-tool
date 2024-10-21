# Directories
BUILD_DIR = build
CONAN_DIR = $(BUILD_DIR)/conan
INSTALL_DIR = $(BUILD_DIR)/release

# Conan options
CONAN_OPTIONS = -of=${CONAN_DIR} --build=missing -s build_type=Release ./conan/conanfile.py

# CMake options
CMAKE_OPTIONS = -DCMAKE_BUILD_TYPE=Release -S . -B $(INSTALL_DIR)

# Path to environment file
ENV_FILE = .env

.PHONY: all build conan cmake install clean

# Default target, runs build
all: build

# Run Conan install, generates files in the build/conan/ directory
conan:
	. $(ENV_FILE) && conan install $(CONAN_OPTIONS)

# Run CMake configure step and build the project
build: conan
	. $(ENV_FILE) && cmake $(CMAKE_OPTIONS)
	. $(ENV_FILE) && cmake --build $(INSTALL_DIR)

# Install the built project (you can customize where to install)
install: build
	. $(ENV_FILE) && cmake --install $(INSTALL_DIR)

# Clean the build directories
clean:
	rm -rf $(BUILD_DIR)
