/*
   @file I_ImageProcessor.h

   Copyright (C) Evan Loughlin 2024
*/

#pragma once

#include <vector>
#include "PixelData.h" // Include PixelData

using Image = std::vector<std::vector<PixelData>>; // Define a type alias for an image
using Kernel = std::vector<std::vector<float>>; // Define a type alias for a kernel

class I_ImageProcessor 
{
public:
    virtual ~I_ImageProcessor() {}

    /**
     * @brief Applies convolution on the given image with the specified kernel.
     * 
     * @param image The input image represented as a 2D vector of PixelData.
     * @param kernel The convolution kernel represented as a 2D vector of floats.
     * @return A 2D vector of PixelData representing the convolved image.
     */
    virtual Image ApplyConvolution(const Image& image, const Kernel& kernel) = 0;
};
