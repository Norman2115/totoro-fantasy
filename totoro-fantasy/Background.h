#pragma once
#include <gl/glut.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Constants.h"
#include "Circle.h"

class Background {
private:
    static void drawStars(int numStars, bool isFantasy = false) {
        srand(static_cast<unsigned>(time(0)));
        if (isFantasy) {
            glColor3f(1.0f, 0.5f, 0.5f); 
        }
        else {
            glColor3f(1.0f, 1.0f, 1.0f); 
        }

        glBegin(GL_POINTS);
        for (int i = 0; i < numStars; ++i) {
            float x = static_cast<float>(rand() % 1920);
            float y = static_cast<float>(rand() % 1080);
            glVertex2f(x, y);
        }
        glEnd();
    }

public:
    static void Scene1_11() {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);        
        glVertex2f(0.0f, 200.0f);  
        glColor3ub(0, 0, 0);        
        glVertex2f(1920.0f, 200.0f); 
        glColor3ub(0, 0, 51);        
        glVertex2f(1920.0f, 1080.0f); 
        glColor3ub(0, 0, 51);       
        glVertex2f(0.0f, 1080.0f);  
        glEnd();

        drawStars(100, false);  

        // Ground
        glColor3f(0.0f, 0.5f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1920.0f, 0.0f);
        glVertex2f(1920.0f, 200.0f);
        glVertex2f(0.0f, 200.0f);
        glEnd();
        
    }

    static void Scene2() {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(0.0f, 200.0f);
        glColor3ub(0, 0, 0);
        glVertex2f(1920.0f, 200.0f);
        glColor3ub(0, 0, 51);
        glVertex2f(1920.0f, 1080.0f);
        glColor3ub(0, 0, 51);
        glVertex2f(0.0f, 1080.0f);
        glEnd();

        drawStars(110, false);

        // Main Hill 
        glColor3f(0.0f, 0.5f, 0.0f);
        Circle::draw(1800.0f, -1800.0f, 2200.0f); 
        
        // Small Hill
        glColor3f(0.0f, 0.5f, 0.0f);
        Circle::draw(-500.0f, -2390.0f, 2700.0f);

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        float radius = 2200.0f; 
        for (int i = 0; i <= 360; ++i) {
            float angle = static_cast<float>(i) * Constants::PI / 180.0f;
            float x = 1800.0f + radius * cosf(angle);
            float y = -1800.0f + radius * sinf(angle);
            glVertex2f(x, y);
        }
        glEnd();
    }

    static void Scene3() {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(0.0f, 200.0f);
        glColor3ub(0, 0, 0);
        glVertex2f(1920.0f, 200.0f);
        glColor3ub(0, 0, 51);
        glVertex2f(1920.0f, 1080.0f);
        glColor3ub(0, 0, 51);
        glVertex2f(0.0f, 1080.0f);
        glEnd();

        drawStars(130, false);

        // Ground
        glColor3f(0.0f, 0.5f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1920.0f, 0.0f);
        glVertex2f(1920.0f, 250.0f);
        glVertex2f(0.0f, 250.0f);
        glEnd();
    }

    static void Scene4() {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);

        glColor3ub(141, 238, 238);
        glVertex2f(0.0f, 1080.0f);
        glVertex2f(1920.0f, 1080.0f);

        glColor3ub(230, 230, 255);
        glVertex2f(1920.0f, 720.0f);
        glVertex2f(0.0f, 720.0f);

        glColor3ub(230, 230, 255);
        glVertex2f(0.0f, 720.0f);
        glVertex2f(1920.0f, 720.0f);

        glColor3ub(255, 182, 193); 
        glVertex2f(1920.0f, 250.0f);
        glVertex2f(0.0f, 250.0f);

        glColor3ub(255, 182, 193); 
        glVertex2f(0.0f, 250.0f);
        glVertex2f(1920.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);

        glEnd();

        // Ground
        glColor3ub(144, 238, 144);
        glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1920.0f, 0.0f);
        glVertex2f(1920.0f, 250.0f);
        glVertex2f(0.0f, 250.0f);
        glEnd();

        glColor3f(0.0f, 0.6f, 0.0f); 
        glBegin(GL_LINES);
        glVertex2f(0.0f, 250.0f);
        glVertex2f(1920.0f, 250.0f);
        glEnd();
    }

    
    static void Scene5() { // no done (dynamic sky)
        glClear(GL_COLOR_BUFFER_BIT);


        // Ground
        glColor3ub(144, 238, 144);
        glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1920.0f, 0.0f);
        glVertex2f(1920.0f, 250.0f);
        glVertex2f(0.0f, 250.0f);
        glEnd();

        glColor3f(0.0f, 0.6f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.0f, 250.0f);
        glVertex2f(1920.0f, 250.0f);
        glEnd();
    }

    static void Scene6_7() {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(0.0f, 200.0f);
        glColor3ub(0, 0, 0);
        glVertex2f(1920.0f, 200.0f);
        glColor3ub(51, 0, 51);
        glVertex2f(1920.0f, 1080.0f);
        glColor3ub(51, 0, 51);
        glVertex2f(0.0f, 1080.0f);
        glEnd();

        drawStars(100, true);

        // Ground
        glColor3f(0.0f, 0.5f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1920.0f, 0.0f);
        glVertex2f(1920.0f, 250.0f);
        glVertex2f(0.0f, 250.0f);
        glEnd();
    }

    static void Scene8() {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(0.0f, 200.0f);
        glColor3ub(0, 0, 0);
        glVertex2f(1920.0f, 200.0f);
        glColor3ub(51, 0, 51);
        glVertex2f(1920.0f, 1080.0f);
        glColor3ub(51, 0, 51);
        glVertex2f(0.0f, 1080.0f);
        glEnd();

        drawStars(80, true);

        // Ground
        glColor3f(0.0f, 0.5f, 0.0f);
        Circle::draw(1700.0f, -2750.0f, 3200.0f);
    }

    static void Scene9() {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(0.0f, 200.0f);
        glColor3ub(0, 0, 0);
        glVertex2f(1920.0f, 200.0f);
        glColor3ub(51, 0, 51);
        glVertex2f(1920.0f, 1080.0f);
        glColor3ub(51, 0, 51);
        glVertex2f(0.0f, 1080.0f);
        glEnd();

        drawStars(50, true);

        // Right Hill
        glColor3f(0.0f, 0.5f, 0.0f);
        Circle::draw(2800.0f, -1500.0f, 2000.0f);

        //Left Hill
        glColor3f(0.0f, 0.5f, 0.0f);
        Circle::draw(550.0f, -2500.0f, 2700.0f);

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        float radius = 2000.0f;
        for (int i = 0; i <= 360; ++i) {
            float angle = static_cast<float>(i) * Constants::PI / 180.0f;
            float x = 2800.0f + radius * cosf(angle);
            float y = -1500.0f + radius * sinf(angle);
            glVertex2f(x, y);
        }
        glEnd();
    }

    static void Scene10() {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(0.0f, 200.0f);
        glColor3ub(0, 0, 0);
        glVertex2f(1920.0f, 200.0f);
        glColor3ub(0, 0, 51);
        glVertex2f(1920.0f, 1080.0f);
        glColor3ub(0, 0, 51);
        glVertex2f(0.0f, 1080.0f);
        glEnd();

        drawStars(75, false);


        // Right Hill
        glColor3f(0.0f, 0.5f, 0.0f);
        Circle::draw(2000.0f, -2500.0f, 2700.0f);


        // Left Hill
        glColor3f(0.0f, 0.5f, 0.0f);
        Circle::draw(-10.0f, -1500.0f, 2000.0f);

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        float radius = 2000.0f;
        for (int i = 0; i <= 360; ++i) {
            float angle = static_cast<float>(i) * Constants::PI / 180.0f;
            float x = -10.0f + radius * cosf(angle);
            float y = -1500.0f + radius * sinf(angle);
            glVertex2f(x, y);
        }
        glEnd();
    }
};