
/*
   @file ImageManager.h

   Copyright (C) Evan Loughlin 2024
*/
#pragma once

#include "I_ImageManager.h"
#include "ImageData.h"
#include <opencv2/opencv.hpp>
#include <string>

class ImageManager : public I_ImageManager 
{
public:
    ImageManager() = default;
    ~ImageManager() = default;

    // Upload an image from a file using OpenCV
    ImageData uploadImage(const std::string& filePath) override;

    // Save an image to a file using OpenCV
    void saveImage(const std::string& filePath, const ImageData& image) override;
};
