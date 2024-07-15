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

       
        float bigRadius = 0.4f * size;
        Circle::draw(x - 0.5f, y, bigRadius); 
        glColor3f(0.0, 0.0, 0.0); 
        Circle::draw(x - 0.35f, y, bigRadius * 0.875f); 

        
        glColor3f(color.getR(), color.getG(), color.getB()); 
        float smallRadius = 0.15f * size;
        Circle::draw(x - 0.1f, y - 0.25f, smallRadius); 
    }

};

