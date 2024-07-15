#pragma once
#include <gl/glut.h>
#include "Circle.h"
#include "Colors.h"
#include "Color.h"

class Moon
{
private:
	virtual void draw(float x, float y, float size, Color color) = 0;
};

class DayMoonOne : public Moon
{
public:
    void draw(float x, float y, float size, Color color) override
    {
      
        glColor3f(color.getR(), color.getG(), color.getB()); 
        float smallRadius = 0.15f * size;
        Circle::draw(x - 0.1f, y - 0.25f, smallRadius); 
    }

};

