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
#include "Elements.h"
#include "Star.h"
#include "Mushroom1.h"

class Background {
private:

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

        Star::draw(false);

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

        Star::draw(false);

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

        Star::draw(false);

        // Ground
        glColor3f(0.39, 0.64, 0.24);
        glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1920.0f, 0.0f);
        glVertex2f(1920.0f, 250.0f);
        glVertex2f(0.0f, 250.0f);
        glEnd();


    }

    static void Cave() {

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

        glPushMatrix();
        glLineWidth(1.0f); 
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
        glPopMatrix(); 

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


        glPushMatrix(); 
        glLineWidth(1.0f);
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
        glPopMatrix();

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

        glPushMatrix();
        glLineWidth(1.0f);
        glColor3f(0.22, 0.3, 0.17);
        glBegin(GL_LINES);
        glVertex2f(0.0f, 250.0f);
        glVertex2f(1920.0f, 250.0f);
        glEnd();
        glPopMatrix();
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

            glColor3f(0.22, 0.3, 0.17);
            glBegin(GL_LINES);
            glVertex2f(0.0f, 250.0f);
            glVertex2f(1920.0f, 250.0f);
            glEnd();


            //Lower Level
            GrassLineTwo grass1;
            grass1.draw(200, 220, 45, Colors::GRASS_NIGHT);
            GrassLineOne grass3;
            grass3.draw(280, 230, 55, Colors::GRASS_NIGHT);
            GrassLineTwo grass5;
            grass5.draw(30, 218, 46, Colors::GRASS_NIGHT);
            GrassLineOne grass7;
            grass7.draw(40, 150, 60, Colors::GRASS_NIGHT);
            GrassLineOne grass8;
            grass8.draw(190, 80, 59, Colors::GRASS_NIGHT);
            GrassLineOne grass9;
            grass9.draw(760, 190, 61, Colors::GRASS_NIGHT);
            GrassLineOne grass10;
            grass10.draw(1230, 44, 62, Colors::GRASS_NIGHT);
            GrassLineOne grass11;
            grass11.draw(1450, 90, 59, Colors::GRASS_NIGHT);
            GrassLineTwo grass12;
            grass12.draw(350, 160, 46, Colors::GRASS_NIGHT);
            GrassLineTwo grass13;
            grass13.draw(550, 190, 44, Colors::GRASS_NIGHT);
            GrassLineTwo grass14;
            grass14.draw(900, 120, 43, Colors::GRASS_NIGHT);
            GrassLineTwo grass15;
            grass15.draw(1200, 200, 44, Colors::GRASS_NIGHT);
            GrassLineTwo grass16;
            grass16.draw(1800, 110, 46, Colors::GRASS_NIGHT);
            GrassLineTwo grass17;
            grass17.draw(1600, 220, 47, Colors::GRASS_NIGHT);
            GrassLineOne grass18;
            grass18.draw(1290, 220, 59, Colors::GRASS_NIGHT);
            GrassLineTwo grass19;
            grass19.draw(1895, 203, 48, Colors::GRASS_NIGHT);

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

        Star::draw(true);

        // Ground
        glColor3f(0.39, 0.64, 0.24);
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

        Star::draw(true);

        mushroomOne mushroom2;
        mushroom2.draw(300, 0, 800, Colors::MUSHROOM_NIGHT, true);
        mushroomThree mushroom1;
        mushroom1.draw(-150, -150, 800, Colors::MUSHROOM_NIGHT, true);
        mushroomOne mushroom3;
        mushroom3.draw(570, 15, 380, Colors::MUSHROOM_NIGHT, true);



        // Ground
        glColor3f(0.39, 0.64, 0.24);
        Circle::draw(1700.0f, -2750.0f, 3200.0f);
    }

    static void Scene9() {
        glClear(GL_COLOR_BUFFER_BIT);

        Star::draw(true);

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

        mushroomThree mushroom1;
        mushroom1.draw(0, -50, 300, Colors::MUSHROOM_NIGHT, true);
        mushroomOne mushroom2;
        mushroom2.draw(100, -60, 100, Colors::MUSHROOM_NIGHT, true);
        mushroomOne mushroom4;
        mushroom4.draw(580, 19, 150, Colors::MUSHROOM_NIGHT, true);
        mushroomThree mushroom3;
        mushroom3.draw(500, 20, 100, Colors::MUSHROOM_NIGHT, true);




        // Right Hill
        glColor3f(0.39, 0.64, 0.24);
        Circle::draw(2800.0f, -1650.0f, 2000.0f);

        //Left Hill
        glColor3f(0.39, 0.64, 0.24);
        Circle::draw(550.0f, -2650.0f, 2700.0f);

    }

    static void Scene10() {
        glClear(GL_COLOR_BUFFER_BIT);

        // Sky
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glVertex2f(0.0f, 0.0f);
        glColor3f(1, 1, 1);
        glVertex2f(1920.0f, 0.0f);
        glColor3f(0.7, 0.87, 1);
        glVertex2f(1920.0f, 1080.0f);
        glColor3f(0.7, 0.87, 1);
        glVertex2f(0.0f, 1080.0f);
        glEnd();

        // Right Hill
        glColor3f(0.67, 0.97, 0.5);
        Circle::draw(2000.0f, -2500.0f, 2700.0f);

        glColor3f(0.22, 0.3, 0.17);
        glBegin(GL_LINE_LOOP);
        float rightHillRadius = 2700.0f;
        for (int i = 0; i <= 360; ++i) {
            float angle = static_cast<float>(i) * Constants::PI / 180.0f;
            float x = 2000.0f + rightHillRadius * cosf(angle);
            float y = -2500.0f + rightHillRadius * sinf(angle);
            glVertex2f(x, y);
        }
        glEnd();

        // Left Hill
        glColor3f(0.67, 0.97, 0.5);
        Circle::draw(-10.0f, -1500.0f, 2000.0f);

        glColor3f(0.22, 0.3, 0.17);
        glBegin(GL_LINE_LOOP);
        float leftHillRadius = 2000.0f;
        for (int i = 0; i <= 360; ++i) {
            float angle = static_cast<float>(i) * Constants::PI / 180.0f;
            float x = -10.0f + leftHillRadius * cosf(angle);
            float y = -1500.0f + leftHillRadius * sinf(angle);
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

