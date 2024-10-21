#include "Kernel.h"

Kernel::Kernel(const std::vector<std::vector<float>>& matrix) : matrix(matrix) {}

int Kernel::getSize() const { return static_cast<int>(matrix.size()); }

float Kernel::getValue(int x, int y) const {
    return matrix[y][x]; // Access value at (x, y)
}
