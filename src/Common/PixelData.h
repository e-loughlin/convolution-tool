#pragma once

class PixelData {
public:
    PixelData();
    PixelData(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255);

    unsigned char getR() const;
    unsigned char getG() const;
    unsigned char getB() const;
    unsigned char getA() const;

    void setR(unsigned char r);
    void setG(unsigned char g);
    void setB(unsigned char b);
    void setA(unsigned char a);

private:
    unsigned char r; // Red channel
    unsigned char g; // Green channel
    unsigned char b; // Blue channel
    unsigned char a; // Alpha channel (transparency)
};

