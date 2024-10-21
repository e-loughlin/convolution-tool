#include "PixelData.h"

PixelData::PixelData() : r(0), g(0), b(0), a(255) {}

PixelData::PixelData(unsigned char r, unsigned char g, unsigned char b, unsigned char a) 
    : r(r), g(g), b(b), a(a) {}

unsigned char PixelData::getR() const { return r; }
unsigned char PixelData::getG() const { return g; }
unsigned char PixelData::getB() const { return b; }
unsigned char PixelData::getA() const { return a; }

void PixelData::setR(unsigned char r) { this->r = r; }
void PixelData::setG(unsigned char g) { this->g = g; }
void PixelData::setB(unsigned char b) { this->b = b; }
void PixelData::setA(unsigned char a) { this->a = a; }
