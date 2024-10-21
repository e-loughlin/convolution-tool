#include <gtest/gtest.h>
#include "../ImageData.h"

class ImageDataTest : public ::testing::Test {
protected:
    void SetUp() override {
        imageData = new ImageData(3, 3);
        imageData->setPixel(0, 0, PixelData(255, 0, 0));  // Red
        imageData->setPixel(0, 1, PixelData(0, 255, 0));  // Green
        imageData->setPixel(0, 2, PixelData(0, 0, 255));  // Blue
    }

    void TearDown() override {
        delete imageData;
    }

    ImageData* imageData;
};

TEST_F(ImageDataTest, GetWidth) {
    EXPECT_EQ(imageData->getWidth(), 3);
}

TEST_F(ImageDataTest, GetHeight) {
    EXPECT_EQ(imageData->getHeight(), 3);
}

TEST_F(ImageDataTest, GetPixel) {
    PixelData pixel = imageData->getPixel(0, 0);
    EXPECT_EQ(pixel.red, 255);
    EXPECT_EQ(pixel.green, 0);
    EXPECT_EQ(pixel.blue, 0);
}

TEST_F(ImageDataTest, SetPixel) {
    imageData->setPixel(1, 1, PixelData(128, 128, 128));
    PixelData pixel = imageData->getPixel(1, 1);
    EXPECT_EQ(pixel.red, 128);
    EXPECT_EQ(pixel.green, 128);
    EXPECT_EQ(pixel.blue, 128);
}

TEST_F(ImageDataTest, PixelOutOfBounds) {
    // Test behavior when trying to get or set out-of-bounds pixels
    ASSERT_THROW(imageData->getPixel(-1, 0), std::out_of_range);
    ASSERT_THROW(imageData->getPixel(3, 3), std::out_of_range);
}
