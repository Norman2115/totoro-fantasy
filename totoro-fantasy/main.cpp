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
#include "Tree.h"
#include "Portal.h"
#include "Island.h"
#include "Flower.h"
#include "Mushroom1.h"

Portal portal;
Totoro totoro;

Catbus catbus{ 500, 250, 600, false };

static void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1920.0, 0.0, 1080.0);
}


static void displayScene1() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene1();
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

    FullMoon moon;
    moon.draw(1520, 950, 140, Colors::NIGHT_FULL_MOON);


    DayCloudTwo cloud1;
    cloud1.draw(1080, 900, 150, Colors::NIGHT_CLOUD);
    DayCloudOne cloud2;
    cloud2.draw(1080, 900, 150, Colors::NIGHT_CLOUD);    
    DayCloudTwo cloud3;
    cloud3.draw(1080, 900, 150, Colors::NIGHT_CLOUD);
    glFlush();
    glutSwapBuffers(); 

}

static void displayScene2() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene2();
  
    //Upper Level
    GrassTwo grass1;
    grass1.drawWithRotation(1550, 388, 57, 9, Colors::GRASS_NIGHT);
    GrassTwo grass2;
    grass2.drawWithRotation(800, 160, 55, 25, Colors::GRASS_NIGHT);
    GrassTwo grass3;
    grass3.drawWithRotation(600, 45, 55,33, Colors::GRASS_NIGHT);
    GrassTwo grass4;
    grass4.drawWithRotation(400, 157, 40, 340, Colors::GRASS_NIGHT);
    GrassTwo grass5;
    grass5.drawWithRotation(30, 258, 40, 345, Colors::GRASS_NIGHT);
    GrassOne grass9;
    grass9.drawWithRotation(1750, 400, 65, 1, Colors::GRASS_NIGHT);
    GrassOne grass10;
    grass10.drawWithRotation(900, 208, 60, 22, Colors::GRASS_NIGHT);
    GrassOne grass11;
    grass11.drawWithRotation(550, 98, 50, 335, Colors::GRASS_NIGHT);    

    //Lower Level
    GrassOne grass12;
    grass12.drawWithRotation(90, 40, 46, 330, Colors::GRASS_NIGHT);  
    GrassTwo grass7;
    grass7.drawWithRotation(440, 85, 46, 335, Colors::GRASS_NIGHT);
    GrassOne grass13;
    grass13.drawWithRotation(950, 85, 46, 30, Colors::GRASS_NIGHT);
    GrassTwo grass14;
    grass14.drawWithRotation(1400, 250, 43, 13, Colors::GRASS_NIGHT);
    GrassTwo grass8;
    grass8.drawWithRotation(1800, 200, 50, 10, Colors::GRASS_NIGHT);

    glFlush();
    glutSwapBuffers(); 
}

static void displayScene3() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene3();

    //Upper Level
    SmallRockOne rock1;
    rock1.draw(1800, 210, 150, Colors::ROCK);
    GrassTwo grass1;
    grass1.draw(200, 250, 45, Colors::GRASS_NIGHT);
    GrassTwo grass2;
    grass2.draw(460, 249, 47, Colors::GRASS_NIGHT);
    GrassOne grass3;
    grass3.draw(260, 250, 55, Colors::GRASS_NIGHT);
    GrassOne grass4;
    grass4.draw(760, 250, 60, Colors::GRASS_NIGHT);
    GrassTwo grass5;
    grass5.draw(30, 248, 46, Colors::GRASS_NIGHT);
    GrassTwo grass6;
    grass6.draw(1150, 250, 46, Colors::GRASS_NIGHT);
    SmallRockTwo rock2;
    rock2.draw(1190, 235, 150, Colors::ROCK);

    //Lower Level
    GrassOne grass7;
    grass7.draw(40, 150, 60, Colors::GRASS_NIGHT);
    GrassOne grass8;
    grass8.draw(190, 80, 59, Colors::GRASS_NIGHT);
    GrassOne grass9;
    grass9.draw(760, 190, 61, Colors::GRASS_NIGHT);
    GrassOne grass10;
    grass10.draw(1230, 44, 62, Colors::GRASS_NIGHT);
    GrassOne grass11;
    grass11.draw(1450, 90, 59, Colors::GRASS_NIGHT);
    GrassTwo grass12;
    grass12.draw(350, 160, 46, Colors::GRASS_NIGHT);
    GrassTwo grass13;
    grass13.draw(550, 190, 44, Colors::GRASS_NIGHT);
    GrassTwo grass14;
    grass14.draw(900, 120, 43, Colors::GRASS_NIGHT);
    GrassTwo grass15;
    grass15.draw(1200, 200, 44, Colors::GRASS_NIGHT);
    GrassTwo grass16;
    grass16.draw(1800, 110, 46, Colors::GRASS_NIGHT);
    GrassTwo grass17;
    grass17.draw(1600, 220, 47, Colors::GRASS_NIGHT);
    GrassOne grass18;
    grass18.draw(1290, 220, 59, Colors::GRASS_NIGHT);
    GrassTwo grass19;
    grass19.draw(1895, 203, 48, Colors::GRASS_NIGHT);

    portal.draw(1500.0f, 410.0f, 90.0f, 140.0f);  

    glFlush();
    glutSwapBuffers(); 
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

    //Upper Level
    GrassOne grass1;
    grass1.draw(190, 250, 55, Colors::GRASS_DAY);
    GrassTwo grass2;
    grass2.draw(456, 249, 50, Colors::GRASS_DAY);
    GrassOne grass3;
    grass3.draw(1210, 250, 50, Colors::GRASS_DAY);
    GrassTwo grass4;
    grass4.draw(266, 250, 52, Colors::GRASS_DAY);
    GrassTwo grass5;
    grass5.draw(766, 250, 55, Colors::GRASS_DAY);
    GrassTwo grass6;
    grass6.draw(1730, 249, 53, Colors::GRASS_DAY);
    GrassOne grass7;
    grass7.draw(1820, 250, 49, Colors::GRASS_DAY);
    GrassOne grass8;
    grass8.draw(810, 248, 52, Colors::GRASS_DAY);
    GrassOne grass9;
    grass9.draw(20, 248, 52, Colors::GRASS_DAY);

    //Lower Level
    GrassTwo grass10;
    grass10.draw(50, 150, 60, Colors::GRASS_DAY);
    GrassTwo grass11;
    grass11.draw(180, 70, 59, Colors::GRASS_DAY);
    GrassTwo grass13;
    grass13.draw(1240, 80, 62, Colors::GRASS_DAY);
    GrassTwo grass14;
    grass14.draw(1550, 60, 59, Colors::GRASS_DAY);
    GrassOne grass15;
    grass15.draw(300, 140, 46, Colors::GRASS_DAY);
    GrassOne grass16;
    grass16.draw(540, 120, 44, Colors::GRASS_DAY);
    GrassOne grass17;
    grass17.draw(890, 95, 43, Colors::GRASS_DAY);
    GrassOne grass18;
    grass18.draw(1100, 150, 44, Colors::GRASS_DAY);
    GrassOne grass19;
    grass19.draw(1830, 30, 46, Colors::GRASS_DAY);
    GrassOne grass20;
    grass20.draw(1450, 180, 47, Colors::GRASS_DAY);

    IslandOne island1;
    island1.draw(700, 700, 250, Colors::ISLAND_DAY);
    IslandTwo island2;
    island2.draw(1500, 600, 200, Colors::ISLAND_DAY);

    mushroom1 mushroom1;
    mushroom1.draw(900, 700, 250, Colors::MUSHROOM_DAY);
    mushroom2 mushroom2;
    mushroom2.draw(300, 700, 250, Colors::MUSHROOM_DAY);
    mushroom3 mushroom3;
    mushroom3.draw(700, 700, 250, Colors::MUSHROOM_DAY);

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
  
    //Upper Level
    GrassTwo grass1;
    grass1.draw(190, 250, 55, Colors::GRASS_NIGHT);
    GrassOne grass2;
    grass2.draw(456, 249, 50, Colors::GRASS_NIGHT);
    GrassTwo grass3;
    grass3.draw(1210, 250, 50, Colors::GRASS_NIGHT);
    GrassOne grass4;
    grass4.draw(266, 250, 52, Colors::GRASS_NIGHT);
    GrassOne grass5;
    grass5.draw(766, 250, 55, Colors::GRASS_NIGHT);
    GrassOne grass6;
    grass6.draw(1730, 249, 53, Colors::GRASS_NIGHT);
    GrassTwo grass7;
    grass7.draw(1820, 250, 49, Colors::GRASS_NIGHT);
    GrassTwo grass8;
    grass8.draw(810, 248, 52, Colors::GRASS_NIGHT);
    GrassTwo grass9;
    grass9.draw(20, 248, 52, Colors::GRASS_NIGHT);

    //Lower Level
    GrassOne grass10;
    grass10.draw(50, 150, 60, Colors::GRASS_NIGHT);
    GrassOne grass11;
    grass11.draw(180, 70, 59, Colors::GRASS_NIGHT);
    GrassOne grass13;
    grass13.draw(1240, 80, 62, Colors::GRASS_NIGHT);
    GrassOne grass14;
    grass14.draw(1550, 60, 59, Colors::GRASS_NIGHT);
    GrassTwo grass15;
    grass15.draw(300, 140, 46, Colors::GRASS_NIGHT);
    GrassTwo grass16;
    grass16.draw(540, 120, 44, Colors::GRASS_NIGHT);
    GrassTwo grass17;
    grass17.draw(890, 95, 43, Colors::GRASS_NIGHT);
    GrassTwo grass18;
    grass18.draw(1100, 150, 44, Colors::GRASS_NIGHT);
    GrassTwo grass19;
    grass19.draw(1830, 30, 46, Colors::GRASS_NIGHT);
    GrassTwo grass20;
    grass20.draw(1450, 180, 47, Colors::GRASS_NIGHT);

    glFlush();
    glutSwapBuffers(); 

}

static void displayScene7() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene6_7();

    //Upper Level
    GrassTwo grass1;
    grass1.draw(190, 250, 55, Colors::GRASS_NIGHT);
    GrassOne grass2;
    grass2.draw(456, 249, 50, Colors::GRASS_NIGHT);
    GrassTwo grass3;
    grass3.draw(1210, 250, 50, Colors::GRASS_NIGHT);
    GrassOne grass4;
    grass4.draw(266, 250, 52, Colors::GRASS_NIGHT);
    GrassOne grass5;
    grass5.draw(766, 250, 55, Colors::GRASS_NIGHT);
    GrassOne grass6;
    grass6.draw(1730, 249, 53, Colors::GRASS_NIGHT);
    GrassTwo grass7;
    grass7.draw(1820, 250, 49, Colors::GRASS_NIGHT);
    GrassTwo grass8;
    grass8.draw(810, 248, 52, Colors::GRASS_NIGHT);
    GrassTwo grass9;
    grass9.draw(20, 248, 52, Colors::GRASS_NIGHT);

    //Lower Level
    GrassOne grass10;
    grass10.draw(50, 150, 60, Colors::GRASS_NIGHT);
    GrassOne grass11;
    grass11.draw(180, 70, 59, Colors::GRASS_NIGHT);
    GrassOne grass13;
    grass13.draw(1240, 80, 62, Colors::GRASS_NIGHT);
    GrassOne grass14;
    grass14.draw(1550, 60, 59, Colors::GRASS_NIGHT);
    GrassTwo grass15;
    grass15.draw(300, 140, 46, Colors::GRASS_NIGHT);
    GrassTwo grass16;
    grass16.draw(540, 120, 44, Colors::GRASS_NIGHT);
    GrassTwo grass17;
    grass17.draw(890, 95, 43, Colors::GRASS_NIGHT);
    GrassTwo grass18;
    grass18.draw(1100, 150, 44, Colors::GRASS_NIGHT);
    GrassTwo grass19;
    grass19.draw(1830, 30, 46, Colors::GRASS_NIGHT);
    GrassTwo grass20;
    grass20.draw(1450, 180, 47, Colors::GRASS_NIGHT);

    totoro.draw(960.0f, 450.0f, 300.0f);

    glFlush();
    glutSwapBuffers(); 

}

static void displayScene8() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene8();

    //Upper Level
    GrassOne grass1;
    grass1.drawWithRotation(1750, 450, 60, 2, Colors::GRASS_NIGHT);
    GrassOne grass2;
    grass2.drawWithRotation(800, 320, 58, 12, Colors::GRASS_NIGHT);
    GrassOne grass3;
    grass3.drawWithRotation(300, 128, 55, 24, Colors::GRASS_NIGHT);
    GrassTwo grass4;
    grass4.drawWithRotation(1850, 448, 65, 358, Colors::GRASS_NIGHT);
    GrassTwo grass5;
    grass5.drawWithRotation(900, 350, 60, 15, Colors::GRASS_NIGHT);
    GrassTwo grass6;
    grass6.drawWithRotation(550, 237, 60, 22, Colors::GRASS_NIGHT);
    GrassOne grass7;
    grass7.drawWithRotation(1300, 425, 56, 5, Colors::GRASS_NIGHT);
    GrassOne grass8;
    grass8.drawWithRotation(1500, 445, 58, 5, Colors::GRASS_NIGHT);
    GrassTwo grass9;
    grass9.drawWithRotation(80, 10, 40, 30, Colors::GRASS_NIGHT);

    //Inner Level
    GrassOne grass10;
    grass10.drawWithRotation(380, 90, 60, 20, Colors::GRASS_NIGHT);
    GrassOne grass11;
    grass11.drawWithRotation(1000, 300, 58, 8, Colors::GRASS_NIGHT);
    GrassOne grass12;
    grass12.drawWithRotation(1700, 350, 55, 3, Colors::GRASS_NIGHT);
    GrassTwo grass13;
    grass13.drawWithRotation(600, 75, 65, 355, Colors::GRASS_NIGHT);
    GrassTwo grass14;
    grass14.drawWithRotation(1200, 180, 60, 15, Colors::GRASS_NIGHT);
    GrassTwo grass15;
    grass15.drawWithRotation(1500, 60, 60, 12, Colors::GRASS_NIGHT);
    GrassOne grass16;
    grass16.drawWithRotation(1850, 100, 58, 357, Colors::GRASS_NIGHT);

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

    //Upper level
    GrassTwo grass1;
    grass1.drawWithRotation(30, 500, 20, 358, Colors::GRASS_DAY);
    GrassTwo grass2;
    grass2.drawWithRotation(130, 495, 20, 355, Colors::GRASS_DAY);
    GrassOne grass3;
    grass3.drawWithRotation(250, 483, 20, 347, Colors::GRASS_DAY);
    GrassTwo grass5;
    grass5.drawWithRotation(550, 420, 20, 345, Colors::GRASS_DAY);
    GrassOne grass6;
    grass6.drawWithRotation(700, 369, 25, 342, Colors::GRASS_DAY);
    GrassOne grass7;
    grass7.drawWithRotation(900, 280, 25, 332, Colors::GRASS_DAY);
    GrassTwo grass8;
    grass8.drawWithRotation(1050, 195, 25, 325, Colors::GRASS_DAY);
    GrassOne grass9;
    grass9.drawWithRotation(1250, 52, 25, 315, Colors::GRASS_DAY);
    GrassTwo grass10;
    grass10.drawWithRotation(1300, 108, 20, 10, Colors::GRASS_DAY);
    GrassOne grass11;
    grass11.drawWithRotation(1350, 120, 20, 15, Colors::GRASS_DAY);
    GrassTwo grass12;
    grass12.drawWithRotation(1500, 153, 20, 5, Colors::GRASS_DAY);

    //Lower Level
    GrassTwo grass13;
    grass13.drawWithRotation(60, 100, 20, 358, Colors::GRASS_DAY);
    GrassTwo grass14;
    grass14.drawWithRotation(100, 400, 20, 355, Colors::GRASS_DAY);
    GrassOne grass15;
    grass15.drawWithRotation(220, 150, 20, 355, Colors::GRASS_DAY);
    GrassOne grass17;
    grass17.drawWithRotation(500, 300, 25, 342, Colors::GRASS_DAY);
    GrassOne grass18;
    grass18.drawWithRotation(780, 50, 25, 332, Colors::GRASS_DAY);
    GrassTwo grass19;
    grass19.drawWithRotation(1100, 70, 25, 2, Colors::GRASS_DAY);
    GrassTwo grass20;
    grass20.drawWithRotation(1450, 25, 20, 350, Colors::GRASS_DAY);

    glFlush();
    glutSwapBuffers(); 

}

static void displayScene11() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene11();

    //Upper Level
    GrassTwo grass1;
    grass1.draw(200, 250, 45, Colors::GRASS_DAY);
    GrassTwo grass2;
    grass2.draw(460, 249, 47, Colors::GRASS_DAY);
    GrassTwo grass3;
    grass3.draw(1200, 250, 46, Colors::GRASS_DAY);
    GrassOne grass4;
    grass4.draw(260, 250, 55, Colors::GRASS_DAY);
    GrassOne grass5;
    grass5.draw(760, 250, 60, Colors::GRASS_DAY);
    GrassOne grass6;
    grass6.draw(1700, 249, 57, Colors::GRASS_DAY);
    GrassTwo grass7;
    grass7.draw(1800, 250, 44, Colors::GRASS_DAY);
    GrassTwo grass8;
    grass8.draw(830, 248, 46, Colors::GRASS_DAY);
    GrassTwo grass9;
    grass9.draw(30, 248, 46, Colors::GRASS_DAY);
    //Lower Level
    GrassOne grass10;
    grass10.draw(50, 100, 60, Colors::GRASS_DAY);
    GrassOne grass11;
    grass11.draw(180, 70, 59, Colors::GRASS_DAY);
    GrassOne grass12;
    grass12.draw(750, 160, 61, Colors::GRASS_DAY);
    GrassOne grass13;
    grass13.draw(1240, 30, 62, Colors::GRASS_DAY);
    GrassOne grass14;
    grass14.draw(1550, 60, 59, Colors::GRASS_DAY);
    GrassTwo grass15;
    grass15.draw(300, 140, 46, Colors::GRASS_DAY);
    GrassTwo grass16;
    grass16.draw(540, 180, 44, Colors::GRASS_DAY);
    GrassTwo grass17;
    grass17.draw(890, 65, 43, Colors::GRASS_DAY);
    GrassTwo grass18;
    grass18.draw(1100, 150, 44, Colors::GRASS_DAY);
    GrassTwo grass19;
    grass19.draw(1830, 90, 46, Colors::GRASS_DAY);
    GrassTwo grass20;
    grass20.draw(1450, 180, 47, Colors::GRASS_DAY);

    Flower flower;
    flower.draw(200, 200, 200, 40, Colors::DAY_CLOUD);

    glFlush();
    glutSwapBuffers();

}

static void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glFlush();
}

static void updateCatbusFrame(int value) {
    catbus.updateFrame();
    glutPostRedisplay();
    glutTimerFunc(30, updateCatbusFrame, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_ALPHA); 
    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(0, 0); 
    glutCreateWindow("Little Girl's Adventure");
    init();

    glutDisplayFunc(displayScene11); // Change this to display the scene you want
    portal.startTimer(); 
    glutFullScreen();
    glutMainLoop();

    return 0;
}