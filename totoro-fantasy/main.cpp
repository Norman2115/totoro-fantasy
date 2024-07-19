#include <windows.h>
#include <iostream>
#include <gl/glut.h>
#include <vector>
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
#include "Thunder.h"
#include "Rain.h"

/////   Declare global variables    /////

Portal portal;
Totoro totoro;
LittleGirl girl(500, 150, 180, 0, false);
// TotoroSide totoroSide;
Catbus catbus{ 500, 180, 600, false };
Rain rain{ 500 };

std::vector<Cloud*> clouds_scene1{
    new DayCloudTwo(1080, 900, 150, Colors::NIGHT_CLOUD),
    new DayCloudOne(400, 850, 150, Colors::NIGHT_CLOUD),
    new DayCloudTwo(1600, 800, 150, Colors::NIGHT_CLOUD)
};

Thunder thunderScene1(clouds_scene1, 2.0f);

std::vector<Cloud*> clouds_scene2{
    new DayCloudOne(1080, 810, 120, Colors::NIGHT_CLOUD),
    new DayCloudOne(400, 850, 120, Colors::NIGHT_CLOUD),
    new DayCloudTwo(1700, 880, 120, Colors::NIGHT_CLOUD),
    new DayCloudTwo(150, 750, 120, Colors::NIGHT_CLOUD)
};

Thunder thunderScene2(clouds_scene2, 2.0f);

std::vector<Cloud*> clouds_scene3{
    new DayCloudOne{ 200, 850, 150, Colors::NIGHT_CLOUD },
    new DayCloudTwo{ 700, 860, 150, Colors::NIGHT_CLOUD },
    new DayCloudOne{ 1800, 870, 150, Colors::NIGHT_CLOUD }
};

Thunder thunderScene3(clouds_scene3, 2.0f);

// Static (Rainbow)
DayCloudOne cloud1_scene4(1290, 745, 130, Colors::DAY_CLOUD);
DayCloudTwo cloud2_scene4(1510, 745, 140, Colors::DAY_CLOUD);

DayCloudTwo cloud3_scene4(140, 850, 130, Colors::DAY_CLOUD);
DayCloudTwo cloud4_scene4(1940, 800, 130, Colors::DAY_CLOUD);
DayCloudTwo cloud5_scene4(760, 700, 40, Colors::DAY_CLOUD);
DayCloudTwo cloud6_scene4(1760, 600, 30, Colors::DAY_CLOUD);

DayCloudTwo cloud1_scene6{ 1080, 950, 130, Colors::NIGHT_CLOUD };
DayCloudTwo cloud2_scene6{ 400, 900, 130, Colors::NIGHT_CLOUD };
DayCloudOne cloud3_scene6{ 1600, 850, 130, Colors::NIGHT_CLOUD };

DayCloudTwo cloud1_scene7{ 1080, 950, 130, Colors::NIGHT_CLOUD };
DayCloudTwo cloud2_scene7{ 400, 900, 130, Colors::NIGHT_CLOUD };
DayCloudOne cloud3_scene7{ 1600, 850, 130, Colors::NIGHT_CLOUD };

DayCloudTwo cloud1_scene8{ 1000, 940, 120, Colors::NIGHT_CLOUD };
DayCloudOne cloud2_scene8{ 440, 910, 120, Colors::NIGHT_CLOUD };
DayCloudOne cloud3_scene8{ 1700, 860, 120, Colors::NIGHT_CLOUD };
DayCloudTwo cloud4_scene8{ 0, 860, 120, Colors::NIGHT_CLOUD };


///// Tree /////

TreeTwo tree8_scene3;
TreeTwo tree9_scene3;
TreeOne tree10_scene3;
TreeTwo tree11_scene3;
TreeTwo tree12_scene3;
TreeTwo tree13_scene3;

///// Flags //////
bool isScene1End = false;
bool isScene2End = false;
bool isScene3End = false;
int currentScene = 1;
bool thunderTriggeredOnScene2 = false;
bool thunderTriggeredOnScene3 = false;
bool isScene2ArcAngleInitialized = false;
bool isScene3GirlPosInitialized = false;
bool isDiagonalMovement = false;
bool isEnterPortal = false;

///// Delay Variables /////

int delayCounterScene3 = 0;
const int delayDurationScene3 = 60;


/////   Declare states  /////

enum LittleGirlState {
    FRONT_VIEW,
    SIDE_VIEW,
    MOVING
};

LittleGirlState currentState = FRONT_VIEW;

///// Init function /////

static void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1920.0, 0.0, 1080.0);
}

/////   Declare scenes  /////

static void displayScene1() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene1();

    House house;
    house.draw(200.0f, 550.0f, 700.0f, true);

    //Upper Level
    GrassTwo grass1;
    grass1.draw(200, 203, 45, Colors::GRASS_NIGHT);
    GrassTwo grass2;
    grass2.draw(400, 203, 47, Colors::GRASS_NIGHT);
    GrassTwo grass3;
    grass3.draw(1200, 200, 46, Colors::GRASS_NIGHT);
    GrassOne grass4;
    grass4.draw(260, 203, 55, Colors::GRASS_NIGHT);
    GrassOne grass5;
    grass5.draw(760, 200, 60, Colors::GRASS_NIGHT);
    GrassOne grass6;
    grass6.draw(1700, 199, 57, Colors::GRASS_NIGHT);
    GrassTwo grass7;
    grass7.draw(1800, 200, 44, Colors::GRASS_NIGHT);
    GrassTwo grass8;
    grass8.draw(830, 198, 46, Colors::GRASS_NIGHT);
    GrassTwo grass9;
    grass9.draw(30, 203, 46, Colors::GRASS_NIGHT);
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

    for (auto cloud : clouds_scene1) {
        cloud->draw();
    }

    switch (currentState) {
        case FRONT_VIEW:
            girl.drawFrontView();
            break;
        case SIDE_VIEW:
        case MOVING:
            girl.drawSideView();
            break;
    }

    glFlush();
    glutSwapBuffers();
}

static void displayScene2() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene2();
    FullMoon moon;
    moon.draw(1530, 950, 140, Colors::NIGHT_FULL_MOON);

    for (auto cloud : clouds_scene2) {
        cloud->draw();
    }

    TreeOne tree1;
    tree1.draw(1900, 380, 300, Colors::TREE_NIGHT);
    TreeTwo tree2;
    tree2.draw(1582, 385, 280, Colors::TREE_NIGHT);
    GrassOne grass21;
    grass21.draw(1613, 386, 40, Colors::GRASS_NIGHT);
    TreeTwo tree3;
    tree3.draw(1300, 320, 250, Colors::TREE_NIGHT);
    GrassTwo grass20;
    grass20.draw(1317, 322, 30, Colors::GRASS_NIGHT);


    //Upper Level
    GrassTwo grass1;
    grass1.drawWithRotation(1550, 388, 57, 9, Colors::GRASS_NIGHT);
    GrassTwo grass2;
    grass2.drawWithRotation(800, 160, 55, 25, Colors::GRASS_NIGHT);
    GrassTwo grass3;
    grass3.drawWithRotation(600, 45, 55,33, Colors::GRASS_NIGHT);
    GrassTwo grass4;
    grass4.drawWithRotation(400, 157, 20, 340, Colors::GRASS_NIGHT);
    GrassTwo grass5;
    grass5.drawWithRotation(30, 258, 20, 345, Colors::GRASS_NIGHT);
    GrassOne grass9;
    grass9.drawWithRotation(1750, 400, 65, 1, Colors::GRASS_NIGHT);
    GrassOne grass10;
    grass10.drawWithRotation(900, 208, 60, 22, Colors::GRASS_NIGHT);
    GrassOne grass11;
    grass11.drawWithRotation(550, 98, 30, 335, Colors::GRASS_NIGHT);    

    //Lower Level
    GrassOne grass12;
    grass12.drawWithRotation(90, 40, 30, 330, Colors::GRASS_NIGHT);  
    GrassTwo grass7;
    grass7.drawWithRotation(440, 85, 20, 335, Colors::GRASS_NIGHT);
    GrassOne grass13;
    grass13.drawWithRotation(950, 85, 46, 30, Colors::GRASS_NIGHT);
    GrassTwo grass14;
    grass14.drawWithRotation(1400, 250, 43, 13, Colors::GRASS_NIGHT);
    GrassTwo grass8;
    grass8.drawWithRotation(1800, 200, 50, 10, Colors::GRASS_NIGHT);

    House house;
    house.draw(20.0f, 350.0f, 250, false);
    GrassTwo grass15;
    grass15.drawWithRotation(65, 227, 20, 0, Colors::GRASS_NIGHT);
    GrassOne grass16;
    grass16.drawWithRotation(10, 227, 20, 0, Colors::GRASS_NIGHT);
    GrassOne grass17;
    grass17.drawWithRotation(145, 225, 20, 0, Colors::GRASS_NIGHT);

    //Second Layer
    TreeTwo tree5;
    tree5.draw(1750, 210, 280, Colors::TREE_NIGHT);
    TreeTwo tree6;
    tree6.draw(1450, 250, 260, Colors::TREE_NIGHT);

    girl.drawSideView();

    //Third Layer
    TreeTwo tree7;
    tree7.draw(1120, 170, 230, Colors::TREE_NIGHT);
    TreeTwo tree8;
    tree8.draw(1550, 150, 220, Colors::TREE_NIGHT);
    GrassOne grass22;
    grass22.draw(1568, 153, 50, Colors::GRASS_NIGHT);
    TreeTwo tree9;
    tree9.draw(1850, 80, 210, Colors::TREE_NIGHT);
    GrassTwo grass23;
    grass23.draw(1840, 82, 30, Colors::GRASS_NIGHT);

    //Fourth Layer
    TreeTwo tree10;
    tree10.draw(1470, -60, 225, Colors::TREE_NIGHT);
    TreeOne tree4;
    tree4.draw(1200, -150, 250, Colors::TREE_NIGHT);
    TreeOne tree11;
    tree11.draw(1720, -210, 255, Colors::TREE_NIGHT);

    rain.renderRain();

    glFlush();
    glutSwapBuffers(); 
}

static void displayScene3() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene3();
  
    FullMoon moon;
    moon.draw(1535, 950, 140, Colors::NIGHT_FULL_MOON);

    for (auto cloud : clouds_scene3) {
        cloud->draw();
    }

    //First Layer
    TreeTwo tree3;
    tree3.draw(1850, 280, 420, Colors::TREE_NIGHT);
    TreeOne tree4;
    tree4.draw(1400, 260, 390, Colors::TREE_NIGHT);
    TreeTwo tree1;
    tree1.draw(400, 250, 400, Colors::TREE_NIGHT);
    TreeTwo tree2;
    tree2.draw(-15, 250, 360, Colors::TREE_NIGHT);
    TreeOne tree5;
    tree5.draw(620, 250, 350, Colors::TREE_NIGHT);

    Background::Cave();

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

    //Second Layer
    TreeTwo tree6;
    tree6.draw(1040, 225, 330, Colors::TREE_NIGHT);
    GrassOne grass21;
    grass21.draw(1060, 224, 55, Colors::GRASS_NIGHT);
    TreeTwo tree7;
    tree7.draw(220, 215, 320, Colors::TREE_NIGHT);
    GrassTwo grass22;
    grass22.draw(209, 217, 38, Colors::GRASS_NIGHT);

    portal.draw(1500.0f, 410.0f, 90.0f, 140.0f);

    switch (currentState) {
        case FRONT_VIEW:
            girl.drawFrontView();
            break;
        case SIDE_VIEW:
        case MOVING:
            girl.drawSideView();
            break;
    }

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
    GrassOne grass20;
    grass20.draw(1676, 205, 55, Colors::GRASS_NIGHT);

    //Third Layer
    tree8_scene3.draw(900, 150, 350, Colors::TREE_NIGHT);
    GrassOne grass23;
    grass23.draw(875, 152, 45, Colors::GRASS_NIGHT);
    tree9_scene3.draw(500, 90, 360, Colors::TREE_NIGHT);
    GrassTwo grass24;
    grass24.draw(515, 91, 30, Colors::GRASS_NIGHT);

    //Fourth Layer
    tree10_scene3.draw(100, -200, 360, Colors::TREE_NIGHT);
    tree11_scene3.draw(630, -240, 370, Colors::TREE_NIGHT);
    tree12_scene3.draw(980, -320, 360, Colors::TREE_NIGHT);
    tree13_scene3.draw(420, -470, 360, Colors::TREE_NIGHT);
    TreeTwo tree14;
    tree14.draw(1900, -400, 360, Colors::TREE_NIGHT);

    rain.renderRain();

    glFlush();
    glutSwapBuffers(); 
}

static void displayScene4() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene4();
    RainbowOne rainbow;   
    
    DaySunOne sun;
    sun.draw(160, 930, 110, Colors::DAY_SUN);

    rainbow.draw(1400, 745, 200, Colors::RAINBOW);
    cloud1_scene4.draw();
    cloud2_scene4.draw();
    cloud3_scene4.draw();
    cloud4_scene4.draw();


    portal.draw(200, 500, 150.0f, 75.0f);

    IslandOne island1;
    island1.draw(700, 700, 250, Colors::ISLAND_DAY);
    IslandTwo island2;
    island2.draw(1800, 600, 200, Colors::ISLAND_DAY);

    cloud5_scene4.draw();
    cloud6_scene4.draw();

    mushroomThree mushroom2;
    mushroom2.draw(1800, 250, 300, Colors::MUSHROOM_DAY, true);

    mushroomOne mushroom3;
    mushroom3.draw(1700, 250, 100, Colors::MUSHROOM_DAY, true);

    mushroomOne mushroom5;
    mushroom5.draw(1000, 250, 300, Colors::MUSHROOM_DAY, true);
    mushroomOne mushroom6;
    mushroom6.draw(1100, 250, 140, Colors::MUSHROOM_DAY, true);


    mushroomOne mushroom4;
    mushroom4.draw(720, 768, 30, Colors::MUSHROOM_DAY, false);
    mushroomTwo mushroom7;
    mushroom7.draw(680, 768, 10, Colors::MUSHROOM_DAY, false);
    mushroomThree mushroom8;
    mushroom8.draw(1790, 640, 30, Colors::MUSHROOM_DAY, false);

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

    FullMoon moon1;
    moon1.draw(130, 950, 140, Colors::NIGHT_FULL_MOON);
    FullMoon moon2;
    moon2.draw(225, 915, 30, Colors::NIGHT_FULL_MOON);

    cloud1_scene6.draw();
    cloud2_scene6.draw();
    cloud3_scene6.draw();

    mushroomThree mushroom5;
    mushroom5.draw(250, 250, 500, Colors::MUSHROOM_NIGHT, true);
    mushroomThree mushroom6;
    mushroom6.draw(820, 250, 600, Colors::MUSHROOM_NIGHT, true);
    mushroomThree mushroom7;
    mushroom7.draw(1500, 250, 500, Colors::MUSHROOM_NIGHT, true);

    mushroomThree mushroom1;
    mushroom1.draw(-150, 250, 800, Colors::MUSHROOM_NIGHT, true);
    mushroomThree mushroom2;
    mushroom2.draw(500, 250, 700, Colors::MUSHROOM_NIGHT, true);   
    mushroomThree mushroom4;
    mushroom4.draw(1800, 250, 750, Colors::MUSHROOM_NIGHT, true);
    mushroomThree mushroom3;
    mushroom3.draw(1200, 250, 820, Colors::MUSHROOM_NIGHT, true);


  
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

    FullMoon moon1;
    moon1.draw(135, 950, 140, Colors::NIGHT_FULL_MOON);
    FullMoon moon2;
    moon2.draw(230, 915, 30, Colors::NIGHT_FULL_MOON);

    cloud1_scene7.draw();
    cloud2_scene7.draw();
    cloud3_scene7.draw();

    mushroomThree mushroom5;
    mushroom5.draw(250, 250, 500, Colors::MUSHROOM_NIGHT, true);
    mushroomThree mushroom6;
    mushroom6.draw(820, 250, 600, Colors::MUSHROOM_NIGHT, true);
    mushroomThree mushroom7;
    mushroom7.draw(1500, 250, 500, Colors::MUSHROOM_NIGHT, true);

    mushroomThree mushroom1;
    mushroom1.draw(-150, 250, 800, Colors::MUSHROOM_NIGHT, true);
    mushroomThree mushroom2;
    mushroom2.draw(500, 250, 700, Colors::MUSHROOM_NIGHT, true);
    mushroomThree mushroom4;
    mushroom4.draw(1800, 250, 750, Colors::MUSHROOM_NIGHT, true);
    mushroomThree mushroom3;
    mushroom3.draw(1200, 250, 820, Colors::MUSHROOM_NIGHT, true);

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

    girl.setPosX(850);
    girl.setPosY(250);
    girl.setCharacterSize(210);
    girl.drawFrontView();
    totoro.draw(1080.0f, 450.0f, 300.0f);
    //totoroSide.draw(700.0f, 300.0f, 300.0f);

    glFlush();
    glutSwapBuffers(); 

}

static void displayScene8() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene8();

    FullMoon moon1;
    moon1.draw(134, 950, 140, Colors::NIGHT_FULL_MOON);
    FullMoon moon2;
    moon2.draw(234, 915, 30, Colors::NIGHT_FULL_MOON);

    cloud1_scene8.draw();
    cloud2_scene8.draw();
    cloud3_scene8.draw();
    cloud4_scene8.draw();

    IslandOne island1;
    island1.draw(1400, 900, 100, Colors::ISLAND_NIGHT);
    mushroomThree mushroom1;
    mushroom1.draw(1390, 928, 20, Colors::MUSHROOM_NIGHT, false);
    mushroomTwo mushroom2;
    mushroom2.draw(1410, 928, 10, Colors::MUSHROOM_NIGHT, false);



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
    if (currentScene == 1) {
        displayScene1();
    }
    else if (currentScene == 2) {
        displayScene2();
    } 
    else if (currentScene == 3) {
        displayScene3();
    }
    else if (currentScene == 4) {
        displayScene4();
    }
}

//// Timer function to update the frame
//void totoroTimer(int value) {
//    totoroSide.updateFrame();
//    glutPostRedisplay();
//    glutTimerFunc(100, totoroTimer, 0); // Call timer function every 100 milliseconds
//}

/////   Declare update functions  /////

static void changeGirlStateAfterDelay(int value) {
    switch (currentState) {
        case FRONT_VIEW:
            currentState = SIDE_VIEW;
            break;
        case SIDE_VIEW:
            currentState = MOVING;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

static void triggerThunder(int value) {
    if (currentScene == 1) {
        thunderScene1.startThunder();
    }
    else if (currentScene == 2 && !thunderTriggeredOnScene2) {
        thunderScene2.startThunder();
        thunderTriggeredOnScene2 = true;
    }
    else if (currentScene == 3 && !thunderTriggeredOnScene3) {
        thunderScene3.startThunder();
        thunderTriggeredOnScene3 = true;
    }
    glutPostRedisplay();
}

static void updateGirlPosition(int value) {
    if (currentScene == 1) {
        if (currentState == MOVING) {
            girl.move(3.0f);
        }

        if (girl.getPosX() > 1920) {
            isScene1End = true;
            currentScene = 2;
            triggerThunder(0);
        }
    }
    else if (currentScene == 2) {
        currentState = MOVING;

        if (!isScene2ArcAngleInitialized) {
            girl.setCurrentAngle(2.2f);
            isScene2ArcAngleInitialized = true;
        }

        girl.moveInArc(0.05f, 0.05f);

        if (girl.getPosX() > 1920) {
            isScene2End = true;
            currentScene = 3;
            triggerThunder(0);
        }
    }
    else if (currentScene == 3) {
        if (!isScene3GirlPosInitialized) {
            currentState = MOVING;
            girl.setPosX(0);
            girl.setPosY(155);
            isScene3GirlPosInitialized = true;
        }
        if (currentState == MOVING) {
            if (!isDiagonalMovement) {
                girl.move(3.0f);
            }
            else {
                girl.moveDiagonally(1.8f, 1.8f);
            }
        }

        if (isEnterPortal) {
            isScene3End = true;
            currentScene = 4;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateGirlPosition, 0);
}

static void updateGirlFrame(int value) {
    if (currentState == MOVING) {
        girl.updateFrame();
    }
    glutPostRedisplay();
    glutTimerFunc(250, updateGirlFrame, 0);
}

static void updateGirlViewScene3(int value) {
    if (currentScene == 3) {
        if (girl.getPosX() >= 1400) {
            currentState = FRONT_VIEW;
            delayCounterScene3++;
            if (delayCounterScene3 >= delayDurationScene3) {
                currentState = SIDE_VIEW;
                currentState = MOVING;
                isDiagonalMovement = true;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateGirlViewScene3, 0);
}

static void updateGirlFadeInIntoPortal(int value) {
    if (currentScene == 3) {
        if (girl.getPosX() >= 1480) {
            girl.setOpacity(girl.getOpacity() - 0.1f);
        }

        if (girl.getOpacity() <= 0) {
            isEnterPortal = true;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateGirlFadeInIntoPortal, 0);
}

static void updateCloudPosition(int value) {
    if (currentScene == 1) {
        clouds_scene1.at(0)->move(0.1f, false);
        clouds_scene1.at(1)->move(0.1f, true);
        clouds_scene1.at(2)->move(0.1f, true);
    }
    else if (currentScene == 2) {
        clouds_scene2.at(0)->move(0.1f, true);
        clouds_scene2.at(1)->move(0.1f, true);
        clouds_scene2.at(2)->move(0.1f, false);
        clouds_scene2.at(3)->move(0.1f, true);
    }
    else {
        clouds_scene3.at(0)->move(0.1f, true);
        clouds_scene3.at(1)->move(0.1f, true);
        clouds_scene3.at(2)->move(0.1f, false);
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateCloudPosition, 0);
}

static void updateThunderEffect(int value) {
    if (currentScene == 1) {
        thunderScene1.update();
    }
    else if (currentScene == 2) {
        thunderScene2.update();
    }
    else if (currentScene == 3) {
        thunderScene3.update();
    }
    glutPostRedisplay();
    glutTimerFunc(100, updateThunderEffect, 0);
}

static void updateRain(int value) {
    if (currentScene == 2 || currentScene == 3) {
        rain.updateRain();
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateRain, 0);
}

static void updateTreeOpacity(int value) {
    if (currentScene == 3) {

        if (girl.getPosX() >= 0) {
            tree10_scene3.setOpacity(0.3f);
        }
        if (girl.getPosX() >= 400) {
            tree10_scene3.setOpacity(1.0f);
        }

        if (girl.getPosX() >= 350) {
            tree13_scene3.setOpacity(0.3f);
        }
        if (girl.getPosX() >= 500) {
            tree13_scene3.setOpacity(1.0f);
        }

        if (girl.getPosX() >= 350) {
            tree9_scene3.setOpacity(0.3f);
        }
        if (girl.getPosX() >= 700) {
            tree9_scene3.setOpacity(1.0f);
        }

        if (girl.getPosX() >= 380) {
            tree11_scene3.setOpacity(0.3f);
        }
        if (girl.getPosX() >= 800) {
            tree11_scene3.setOpacity(1.0f);
        }

        if (girl.getPosX() >= 750) {
            tree8_scene3.setOpacity(0.3f);
        }
        if (girl.getPosX() >= 1100) {
            tree8_scene3.setOpacity(1.0f);
        }

        if (girl.getPosX() >= 800) {
            tree12_scene3.setOpacity(0.3f);
        }
        if (girl.getPosX() >= 1100) {
            tree12_scene3.setOpacity(1.0f);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateTreeOpacity, 0);
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

    glutDisplayFunc(displayScene8);

    portal.startTimer(); 
    glutTimerFunc(1000, changeGirlStateAfterDelay, 0);
    glutTimerFunc(1000, changeGirlStateAfterDelay, 1);
    glutTimerFunc(16, updateGirlPosition, 0);
    glutTimerFunc(250, updateGirlFrame, 0);
    glutTimerFunc(16, updateCloudPosition, 0);
    glutTimerFunc(3000, triggerThunder, 0);
    glutTimerFunc(100, updateThunderEffect, 0);
    glutTimerFunc(16, updateRain, 0);
    glutTimerFunc(16, updateTreeOpacity, 0);
    glutTimerFunc(16, updateGirlViewScene3, 0);
    glutTimerFunc(16, updateGirlFadeInIntoPortal, 0);

    glutFullScreen();
    glutMainLoop();

    return 0;
}