#pragma once
#include <vector>
#include "PixelData.h"

class ImageData {
public:
    ImageData(int width, int height);
    
    int getWidth() const;
    int getHeight() const;
    PixelData& getPixel(int x, int y);
    const PixelData& getPixel(int x, int y) const;

private:
    int width;
    int height;
    std::vector<std::vector<PixelData>> pixels; // 2D vector of PixelData
};
