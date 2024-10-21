
#include "ImageData.h"

ImageData::ImageData(int width, int height) : width(width), height(height) {
    pixels.resize(height, std::vector<PixelData>(width));
}

int ImageData::getWidth() const { return width; }
int ImageData::getHeight() const { return height; }

PixelData& ImageData::getPixel(int x, int y) {
    return pixels[y][x]; 
}

const PixelData& ImageData::getPixel(int x, int y) const {
    return pixels[y][x]; 
}
