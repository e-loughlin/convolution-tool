
#include <gtest/gtest.h>
#include "Kernel.h"

class KernelTest : public ::testing::Test {
protected:
    // You can set up any common test data here
    Kernel* kernel;

    void SetUp() override {
        // Example matrix for testing
        std::vector<std::vector<float>> testMatrix = {
            {1.0f, 2.0f, 3.0f},
            {4.0f, 5.0f, 6.0f},
            {7.0f, 8.0f, 9.0f}
        };
        kernel = new Kernel(testMatrix);
    }

    void TearDown() override {
        delete kernel; 
    }
};

TEST_F(KernelTest, GetSizeReturnsCorrectSize) {
    EXPECT_EQ(kernel->getSize(), 3); 
}

TEST_F(KernelTest, GetValueReturnsCorrectValue) {
    EXPECT_FLOAT_EQ(kernel->getValue(0, 0), 1.0f); 
    EXPECT_FLOAT_EQ(kernel->getValue(1, 1), 5.0f); 
    EXPECT_FLOAT_EQ(kernel->getValue(2, 2), 9.0f); 
}

TEST_F(KernelTest, GetValueOutOfBounds) {
    // Check for out-of-bounds access
    EXPECT_ANY_THROW(kernel->getValue(3, 3)); 
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
