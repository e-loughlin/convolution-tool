#pragma once
#include <vector>

class Kernel {
public:
    Kernel(const std::vector<std::vector<float>>& matrix);
    
    int getSize() const;
    float getValue(int x, int y) const;

private:
    std::vector<std::vector<float>> matrix; 
};
