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
#include "Totoro.h"


static void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1920.0, 0.0, 1080.0);
}

static void displayScene1() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene1(); 
    DayCloudTwo cloud;
    cloud.draw(1080, 900, 150, Colors::NIGHT_CLOUD); 
    House house;
    house.draw(200.0f, 450.0f, 500.0f);
}

static void displayScene2() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene2(); 
    glFlush();
}

static void displayScene3() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene3();
    glFlush();
}

static void displayScene4() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene4();
    glFlush();
}

static void displayScene5() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene5();
    glFlush();
}

static void displayScene6() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene6_7();
    glFlush();
}

static void displayScene7() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene6_7();
    Totoro totoro;
    totoro.init();
    totoro.draw(0.0f, 0.0f, 0.5f);
    glFlush();
}

static void displayScene8() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene8();
    glFlush();
}

static void displayScene9() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene9();
    glFlush();
}

static void displayScene10() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene10();
    glFlush();
}

static void displayScene11() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene11();

    glFlush();
}

static void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Little Girl's Adventure");
    init();
    glutDisplayFunc(displayScene7);
    glutMainLoop();

    return 0;
}