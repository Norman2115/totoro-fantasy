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

class FullMoon : public Moon
{
public:
    void draw(float x, float y, float size, Color color) override
    {

        glColor3f(color.getR(), color.getG(), color.getB()); 
     
        float circleRadius = 0.5f * size;
        Circle::draw(x + 0.1f * size, y + 0.1f * size, circleRadius);
        
        float smallRadius1 = 0.1f * size;
        float smallRadius2 = 0.1f * size;
        float smallRadius3 = 0.1f * size;

        glColor3f(0.86, 0.84, 0.45);
        Circle::draw(x - 0.2f * size, y + 0.3f * size, smallRadius1); 
        Circle::draw(x + 0.35f * size, y - 0.1f * size, smallRadius2); 
        Circle::draw(x + 0.1f * size, y + 0.1f * size, smallRadius3);

        
        float smallerRadius = 0.05f * size;
        Circle::draw(x - 0.2f * size, y - 0.1f * size, smallerRadius);
        Circle::draw(x + 0.4f * size, y + 0.3f * size, smallerRadius);
       
    
    }

};



