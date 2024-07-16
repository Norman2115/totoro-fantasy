#include <windows.h>
#include <iostream>
#include <gl/glut.h>
#include "Cloud.h"
#include "Sun.h"
#include "Moon.h"
#include "Colors.h"
#include "Background.h"
#include "Character.h"
#include "Elements.h"
#include "House.h"
#include "Ellipse.h"
#include "Catbus.h"
#include "Totoro.h"
#include "Rainbow.h"
#include "Portal.h"

Portal portal;
Totoro totoro;

static void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1920.0, 0.0, 1080.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

static void displayScene1() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene1();
    DayCloudTwo cloud;
    cloud.draw(1080, 900, 150, Colors::NIGHT_CLOUD);
    House house;
    house.draw(200.0f, 450.0f, 500.0f);

    //Upper Level
    GrassTwo grass1;
    grass1.draw(200, 200, 45, Colors::GRASS_NIGHT);
    GrassTwo grass2;
    grass2.draw(460, 199, 47, Colors::GRASS_NIGHT);
    GrassTwo grass3;
    grass3.draw(1200, 200, 46, Colors::GRASS_NIGHT);
    GrassOne grass4;
    grass4.draw(260, 200, 55, Colors::GRASS_NIGHT);
    GrassOne grass5;
    grass5.draw(760, 200, 60, Colors::GRASS_NIGHT);
    GrassOne grass6;
    grass6.draw(1700, 199, 57, Colors::GRASS_NIGHT);
    GrassTwo grass7;
    grass7.draw(1800, 200, 44, Colors::GRASS_NIGHT);
    GrassTwo grass8;
    grass8.draw(830, 198, 46, Colors::GRASS_NIGHT);
    GrassTwo grass9;
    grass9.draw(30, 198, 46, Colors::GRASS_NIGHT);

    //Lower Level
    GrassOne grass10;
    grass10.draw(50, 100, 60, Colors::GRASS_NIGHT);
    GrassOne grass11;
    grass11.draw(180, 70, 59, Colors::GRASS_NIGHT);    
    GrassOne grass12;
    grass12.draw(750, 160, 61, Colors::GRASS_NIGHT);    
    GrassOne grass13;
    grass13.draw(1240, 30, 62, Colors::GRASS_NIGHT);    
    GrassOne grass14;
    grass14.draw(1550, 60, 59, Colors::GRASS_NIGHT);
    GrassTwo grass15;
    grass15.draw(300, 110, 46, Colors::GRASS_NIGHT);    
    GrassTwo grass16;
    grass16.draw(540, 140, 44, Colors::GRASS_NIGHT);    
    GrassTwo grass17;
    grass17.draw(890, 65, 43, Colors::GRASS_NIGHT);    
    GrassTwo grass18;
    grass18.draw(1100, 150, 44, Colors::GRASS_NIGHT);    
    GrassTwo grass19;
    grass19.draw(1830, 90, 46, Colors::GRASS_NIGHT);  
    GrassTwo grass20;
    grass20.draw(1450, 180, 47, Colors::GRASS_NIGHT);
    glFlush();
    glutSwapBuffers();
}

static void displayScene2() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene2();

    glFlush();
    glutSwapBuffers();
}

static void displayScene3() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene3();
    portal.draw(1000.0f, 400.0f, 100.0f, 160.0f);  // Call the draw method of the portal with parameters
    glutSwapBuffers(); // Swap the buffers for double buffering
}

static void displayScene4() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene4();
    RainbowOne rainbow;
    rainbow.draw(1280, 800, 200, Colors::RAINBOW);
    DayCloudOne cloud;
    cloud.draw(1180, 800, 130, Colors::DAY_CLOUD);
    DayCloudTwo cloud1;
    cloud1.draw(1390, 800, 140, Colors::DAY_CLOUD);
    DaySunOne sun;
    sun.draw(180, 930, 150, Colors::DAY_SUN);
    glFlush();
    glutSwapBuffers();
}

static void displayScene5() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene5();
    glFlush();
    glutSwapBuffers();
}

static void displayScene6() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene6_7();
    glFlush();
    glutSwapBuffers();
}

static void displayScene7() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene6_7();
    totoro.draw(960.0f, 370.0f, 300.0f); // Draw Totoro at center with larger size
    glFlush();
    glutSwapBuffers();
}

static void displayScene8() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene8();
    glFlush();
    glutSwapBuffers();
}

static void displayScene9() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene9();
    glFlush();
    glutSwapBuffers();
}

static void displayScene10() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene10();
    glFlush();
    glutSwapBuffers();
}

static void displayScene11() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene11();
    glFlush();
    glutSwapBuffers();
}

static void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_ALPHA); // Use double buffering
    // Get screen width and height
    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);

    // Use screen width and height directly
    glutInitWindowSize(screenWidth, screenHeight);

    // Center the window on the screen
    glutInitWindowPosition(0, 0); // Position at top-left corner for full screen

    glutCreateWindow("Little Girl's Adventure");
    init();
    glutDisplayFunc(displayScene7);
    portal.startTimer(); // Start the timer within the portal class
    glutFullScreen();
    glutMainLoop();

    return 0;
}
