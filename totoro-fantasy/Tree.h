#pragma once
#include <gl/glut.h>
#include "Circle.h"
#include "Colors.h"
#include "Color.h"

class Tree
{
private:
	virtual void draw(float x, float y, float size, Color color) = 0;
};

class TreeOne : public Tree
{
   public:
	   void draw(float x, float y, float size, Color color) 
	   {
		   glColor3f(color.getR(), color.getG(), color.getB());

           // Draw the trunk
           glColor3f(0.55f, 0.27f, 0.07f); // Brown color
           glBegin(GL_POLYGON);
           glVertex2f(x - 0.1 * size, y - 0.6 * size);
           glVertex2f(x + 0.1 * size, y - 0.6 * size);
           glVertex2f(x + 0.1 * size, y);
           glVertex2f(x - 0.1 * size, y);
           glEnd();

           glColor3f(0.0f, 0.0f, 0.0f); // Black outline
           glLineWidth(2.0f);
           glBegin(GL_LINE_LOOP);
           glVertex2f(x - 0.1 * size, y - 0.6 * size);
           glVertex2f(x + 0.1 * size, y - 0.6 * size);
           glVertex2f(x + 0.1 * size, y);
           glVertex2f(x - 0.1 * size, y);
           glEnd();

           // Draw the bottom triangle
           glColor3f(0.0f, 0.5f, 0.0f); // Green color
           glBegin(GL_TRIANGLES);
           glVertex2f(x, y + 0.4 * size);
           glVertex2f(x - 0.6 * size, y - 0.2 * size);
           glVertex2f(x + 0.6 * size, y - 0.2 * size);
           glEnd();

           glColor3f(0.0f, 0.0f, 0.0f); // Black outline
           glLineWidth(2.0f);
           glBegin(GL_LINE_LOOP);
           glVertex2f(x, y + 0.4 * size);
           glVertex2f(x - 0.6 * size, y - 0.2 * size);
           glVertex2f(x + 0.6 * size, y - 0.2 * size);
           glEnd();

           // Draw the middle triangle
           glColor3f(0.0f, 0.5f, 0.0f); // Green color
           glBegin(GL_TRIANGLES);
           glVertex2f(x, y + 0.8 * size);
           glVertex2f(x - 0.6 * size, y + 0.2 * size);
           glVertex2f(x + 0.6 * size, y + 0.2 * size);
           glEnd();

           glColor3f(0.0f, 0.0f, 0.0f); // Black outline
           glLineWidth(2.0f);
           glBegin(GL_LINE_LOOP);
           glVertex2f(x, y + 0.8 * size);
           glVertex2f(x - 0.6 * size, y + 0.2 * size);
           glVertex2f(x + 0.6 * size, y + 0.2 * size);
           glEnd();

           // Draw the top triangle
           glColor3f(0.0f, 0.5f, 0.0f); // Green color
           glBegin(GL_TRIANGLES);
           glVertex2f(x, y + 1.2 * size);
           glVertex2f(x - 0.6 * size, y + 0.6 * size);
           glVertex2f(x + 0.6 * size, y + 0.6 * size);
           glEnd();

           glColor3f(0.0f, 0.0f, 0.0f); // Black outline
           glLineWidth(2.0f);
           glBegin(GL_LINE_LOOP);
           glVertex2f(x, y + 1.2 * size);
           glVertex2f(x - 0.6 * size, y + 0.6 * size);
           glVertex2f(x + 0.6 * size, y + 0.6 * size);
           glEnd();
           
       
	   }

};

class TreeTwo : public Tree
{
public:
    void draw(float x, float y, float size, Color color)
    {
        glColor3f(color.getR(), color.getG(), color.getB());

        // Draw the trunk
        glColor3f(0.55f, 0.27f, 0.07f); // Brown color
        glBegin(GL_POLYGON);
        glVertex2f(x - 0.1 * size, y - 0.6 * size);
        glVertex2f(x + 0.1 * size, y - 0.6 * size);
        glVertex2f(x + 0.1 * size, y);
        glVertex2f(x - 0.1 * size, y);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); // Black outline
        glLineWidth(2.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x - 0.1 * size, y - 0.6 * size);
        glVertex2f(x + 0.1 * size, y - 0.6 * size);
        glVertex2f(x + 0.1 * size, y);
        glVertex2f(x - 0.1 * size, y);
        glEnd();

        // Draw the bottom triangle
        glColor3f(0.0f, 0.5f, 0.0f); // Green color
        glBegin(GL_TRIANGLES);
        glVertex2f(x, y + 0.4 * size);
        glVertex2f(x - 0.4 * size, y - 0.2 * size);
        glVertex2f(x + 0.4 * size, y - 0.2 * size);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); // Black outline
        glLineWidth(2.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y + 0.4 * size);
        glVertex2f(x - 0.4 * size, y - 0.2 * size);
        glVertex2f(x + 0.4 * size, y - 0.2 * size);
        glEnd();

        // Draw the middle triangle
        glColor3f(0.0f, 0.5f, 0.0f); // Green color
        glBegin(GL_TRIANGLES);
        glVertex2f(x, y + 0.8 * size);
        glVertex2f(x - 0.4 * size, y + 0.2 * size);
        glVertex2f(x + 0.4 * size, y + 0.2 * size);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); // Black outline
        glLineWidth(2.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y + 0.8 * size);
        glVertex2f(x - 0.4 * size, y + 0.2 * size);
        glVertex2f(x + 0.4 * size, y + 0.2 * size);
        glEnd();

        // Draw the top triangle
        glColor3f(0.0f, 0.5f, 0.0f); // Green color
        glBegin(GL_TRIANGLES);
        glVertex2f(x, y + 1.2 * size);
        glVertex2f(x - 0.4 * size, y + 0.6 * size);
        glVertex2f(x + 0.4 * size, y + 0.6 * size);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); // Black outline
        glLineWidth(2.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y + 1.2 * size);
        glVertex2f(x - 0.4 * size, y + 0.6 * size);
        glVertex2f(x + 0.4 * size, y + 0.6 * size);
        glEnd();


    }

};
