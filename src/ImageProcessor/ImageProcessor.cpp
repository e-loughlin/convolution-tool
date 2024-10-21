/*
   @file ImageProcessor.h

   Copyright (C) Evan Loughlin 2024
*/

#pragma once

#include "I_ImageProcessor.h"
#include "Kernel.h"  // Assuming Kernel is defined in Kernel.h

class ImageProcessor : public I_ImageProcessor 
{
public:
    Image ApplyConvolution(const Image& image, const Kernel& kernel) override;
};
