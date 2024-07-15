#pragma once
#include <gl/glut.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <thread>
#include <chrono>
#include "Constants.h"
#include "Circle.h"

class Background {
private:
    static void drawStars(int numStars, bool isFantasy = false) {
        srand(static_cast<unsigned>(time(0)));
        if (isFantasy) {
            glColor3f(1, 0.11, 0.94);
        }
        else {
            glColor3f(1, 1, 1); 
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
    static void Scene1() {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        glColor3f(0, 0, 0);        
        glVertex2f(0.0f, 200.0f);  
        glColor3f(0, 0, 0);        
        glVertex2f(1920.0f, 200.0f); 
        glColor3f(0.06, 0.07, 0.19);
        glVertex2f(1920.0f, 1080.0f); 
        glColor3f(0.06, 0.07, 0.19);
        glVertex2f(0.0f, 1080.0f);  
        glEnd();

        drawStars(100, false);  

        // Ground
        glColor3f(0.39, 0.64, 0.24);
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
        glColor3f(0, 0, 0);
        glVertex2f(0.0f, 200.0f);
        glColor3f(0, 0, 0);
        glVertex2f(1920.0f, 200.0f);
        glColor3f(0.06, 0.07, 0.19);
        glVertex2f(1920.0f, 1080.0f);
        glColor3f(0.06, 0.07, 0.19);
        glVertex2f(0.0f, 1080.0f);
        glEnd();

        drawStars(110, false);

        // Main Hill 
        glColor3f(0.39, 0.64, 0.24);
        Circle::draw(1800.0f, -1800.0f, 2200.0f);
        
        // Small Hill
        glColor3f(0.39, 0.64, 0.24);
        Circle::draw(-500.0f, -2390.0f, 2700.0f);

        glColor3f(0.22, 0.3, 0.17);
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
        glColor3f(0, 0, 0);
        glVertex2f(0.0f, 200.0f);
        glColor3f(0, 0, 0);
        glVertex2f(1920.0f, 200.0f);
        glColor3f(0.06, 0.07, 0.19);
        glVertex2f(1920.0f, 1080.0f);
        glColor3f(0.06, 0.07, 0.19);
        glVertex2f(0.0f, 1080.0f);
        glEnd();

        drawStars(130, false);

        // Ground
        glColor3f(0.39, 0.64, 0.24);
        glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1920.0f, 0.0f);
        glVertex2f(1920.0f, 250.0f);
        glVertex2f(0.0f, 250.0f);
        glEnd();

        // Cave
        glColor3f(0.37, 0.38, 0.38);
        glBegin(GL_POLYGON);
        glVertex2f(1200.0f, 220.0f); 
        glVertex2f(1230.0f, 400.0f);
        glVertex2f(1350.0f, 570.0f); 
        glVertex2f(1410.0f, 600.0f); 
        glVertex2f(1500.0f, 700.0f); 
        glVertex2f(1600.0f, 700.0f); 
        glVertex2f(1700.0f, 690.0f); 
        glVertex2f(1740.0f, 580.0f); 
        glVertex2f(1880.0f, 460.0f); 
        glVertex2f(1920.0f, 220.0f); 
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(1200.0f, 220.0f);
        glVertex2f(1230.0f, 400.0f);
        glVertex2f(1350.0f, 570.0f);
        glVertex2f(1410.0f, 600.0f);
        glVertex2f(1500.0f, 700.0f);
        glVertex2f(1600.0f, 700.0f);
        glVertex2f(1700.0f, 690.0f);
        glVertex2f(1740.0f, 580.0f);
        glVertex2f(1880.0f, 460.0f);
        glVertex2f(1920.0f, 220.0f);
        glEnd();

        // Small Rocks
        glColor3f(0.37, 0.38, 0.38);
        glBegin(GL_POLYGON);
        glVertex2f(1670.0f, 200.0f);
        glVertex2f(1680.0f, 300.0f);
        glVertex2f(1780.0f, 450.0f);
        glVertex2f(1800.0f, 464.0f);
        glVertex2f(1890.0f, 490.0f);
        glVertex2f(1890.0f, 490.0f);
        glVertex2f(1930.0f, 480.0f);
        glVertex2f(1930.0f, 200.0f);
        glVertex2f(1810.0f, 200.0f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(1670.0f, 200.0f);
        glVertex2f(1680.0f, 300.0f);
        glVertex2f(1780.0f, 450.0f);
        glVertex2f(1800.0f, 464.0f);
        glVertex2f(1890.0f, 490.0f);
        glVertex2f(1890.0f, 490.0f);
        glVertex2f(1930.0f, 480.0f);
        glVertex2f(1930.0f, 200.0f);
        glVertex2f(1810.0f, 200.0f);
        glEnd();


    }

    static void Scene4() {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);

        glColor3f(1, 0.71, 0.99);
        glVertex2f(0.0f, 1080.0f);
        glVertex2f(1920.0f, 1080.0f);

        glColor3f(1, 0.8, 1);
        glVertex2f(1920.0f, 720.0f);
        glVertex2f(0.0f, 720.0f);

        glColor3f(1, 0.8, 1);
        glVertex2f(0.0f, 720.0f);
        glVertex2f(1920.0f, 720.0f);

        glColor3f(1, 1, 0.87);
        glVertex2f(1920.0f, 250.0f);
        glVertex2f(0.0f, 250.0f);

        glColor3f(1, 1, 0.87);
        glVertex2f(0.0f, 250.0f);
        glVertex2f(1920.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);

        glEnd();

        // Ground
        glColor3f(0.67, 0.97, 0.5);
        glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1920.0f, 0.0f);
        glVertex2f(1920.0f, 250.0f);
        glVertex2f(0.0f, 250.0f);
        glEnd();

        glColor3f(0.22, 0.3, 0.17);
        glBegin(GL_LINES);
        glVertex2f(0.0f, 250.0f);
        glVertex2f(1920.0f, 250.0f);
        glEnd();
    }

    
    static void Scene5() { 
        int transitionTime = 10000; // 10 seconds
        int steps = 100;
        int delay = transitionTime / steps;

        for (int i = 0; i <= steps; i++) {
            float a = (float)i / steps; // Appear
            float f = 1.0f - a; // Fade 

            glClear(GL_COLOR_BUFFER_BIT);

            // Sunset 
            glBegin(GL_QUADS);
            glColor3f(1, 0.25 * a + 0.71 * f, 0.53 * a + 0.99 * f);
            glVertex2f(0.0f, 1080.0f);
            glVertex2f(1920.0f, 1080.0f);

            glColor3f(1, 0.45 * a + 0.8 * f, 0.26 * a + 1 * f);
            glVertex2f(1920.0f, 720.0f);
            glVertex2f(0.0f, 720.0f);

            glColor3f(1, 0.45 * a + 0.8 * f, 0.26 * a + 1 * f);
            glVertex2f(0.0f, 720.0f);
            glVertex2f(1920.0f, 720.0f);

            glColor3f(1, 0.63 * a + 1 * f, 0.26 * a + 0.87 * f);
            glVertex2f(1920.0f, 250.0f);
            glVertex2f(0.0f, 250.0f);

            glColor3f(1, 0.63 * a + 1 * f, 0.26 * a + 0.87 * f);
            glVertex2f(0.0f, 250.0f);
            glVertex2f(1920.0f, 0.0f);
            glVertex2f(0.0f, 0.0f);
            glEnd();

            // Ground 
            glColor3f(0.44 * a + 0.67 * f, 0.74 * a + 0.97 * f, 0.27 * a + 0.5 * f);
            glBegin(GL_QUADS);
            glVertex2f(0.0f, 0.0f);
            glVertex2f(1920.0f, 0.0f);
            glVertex2f(1920.0f, 250.0f);
            glVertex2f(0.0f, 250.0f);
            glEnd();

            glFlush();
            glutSwapBuffers();

            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }

        //static sunset (leave in case of emergency)
        /*
        glBegin(GL_QUADS); // sunset
        glColor3f(1, 0.25, 0.53);
        glVertex2f(0.0f, 1080.0f);
        glVertex2f(1920.0f, 1080.0f);

        glColor3f(1, 0.45, 0.26);
        glVertex2f(1920.0f, 720.0f);
        glVertex2f(0.0f, 720.0f);

        glColor3f(1, 0.45, 0.26);
        glVertex2f(0.0f, 720.0f);
        glVertex2f(1920.0f, 720.0f);

        glColor3f(1, 0.63, 0.26);
        glVertex2f(1920.0f, 250.0f);
        glVertex2f(0.0f, 250.0f);

        glColor3f(1, 0.63, 0.26);
        glVertex2f(0.0f, 250.0f);
        glVertex2f(1920.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glEnd();

        // Ground(sunset)
        glColor3f(0.44, 0.74, 0.27);
        glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1920.0f, 0.0f);
        glVertex2f(1920.0f, 250.0f);
        glVertex2f(0.0f, 250.0f);
        glEnd();
        */
    }

    static void Scene6_7() {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        glColor3f(0, 0, 0);
        glVertex2f(0.0f, 200.0f);
        glColor3f(0, 0, 0);
        glVertex2f(1920.0f, 200.0f);
        glColor3f(0.17, 0.08, 0.28);
        glVertex2f(1920.0f, 1080.0f);
        glColor3f(0.17, 0.08, 0.28);
        glVertex2f(0.0f, 1080.0f);
        glEnd();

        drawStars(100, true);

        // Ground
        glColor3f(0.44, 0.74, 0.27);
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
        glColor3f(0, 0, 0);
        glVertex2f(0.0f, 200.0f);
        glColor3f(0, 0, 0);
        glVertex2f(1920.0f, 200.0f);
        glColor3f(0.17, 0.08, 0.28);
        glVertex2f(1920.0f, 1080.0f);
        glColor3f(0.17, 0.08, 0.28);
        glVertex2f(0.0f, 1080.0f);
        glEnd();

        drawStars(80, true);

        // Ground
        glColor3f(0.44, 0.74, 0.27);
        Circle::draw(1700.0f, -2750.0f, 3200.0f);
    }

    static void Scene9() {
        glClear(GL_COLOR_BUFFER_BIT);

        drawStars(150, true);

        glBegin(GL_POLYGON);
        glColor3f(0, 0, 0);
        glVertex2f(0.0f, 500.0f);
        glVertex2f(1920.0f,500.0f);
        glColor3f(0.28, 1, 0.65);
        glVertex2f(1920.0f, 900.0f);
        glVertex2f(0.0f, 900.0f);
        glEnd();

        glBegin(GL_POLYGON);       
        glColor3f(0.28, 1, 0.65);
        glVertex2f(0.0f, 900.0f);
        glVertex2f(1920.0f, 900.0f);
        glColor3f(0.67, 0.63, 1);
        glVertex2f(1920.0f, 1080.0f);
        glVertex2f(0.0f, 1080.0f);
        glEnd();

        // Right Hill
        glColor3f(0.44, 0.74, 0.27);
        Circle::draw(2800.0f, -1500.0f, 2000.0f);

        //Left Hill
        glColor3f(0.44, 0.74, 0.27);
        Circle::draw(550.0f, -2500.0f, 2700.0f);

        glColor3f(0.22, 0.3, 0.17);
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
        glColor3f(0, 0, 0);
        glVertex2f(0.0f, 200.0f);
        glColor3f(0, 0, 0);
        glVertex2f(1920.0f, 200.0f);
        glColor3f(0.06, 0.07, 0.19);
        glVertex2f(1920.0f, 1080.0f);
        glColor3f(0.06, 0.07, 0.19);
        glVertex2f(0.0f, 1080.0f);
        glEnd();

        drawStars(75, false);


        // Right Hill
        glColor3f(0.39, 0.64, 0.24);
        Circle::draw(2000.0f, -2500.0f, 2700.0f);


        // Left Hill
        glColor3f(0.39, 0.64, 0.24);
        Circle::draw(-10.0f, -1500.0f, 2000.0f);

        glColor3f(0.22, 0.3, 0.17);
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

    static void Scene11() {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glVertex2f(0.0f, 200.0f);
        glColor3f(1, 1, 1);
        glVertex2f(1920.0f, 200.0f);
        glColor3f(0.7, 0.87, 1);
        glVertex2f(1920.0f, 1080.0f);
        glColor3f(0.7, 0.87, 1);
        glVertex2f(0.0f, 1080.0f);
        glEnd();
        
        // Ground
        glColor3f(0.67, 0.97, 0.5);
        glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1920.0f, 0.0f);
        glVertex2f(1920.0f, 250.0f);
        glVertex2f(0.0f, 250.0f);
        glEnd();

        glColor3f(0.22, 0.3, 0.17);
        glBegin(GL_LINES);
        glVertex2f(0.0f, 250.0f);
        glVertex2f(1920.0f, 250.0f);
        glEnd();
    }

};

