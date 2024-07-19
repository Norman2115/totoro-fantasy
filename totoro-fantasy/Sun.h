#pragma once
#include <gl/glut.h>
#include "Circle.h"
#include "Colors.h"
#include "Color.h"

class Sun
{
private:
    virtual void draw(float x, float y, float size, Color color) = 0;
};

class DaySunOne : public Sun
{
public:
    void draw(float x, float y, float size, Color color) override
    {
        glColor3f(color.getR(), color.getG(), color.getB());
        float radius = 0.5 * size;

        Circle::draw(x, y + 0.0125 * radius, radius);

        float longRayLength = size * 0.5f; 
        float shortRayLength = size * 0.3f; 
        float rayWidth = size * 0.1f; 
        float rayDistance = size * 0.1f; 
        int numRays = 12;
        for (int i = 0; i < numRays; i++) {
            float angle = i * (2.0f * 3.1415926f / numRays);
            
            float rayLength = (i % 2 == 0) ? longRayLength : shortRayLength;
            
            float rayStartX = x + (radius + rayDistance) * cos(angle);
            float rayStartY = y + (radius + rayDistance) * sin(angle);
            float rayEndX = x + (radius + rayLength) * cos(angle);
            float rayEndY = y + (radius + rayLength) * sin(angle);
            
            float perpX = -sin(angle);
            float perpY = cos(angle);

            float rayTopLeftX = rayEndX - rayWidth / 2 * perpX;
            float rayTopLeftY = rayEndY - rayWidth / 2 * perpY;
            float rayTopRightX = rayEndX + rayWidth / 2 * perpX;
            float rayTopRightY = rayEndY + rayWidth / 2 * perpY;
            float rayBottomRightX = rayStartX + rayWidth / 2 * perpX;
            float rayBottomRightY = rayStartY + rayWidth / 2 * perpY;
            float rayBottomLeftX = rayStartX - rayWidth / 2 * perpX;
            float rayBottomLeftY = rayStartY - rayWidth / 2 * perpY;
          
            glBegin(GL_QUADS);
            glVertex2f(rayTopLeftX, rayTopLeftY); 
            glVertex2f(rayTopRightX, rayTopRightY); 
            glVertex2f(rayBottomRightX, rayBottomRightY); 
            glVertex2f(rayBottomLeftX, rayBottomLeftY); 
            glEnd();
        }
    }
};

