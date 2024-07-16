#pragma once
#include <gl/glut.h>
#include <iostream>
#include "Circle.h"
#include "Colors.h"
#include "Color.h"

class Rainbow
{
private:
    virtual void draw(float x, float y, float size, Color color) = 0;
};

class RainbowOne : public Rainbow {
public:
    void draw(float x, float y, float size, Color color) override {
        float radius = size;
        int numColors = 7;
        Color colors[] = {
            Color(1, 0.24, 0.24),
            Color(1, 0.47, 0.24),
            Color(1, 0.96, 0.24),
            Color(0.52, 1, 0.24),
            Color(0.5, 0.84, 1),
            Color(0.71, 0.45, 1),
            Color(0.73, 0.18, 1)
        };

        for (int i = 0; i < numColors; ++i) {
            glColor3f(colors[i].getR(), colors[i].getG(), colors[i].getB());
            SemiCircle::draw(x, y, radius - (i * (radius / numColors)), true); 
        }
    }
};