/*
   @file ImageProcessor.h

   Copyright (C) Evan Loughlin 2024
*/

#pragma once

#include "I_ImageProcessor.h"
#include "Kernel.h" 
#include <stdexcept>

class ImageProcessor : public I_ImageProcessor 
{
public:
    Image ApplyConvolution(const Image& image, const Kernel& kernel) override 
    {
        int kernelSize = kernel.size();
        int kernelHalfSize = kernelSize / 2;

        int imageHeight = image.size();
        int imageWidth = image[0].size();
        Image result(imageHeight, std::vector<PixelData>(imageWidth, PixelData()));

        for (int y = 0; y < imageHeight; ++y) {
            for (int x = 0; x < imageWidth; ++x) {
                float sumR = 0.0f;
                float sumG = 0.0f;
                float sumB = 0.0f;
                float sumA = 0.0f; 

                // Apply the kernel
                for (int ky = -kernelHalfSize; ky <= kernelHalfSize; ++ky) {
                    for (int kx = -kernelHalfSize; kx <= kernelHalfSize; ++kx) {
                        int imageY = y + ky;
                        int imageX = x + kx;

                        // Check if we are within the bounds of the image
                        if (imageY >= 0 && imageY < imageHeight && imageX >= 0 && imageX < imageWidth) {
                            const PixelData& pixel = image[imageY][imageX];
                            sumR += pixel.getR() * kernel[ky + kernelHalfSize][kx + kernelHalfSize];
                            sumG += pixel.getG() * kernel[ky + kernelHalfSize][kx + kernelHalfSize];
                            sumB += pixel.getB() * kernel[ky + kernelHalfSize][kx + kernelHalfSize];
                            sumA += pixel.getA() * kernel[ky + kernelHalfSize][kx + kernelHalfSize]; // Optional
                        }
                    }
                }

                // Normalize and clamp values to 0-255 for the result
                result[y][x].setR(static_cast<unsigned char>(std::clamp(sumR, 0.0f, 255.0f)));
                result[y][x].setG(static_cast<unsigned char>(std::clamp(sumG, 0.0f, 255.0f)));
                result[y][x].setB(static_cast<unsigned char>(std::clamp(sumB, 0.0f, 255.0f)));
                result[y][x].setA(static_cast<unsigned char>(std::clamp(sumA, 0.0f, 255.0f))); // Optional
            }
        }

        return result;
    }
};
