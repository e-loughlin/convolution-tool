/*
   @file ImageManager.cpp

   Copyright (C) Evan Loughlin 2024
*/
#include "ImageManager.h"
#include "ImageData.h"
#include <opencv2/opencv.hpp>
#include <iostream>

// Upload an image from a file
ImageData ImageManager::uploadImage(const std::string& filePath) 
{
    // Use OpenCV to load the image
    cv::Mat img = cv::imread(filePath, cv::IMREAD_COLOR);
    
    if (img.empty()) {
        std::cerr << "Error: Could not load image at path: " << filePath << std::endl;
        return ImageData(); // Return an empty ImageData object on failure
    }

    // Convert the OpenCV image (cv::Mat) to ImageData
    ImageData imageData(img.rows, img.cols);
    
    // Copy the image data
    for (int i = 0; i < img.rows; ++i) {
        for (int j = 0; j < img.cols; ++j) {
            cv::Vec3b pixel = img.at<cv::Vec3b>(i, j);
            imageData.setPixel(i, j, PixelData(pixel[0], pixel[1], pixel[2]));
        }
    }

    return imageData;
}

// Save an image to a file
void ImageManager::saveImage(const std::string& filePath, const ImageData& image) 
{
    cv::Mat img(image.getHeight(), image.getWidth(), CV_8UC3);

    // Copy ImageData to OpenCV matrix (cv::Mat)
    for (int i = 0; i < image.getHeight(); ++i) {
        for (int j = 0; j < image.getWidth(); ++j) {
            PixelData pixel = image.getPixel(i, j);
            img.at<cv::Vec3b>(i, j) = cv::Vec3b(pixel.red, pixel.green, pixel.blue);
        }
    }

    // Use OpenCV to save the image
    if (!cv::imwrite(filePath, img)) {
        std::cerr << "Error: Could not save image at path: " << filePath << std::endl;
    }
}

