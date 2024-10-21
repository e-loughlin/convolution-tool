/*
   @file I_ImageManager.h

   Copyright (C) Evan Loughlin 2024
*/
 
#include "ImageData.h"

class I_ImageManager 
{
public:
    virtual ~I_ImageManager() {}

    virtual ImageData uploadImage(const std::string& filePath) = 0;

    virtual void saveImage(const std::string& filePath, const ImageData& image) = 0;

};
