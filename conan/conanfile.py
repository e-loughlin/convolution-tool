from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain


class YourProjectConan(ConanFile):
    name = "Convolution Tool"
    version = "0.1"
    settings = "os", "compiler", "build_type", "arch"
    requires = ["qt/6.7.3", "gtest/1.13.0", "opencv/4.10.0"]
    generators = "CMakeDeps"

    def generate(self):
        toolchain = CMakeToolchain(self)
        toolchain.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
