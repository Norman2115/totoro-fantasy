#pragma once
class Color
{
private:
    float r, g, b;

public:
    Color() : r(0.0f), g(0.0f), b(0.0f) {}
    Color(float red, float green, float blue) : r(red), g(green), b(blue) {}

    float getR() const { return r; }
    float getG() const { return g; }
    float getB() const { return b; }
};

