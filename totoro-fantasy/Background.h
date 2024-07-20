#pragma once
#include <gl/glut.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "Constants.h"
#include "Circle.h"
#include "Elements.h"
#include "Star.h"
#include "Mushroom1.h"
#include "Cloud.h"
#include "Island.h"
#include "Flower.h"
#include "Character.h"


class Background {
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
    
    static void Scene5(LittleGirl& girl, std::vector<Island*>& islands, std::vector<Elements*>& grass, std::vector<Cloud*>& clouds, std::vector<Mushroom1*>& mushrooms, std::vector<Flower*>& flower, DaySunOne sun, int currentStep, int steps) {
        float a = (float)currentStep / steps; // Appear
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

        sun.draw();

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

        // Dont Move
        IslandTwo island1;
        island1.draw(700, 850, 150, Colors::ISLAND_DAY);
        IslandOne island2;
        island2.draw(1300, 700, 120, Colors::ISLAND_DAY);
        mushrooms.at(0)->draw(false);
        mushrooms.at(1)->draw(false);
        mushrooms.at(2)->draw(false);

        // Move Fast
        clouds.at(0)->draw();
        clouds.at(1)->draw();
        clouds.at(2)->draw();
        clouds.at(3)->draw();
        clouds.at(4)->draw();
        clouds.at(5)->draw();

        /* Line for Sunset
        glColor3f(0.39, 0.64, 0.24);
        Circle::draw(-490.0f, -2617.0f, 3600.0f);
        */

        // Move Infinite
        mushrooms.at(4)->draw(true);
        mushrooms.at(3)->draw(true);
        mushrooms.at(5)->draw(true);
        mushrooms.at(6)->draw(true);
        mushrooms.at(7)->draw(true);

        flower.at(0)->draw(60);
        flower.at(1)->draw(100);
        flower.at(2)->draw(130);

        for (auto& grass : grass) {
            grass->draw();
        }

        girl.drawSideView();
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

        mushroomOne mushroom2(300, 0, 800, Colors::MUSHROOM_NIGHT);
        mushroom2.draw(true);
        mushroomThree mushroom1(-150, -150, 800, Colors::MUSHROOM_NIGHT);
        mushroom1.draw(true);
        mushroomOne mushroom3(570, 15, 380, Colors::MUSHROOM_NIGHT);
        mushroom3.draw(true);

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

        mushroomThree mushroom1(0, -50, 300, Colors::MUSHROOM_NIGHT);
        mushroom1.draw(true);
        mushroomOne mushroom2(100, -60, 100, Colors::MUSHROOM_NIGHT);
        mushroom2.draw(true);
        mushroomOne mushroom4(580, 19, 150, Colors::MUSHROOM_NIGHT);
        mushroom4.draw(true);
        mushroomThree mushroom3(500, 20, 100, Colors::MUSHROOM_NIGHT);
        mushroom3.draw(true);

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

    static void Scene12() {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        glColor3f(0, 0, 0);
        glVertex2f(0, 0);
        glVertex2f(0, 1080);
        glVertex2f(1920, 0);
        glVertex2f(1920, 1080);
        glEnd();

        // T
        glLineWidth(3.0f);
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(600.0f, 750.0f);
        glVertex2f(800.0f, 750.0f);
        glEnd();

        //T
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(700.0f, 750.0f);
        glVertex2f(700.0f, 550.0f);
        glEnd();

        //h
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(750.0f, 700.0f);
        glVertex2f(750.0f, 550.0f);
        glEnd();

        //h
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(750.0f, 600.0f);
        glVertex2f(800.0f, 600.0f);
        glEnd();

        //h
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(800.0f, 550.0f);
        glVertex2f(800.0f, 600.0f);
        glEnd();

        //e
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(840.0f, 550.0f);
        glVertex2f(840.0f, 600.0f);
        glEnd();

        //e
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(840.0f, 600.0f);
        glVertex2f(890.0f, 600.0f);
        glEnd();

        //e
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(890.0f, 600.0f);
        glVertex2f(890.0f, 575.0f);
        glEnd();

        //e
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(840.0f, 575.0f);
        glVertex2f(890.0f, 575.0f);
        glEnd();

        //e
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(840.0f, 550.0f);
        glVertex2f(890.0f, 550.0f);
        glEnd();

        //E
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(1000.0f, 450.0f);
        glVertex2f(1000.0f, 250.0f);
        glEnd();

        //E
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(1000.0f, 450.0f);
        glVertex2f(1100.0f, 450.0f);
        glEnd();

        //E
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(1000.0f, 350.0f);
        glVertex2f(1100.0f, 350.0f);
        glEnd();

        //E
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(1000.0f, 250.0f);
        glVertex2f(1100.0f, 250.0f);
        glEnd();

        //n
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(1140.0f, 350.0f);
        glVertex2f(1140.0f, 250.0f);
        glEnd();

        //n
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(1140.0f, 335.0f);
        glVertex2f(1190.0f, 335.0f);
        glEnd();

        //n
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(1190.0f, 335.0f);
        glVertex2f(1190.0f, 250.0f);
        glEnd();

        //d
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(1230.0f, 300.0f);
        glVertex2f(1230.0f, 250.0f);
        glEnd();

        //d
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(1230.0f, 300.0f);
        glVertex2f(1280.0f, 300.0f);
        glEnd();

        //d
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(1230.0f, 250.0f);
        glVertex2f(1280.0f, 250.0f);
        glEnd();

        //d
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(1280.0f, 400.0f);
        glVertex2f(1280.0f, 250.0f);
        glEnd();
    }
};

