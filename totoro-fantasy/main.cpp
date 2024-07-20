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
#include "sound.h"
#include "FadeEffect.h"
#include "BusSignBoard.h"


/////   Declare global variables    /////
Sound sound;
//bool isRainSoundPlaying = false;
//bool isThunderSoundPlaying = false;
//bool isPortalSoundPlaying = false;
Portal portal;
Totoro totoroFront;
TotoroSide totoroSide;
LittleGirl girl(500, 150, 180, 0, false);
Catbus catbus{ 0, 0, 600, false };
Rain rain{ 500 };
FadeEffect fadeOutScene6;

//for totoro side view walking
int state = 0; // 0 for side view walking, 1 for front view
float positionX = 1980.0f; // Starting position for the side view
const float startX = 1.0f;
const float endX = 1020.0f; // Ending position for the side view
int steps = 0;

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

std::vector<Cloud*> clouds_scene4{
    new DayCloudThree(1300, 740, 105, Colors::DAY_CLOUD), // static
    new DayCloudThree(1500, 740, 105, Colors::DAY_CLOUD), // static
    new DayCloudTwo(140, 850, 130, Colors::DAY_CLOUD),
    new DayCloudTwo(1940, 800, 130, Colors::DAY_CLOUD),
    new DayCloudTwo(760, 700, 40, Colors::DAY_CLOUD),
    new DayCloudTwo(1760, 600, 30, Colors::DAY_CLOUD)
};

std::vector<Cloud*> clouds_scene6{
    new DayCloudTwo(1080, 950, 130, Colors::NIGHT_CLOUD),
    new DayCloudTwo(400, 900, 130, Colors::NIGHT_CLOUD),
    new DayCloudOne(1600, 850, 130, Colors::NIGHT_CLOUD)
};


DayCloudTwo cloud1_scene8{ 1000, 940, 120, Colors::NIGHT_CLOUD };
DayCloudOne cloud2_scene8{ 440, 910, 120, Colors::NIGHT_CLOUD };
DayCloudOne cloud3_scene8{ 1700, 860, 120, Colors::NIGHT_CLOUD };
DayCloudTwo cloud4_scene8{ 0, 860, 120, Colors::NIGHT_CLOUD };

DayCloudTwo cloud1_scene9{ 1000, 440, 120, Colors::NIGHT_CLOUD };
DayCloudOne cloud2_scene9{ 440, 410, 120, Colors::NIGHT_CLOUD };
DayCloudOne cloud3_scene9{ 1700, 360, 120, Colors::NIGHT_CLOUD };
DayCloudTwo cloud4_scene9{ 0, 360, 120, Colors::NIGHT_CLOUD };
DayCloudTwo cloud5_scene9{ 1930, 460, 120, Colors::NIGHT_CLOUD };

DayCloudTwo cloud1_scene9Half{ 1080, 950, 130, Colors::NIGHT_CLOUD };
DayCloudTwo cloud2_scene9Half{ 400, 900, 130, Colors::NIGHT_CLOUD };
DayCloudOne cloud3_scene9Half{ 1600, 850, 130, Colors::NIGHT_CLOUD };

DayCloudTwo cloud1_scene10{ 1080, 950, 110, Colors::DAY_CLOUD };
DayCloudTwo cloud2_scene10{ 400, 900, 110, Colors::DAY_CLOUD };
DayCloudOne cloud3_scene10{ 1600, 850, 110, Colors::DAY_CLOUD };
DayCloudTwo cloud4_scene10{ 1930, 885, 110, Colors::DAY_CLOUD };

DayCloudTwo cloud1_scene11{ 1080, 900, 140, Colors::DAY_CLOUD };
DayCloudTwo cloud2_scene11{ 400, 850, 140, Colors::DAY_CLOUD };
DayCloudOne cloud3_scene11{ 1600, 800, 140, Colors::DAY_CLOUD };
DayCloudTwo cloud4_scene11{ 1930, 900, 140, Colors::DAY_CLOUD };

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
bool isScene4End = false;
bool isScene6End = false;
bool isScene8End = false;
bool isScene9End = false;
bool isScene10End = false;  

int currentScene = 1;

bool thunderTriggeredOnScene2 = false;
bool thunderTriggeredOnScene3 = false;

bool isScene2ArcAngleInitialized = false;
bool isScene3GirlPosInitialized = false;
bool isScene4Initialized = false;
bool isScene4AfterBounceInitialized = false;
bool isScene6Initialized = false;
bool isScene8Initialized = false;
bool isScene9Initialized = false;
bool isScene10Initialized = false;

bool isDiagonalMovement = false;
bool isVerticalMovement = false;
bool isEnterPortal = false;
bool isCatbusEnterPortal = false;
bool isCatbusExitPortal = false;
bool isPortalActivatedScene9 = false;
bool isPortalDeactivatedScene9 = false;
bool isPortalActivatedScene10 = false;
bool isPortalDeactivatedScene10 = false;
bool isBouncing = true;
bool isCrying = false;
bool isTotoroAppeared = false;
bool isTotoroComforting = false;
bool isFinishCrying = false;
bool isFadeOutScene6 = false;
bool isDoneFadeOutScene6 = false;
bool isPickup = false;
bool isCatbusReachedGround = false;

///// Delay Variables /////

int delayCounterScene3 = 0;
const int delayDurationScene3 = 60;

int delayCounterScene4 = 0;
const int delayDurationScene4 = 60;

int delayCounterScene6 = 0;
const int delayDurationScene6 = 60;

int cryingDelayCounter = 0;
const int cryingDurationCounter = 125;

int finishCryingDelayCounter = 0;
const int finishCryingDurationCounter = 75;

int fadeOutScene6DelayCounter = 0;
const int fadeOutScene6DurationCounter = 60;

int pickupBeforeDelayCounter = 0;
const int pickupBeforeDurationCounter = 60;

int transitionScene9to10DelayCounter = 0;
const int transitionScene9to10DurationCounter = 20;

int portalActivationScene10DelayCounter = 0;
const int portalActivationScene10DurationCounter = 20;

int portalDeactivationScene10DelayCounter = 0;
const int portalDeactivationScene10DurationCounter = 60;

/////   Declare states  /////

enum LittleGirlState {
    LITTLE_GIRL_FRONT_VIEW,
    LITTLE_GIRL_SIDE_VIEW,
    LITTLE_GIRL_MOVING
};

enum TotoroState {
    TOTORO_INVISIBLE,
    TOTORO_FRONT_VIEW,
    TOTORO_SIDE_VIEW_WALKING
};

enum CatbusState {
    CATBUS_INVISIBLE,
    CATBUS_STANDSTILL,
    CATBUS_RUNNING
};

LittleGirlState currentGirlState = LITTLE_GIRL_FRONT_VIEW;
TotoroState currentTotoroState = TOTORO_INVISIBLE;
CatbusState currentCatbusState = CATBUS_RUNNING;

static void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1920.0, 0.0, 1080.0);
}

/////   Declare scenes  /////

static void displayScene1() {
    glClear(GL_COLOR_BUFFER_BIT);

    sound.playDoorSound();
        sound.playThunderSoundWithDelay(3);
    Background::Scene1();

    House house;
    house.draw(200.0f, 550.0f, 700.0f, true, false);

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
    moon.draw(1520, 950, 140, Colors::NIGHT_FULL_MOON, 1);

    for (auto cloud : clouds_scene1) {
        cloud->draw();
    }

    switch (currentGirlState) {
    case LITTLE_GIRL_FRONT_VIEW:
        girl.drawFrontView();
        break;
    case LITTLE_GIRL_SIDE_VIEW:
    case LITTLE_GIRL_MOVING:
        girl.drawSideView();
        break;
    }

    glFlush();
    glutSwapBuffers();
}

static void displayScene2() {
    glClear(GL_COLOR_BUFFER_BIT);

        sound.playRainSound();


    Background::Scene2();
    FullMoon moon;
    moon.draw(1530, 950, 140, Colors::NIGHT_FULL_MOON, 1);

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
    grass3.drawWithRotation(600, 45, 55, 33, Colors::GRASS_NIGHT);
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
    house.draw(20.0f, 350.0f, 250, false, false);
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
    sound.playRainSoundForDuration(7);
    sound.playPortalSoundWithDelay(7);
    Background::Scene3();

    FullMoon moon;
    moon.draw(1535, 950, 140, Colors::NIGHT_FULL_MOON, 1);

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

    switch (currentGirlState) {
    case LITTLE_GIRL_FRONT_VIEW:
        girl.drawFrontView();
        break;
    case LITTLE_GIRL_SIDE_VIEW:
    case LITTLE_GIRL_MOVING:
        girl.drawSideView();
        break;
    }

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
    sound.stopPortalSound();

    Background::Scene4();
    RainbowOne rainbow;

    DaySunOne sun;
    sun.draw(160, 930, 110, Colors::DAY_SUN);

    rainbow.draw(1400, 745, 200, Colors::RAINBOW);

    clouds_scene4[0]->draw();
    clouds_scene4[1]->draw();
    clouds_scene4[2]->draw();
    clouds_scene4[3]->draw();

    portal.draw(200, 500, 150.0f, 75.0f);

    IslandOne island1;
    island1.draw(700, 700, 250, Colors::ISLAND_DAY);
    IslandTwo island2;
    island2.draw(1800, 600, 200, Colors::ISLAND_DAY);

    clouds_scene4[4]->draw();
    clouds_scene4[5]->draw();

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

    switch (currentGirlState) {
        case LITTLE_GIRL_FRONT_VIEW:
            girl.drawFrontView();
            break;
        case LITTLE_GIRL_SIDE_VIEW:
        case LITTLE_GIRL_MOVING:
            girl.drawSideView();
            break;
    }

    Flower flower1;
    flower1.draw(80, 200, 40, 40, Colors::FLOWER_BLUE);
    Flower flower3;
    flower3.draw(1050, 190, 40, 50, Colors::FLOWER_ORANGE);
    Flower flower4;
    flower4.draw(790, 20, 40, 60, Colors::FLOWER_PURPLE);
    Flower flower5;
    flower5.draw(1800, 100, 40, 80, Colors::FLOWER_RED);
    Flower flower6;
    flower6.draw(400, 50, 40, 90, Colors::FLOWER_YELLOW);

    glFlush();
    glutSwapBuffers();
}

static void displayScene5() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene5();
    glFlush();
    glutSwapBuffers();
}

static void displayScene6_7() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene6_7();

    FullMoon moon1;
    moon1.draw(130, 950, 140, Colors::NIGHT_FULL_MOON, 1);
    FullMoon moon2;
    moon2.draw(225, 915, 30, Colors::NIGHT_FULL_MOON, 1);

    for (auto cloud : clouds_scene6) {
        cloud->draw();
    }

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

    Flower flower1;
    flower1.draw(1050, 100, 40, 60, Colors::FLOWER_BLUE);
    Flower flower2;
    flower2.draw(400, 190, 40, 100, Colors::FLOWER_CYAN);
    Flower flower3;
    flower3.draw(100, 90, 40, 130, Colors::FLOWER_RED);
    Flower flower4;
    flower4.draw(800, 120, 40, 20, Colors::FLOWER_PURPLE);
    Flower flower5;
    flower5.draw(1300, 190, 40, 60, Colors::FLOWER_RED);
    Flower flower6;
    flower6.draw(1800, 50, 40, 40, Colors::FLOWER_PURPLE);

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

    switch (currentGirlState) {
        case LITTLE_GIRL_FRONT_VIEW:
            girl.drawFrontView();
            break;
        case LITTLE_GIRL_SIDE_VIEW:
        case LITTLE_GIRL_MOVING:
            girl.drawSideView();
            break;
    }
    
    switch (currentTotoroState) {
        case TOTORO_INVISIBLE:
            break;
        case TOTORO_FRONT_VIEW:
            totoroFront.draw(1080.0f, 450.0f, 300.0f);
            break;
        case TOTORO_SIDE_VIEW_WALKING:
            totoroSide.draw(positionX, 420.0f, 270.0f);
            break;
    }

    if (isFadeOutScene6) {
        fadeOutScene6.drawFadeScreen();
    }

    glFlush();
    glutSwapBuffers();
}

static void displayScene7() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene6_7();

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
    mushroomThree mushroom3;
    mushroom3.draw(1200, 250, 820, Colors::MUSHROOM_NIGHT, true);
    mushroomThree mushroom4;
    mushroom4.draw(1800, 250, 750, Colors::MUSHROOM_NIGHT, true);




    if (state == 0) {
        // Side view walking
        totoroSide.draw(positionX, 420.0f, 270.0f); // Adjust the Y position and size as needed
    }
    else if (state == 1) {
        // Front view
        totoroFront.draw(1080.0f, 450.0f, 300.0f);

    }

    girl.setPosX(850);
    girl.setPosY(250);
    girl.setCharacterSize(210);
    girl.drawFrontView();

    glFlush();
    glutSwapBuffers();

}

static void displayScene8() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene8();

    FullMoon moon1;
    moon1.draw(134, 950, 140, Colors::NIGHT_FULL_MOON, 1);
    FullMoon moon2;
    moon2.draw(234, 915, 30, Colors::NIGHT_FULL_MOON, 1);

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

    BusSignBoard sign;
    sign.draw(1200, 530, 100, 3);
  
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

    Flower flower1;
    flower1.draw(1550, 370, 40, 60, Colors::FLOWER_ORANGE);
    Flower flower2;
    flower2.draw(1000, 200, 40, 100, Colors::FLOWER_YELLOW);
    Flower flower3;
    flower3.draw(1300, 90, 40, 130, Colors::FLOWER_BLUE);
    Flower flower4;
    flower4.draw(1850, 30, 40, 20, Colors::FLOWER_PURPLE);
    Flower flower5;
    flower5.draw(500, 60, 40, 40, Colors::FLOWER_RED);

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

    totoroFront.draw(1000.0f, 520.0f, 270.0f);
    girl.drawFrontView();

    switch (currentCatbusState) {
        case CATBUS_INVISIBLE:
            break;
        case CATBUS_RUNNING:
            catbus.drawRunningView();
            break;
        case CATBUS_STANDSTILL:
            catbus.drawStandstillView();
    }

    glFlush();
    glutSwapBuffers();
}

static void displayScene8Half() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene6_7();

    FullMoon moon1;
    moon1.draw(135, 950, 140, Colors::NIGHT_FULL_MOON, 1);
    FullMoon moon2;
    moon2.draw(230, 915, 30, Colors::NIGHT_FULL_MOON, 1);

    IslandTwo island1;
    island1.draw(1830, 700, 150, Colors::ISLAND_NIGHT);
    mushroomOne mushroom11;
    mushroom11.draw(1818, 730, 20, Colors::MUSHROOM_NIGHT, false);
    mushroomThree mushroom12;
    mushroom12.draw(1840, 730, 13, Colors::MUSHROOM_NIGHT, false);

    cloud1_scene9Half.draw();
    cloud2_scene9Half.draw();
    cloud3_scene9Half.draw();

    mushroomThree mushroom5;
    mushroom5.draw(360, 250, 500, Colors::MUSHROOM_NIGHT, true);
    mushroomThree mushroom6;
    mushroom6.draw(820, 250, 600, Colors::MUSHROOM_NIGHT, true);
    mushroomThree mushroom7;
    mushroom7.draw(1500, 250, 500, Colors::MUSHROOM_NIGHT, true);
    mushroomThree mushroom2;
    mushroom2.draw(500, 250, 400, Colors::MUSHROOM_NIGHT, true);
    mushroomThree mushroom3;
    mushroom3.draw(1210, 250, 350, Colors::MUSHROOM_NIGHT, true);
    mushroomThree mushroom10;
    mushroom10.draw(1650, 250, 150, Colors::MUSHROOM_NIGHT, true);
    mushroomThree mushroom8;
    mushroom8.draw(155, 250, 120, Colors::MUSHROOM_NIGHT, true);


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

    Flower flower1;
    flower1.draw(1050, 100, 40, 60, Colors::FLOWER_BLUE);
    Flower flower2;
    flower2.draw(400, 190, 40, 100, Colors::FLOWER_CYAN);
    Flower flower3;
    flower3.draw(100, 90, 40, 130, Colors::FLOWER_RED);
    Flower flower4;
    flower4.draw(800, 50, 40, 20, Colors::FLOWER_PURPLE);
    Flower flower5;
    flower5.draw(1300, 190, 40, 60, Colors::FLOWER_RED);
    Flower flower6;
    flower6.draw(1800, 120, 40, 40, Colors::FLOWER_PURPLE);

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

static void displayScene9() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene9();

    FullMoon moon1;
    moon1.draw(137, 900, 140, Colors::NIGHT_FULL_MOON, 0.35);
    FullMoon moon2;
    moon2.draw(237, 855, 30, Colors::NIGHT_FULL_MOON, 0.35);

    portal.draw(200.0f, 600.0f, 90.0f, 140.0f);

    mushroomThree mushroom4;
    mushroom4.draw(800, -250, 400, Colors::MUSHROOM_NIGHT, true);
    mushroomOne mushroom5;
    mushroom5.draw(350, -165, 200, Colors::MUSHROOM_NIGHT, true);

    IslandTwo island1;
    island1.draw(1300, 380, 100, Colors::ISLAND_NIGHT);
    mushroomOne mushroom6;
    mushroom6.draw(1310, 400, 20, Colors::MUSHROOM_NIGHT, false);
    mushroomTwo mushroom7;
    mushroom7.draw(1290, 400, 10, Colors::MUSHROOM_NIGHT, false);

    catbus.drawRunningView();

    cloud1_scene9.draw();
    cloud2_scene9.draw();
    cloud3_scene9.draw();
    cloud4_scene9.draw();
    cloud5_scene9.draw();

    glFlush();
    glutSwapBuffers();

}

static void displayScene10() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene10();

    DaySunOne sun;
    sun.draw(150, 940, 110, Colors::DAY_SUN);

    cloud1_scene10.draw();
    cloud2_scene10.draw();
    cloud3_scene10.draw();
    cloud4_scene10.draw();

    portal.draw(1920.0f, 630.0f, 90.0f, 140.0f);

    House house;
    house.draw(20.0f, 595.0f, 200, false, true);

    TreeTwo tree1;
    tree1.draw(1930, 180, 140, Colors::TREE_DAY);
    TreeOne tree2;
    tree2.draw(1750, 155, 130, Colors::TREE_DAY);    
    TreeTwo tree3;
    tree3.draw(1550, 150, 135, Colors::TREE_DAY);

    TreeTwo tree4;
    tree4.draw(1830, 90, 150, Colors::TREE_DAY);
    TreeTwo tree5;
    tree5.draw(1650, 60, 160, Colors::TREE_DAY);

    TreeTwo tree6;
    tree6.draw(1950, -100, 150, Colors::TREE_DAY);
    TreeOne tree7;
    tree7.draw(1750, -80, 160, Colors::TREE_DAY);
    TreeTwo tree8;
    tree8.draw(1580, -100, 140, Colors::TREE_DAY);

    //Upper level
    GrassTwo grass1;
    grass1.drawWithRotation(30, 496, 20, 358, Colors::GRASS_DAY);
    GrassTwo grass2;
    grass2.drawWithRotation(123, 495, 17, 355, Colors::GRASS_DAY);
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

    catbus.drawRunningView();

    glFlush();
    glutSwapBuffers();

}

static void displayScene11() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene11();

    DaySunOne sun;
    sun.draw(155, 940, 110, Colors::DAY_SUN);

    cloud1_scene11.draw();
    cloud2_scene11.draw();
    cloud3_scene11.draw();
    cloud4_scene11.draw();

    House house;
    house.draw(200.0f, 600.0f, 700.0f, true, true);

    //Upper Level
    GrassTwo grass1;
    grass1.draw(200, 250, 45, Colors::GRASS_DAY);
    GrassTwo grass2;
    grass2.draw(400, 253, 47, Colors::GRASS_DAY);
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

    GrassTwo grass17;
    grass17.draw(890, 65, 43, Colors::GRASS_DAY);
    GrassTwo grass18;
    grass18.draw(1100, 150, 44, Colors::GRASS_DAY);
    GrassTwo grass19;
    grass19.draw(1830, 90, 46, Colors::GRASS_DAY);
    GrassTwo grass20;
    grass20.draw(1450, 180, 47, Colors::GRASS_DAY);

    glFlush();
    glutSwapBuffers();
}

static void displayScene12() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene12();

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
    else if (currentScene == 5) {
        displayScene5();
    }
    else if (currentScene == 6 || currentScene == 7) {
        displayScene6_7();
    }
    else if (currentScene == 8) {
        displayScene8();
    }
    else if (currentScene == 9) {
        displayScene9();
    }
    else if (currentScene == 10) {
        displayScene10();
    }
    else if (currentScene == 11) {
        displayScene11();
    }
}

/////   Declare update functions  /////

static void changeGirlStateAfterDelay(int value) {
    switch (currentGirlState) {
        case LITTLE_GIRL_FRONT_VIEW:
            currentGirlState = LITTLE_GIRL_SIDE_VIEW;
            break;
        case LITTLE_GIRL_SIDE_VIEW:
            currentGirlState = LITTLE_GIRL_MOVING;
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
        if (currentGirlState == LITTLE_GIRL_MOVING) {
            girl.move(3.5f);
        }

        if (girl.getPosX() > 1920) {
            isScene1End = true;
            currentScene = 2;
            triggerThunder(0);
        }
    }
    else if (currentScene == 2) {
        currentGirlState = LITTLE_GIRL_MOVING;

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
            currentGirlState = LITTLE_GIRL_MOVING;
            girl.setPosX(0);
            girl.setPosY(155);
            isScene3GirlPosInitialized = true;
        }
        if (currentGirlState == LITTLE_GIRL_MOVING) {
            if (!isDiagonalMovement) {
                girl.move(3.5f);
            }
            else {
                girl.moveDiagonally(1.8f, 1.8f);
            }
        }

        if (isEnterPortal) {
            isScene3End = true;
            currentScene = 4;
            isDiagonalMovement = false;
        }
    }
    else if (currentScene == 4) {
        if (!isScene4Initialized) {
            currentGirlState = LITTLE_GIRL_FRONT_VIEW;
            girl.setPosX(190);
            girl.setPosY(400);
            girl.setCharacterSize(210);
            girl.setOpacity(0.0f);
            isScene4Initialized = true;
        }

        if (!isBouncing) {
            if (!isScene4AfterBounceInitialized) {
                currentGirlState = LITTLE_GIRL_SIDE_VIEW;
                currentGirlState = LITTLE_GIRL_MOVING;
            }
            girl.move(3.5f);

            if (girl.getPosX() > 1920) {
                isScene4End = true;
                currentScene = 6;
            }
        }
    }
    else if (currentScene == 6) {
        if (!isScene6Initialized) {
            currentGirlState = LITTLE_GIRL_MOVING;
            girl.setPosX(0);
            girl.setPosY(200);
            isScene6Initialized = true;
        }

        if (currentGirlState == LITTLE_GIRL_MOVING) {
            if (!isVerticalMovement) {
                girl.move(3.0f);
            }
            else {
                girl.moveVertically(1.8f);
            }
        }
        if (isDoneFadeOutScene6) {
            isScene6End = true;
            currentScene = 8;
        }
    }
    else if (currentScene == 8) {
        if (!isScene8Initialized) {
            girl.setPosX(1200);
            girl.setPosY(350);
            girl.setCharacterSize(210);

            currentCatbusState = CATBUS_RUNNING;
            catbus.setBusSize(600);
            catbus.setCurrentAngle(Constants::PI / 3);
            isScene8Initialized = true;
        }

        if (currentCatbusState == CATBUS_RUNNING) {
            catbus.moveInArc(0.1f, 0.05f);

            if (catbus.getPosX() < 10) {
                isScene8End = true;
                currentScene = 9;
            }
        }
    }
    else if (currentScene == 9) {
        if (!isScene9Initialized) {
            catbus.setPosX(1920);
            catbus.setPosY(550);
            catbus.setBusSize(450);
            catbus.setOpacity(1.0f);
            portal.setOpacity(0.0f);
            isScene9Initialized = true;
        }

        if (currentCatbusState == CATBUS_RUNNING) {
            catbus.move(5.0f);
        }

        if (isPortalDeactivatedScene9) {
            isScene9End = true;
            currentScene = 10;
        }
    }
    else if (currentScene == 10) {
        if (!isScene10Initialized) {
            portal.setOpacity(0.0f);
            catbus.setPosX(2200);
            catbus.setPosY(650);
            catbus.setOpacity(0.0f);
            isScene10Initialized = true;
        }

        if (catbus.getPosX() <= 800) {
            isCatbusReachedGround = true;
        }

        if (currentCatbusState == CATBUS_RUNNING) {
            if (!isCatbusReachedGround) {
                catbus.moveDiagonal(-6.0f, -2.0f);
                if (catbus.getBusSize() > 300.0f) {
                    catbus.setBusSize(catbus.getBusSize() - 1.5f);
                }
            }
            else {
                catbus.moveDiagonal(-6.0f, 3.8f);
            }
        }

        if (catbus.getPosX() <= 600) {
            isScene10End = true;
            currentScene = 11;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateGirlPosition, 0);
}

static void updateGirlFrame(int value) {
    if (currentGirlState == LITTLE_GIRL_MOVING) {
        girl.updateFrame();
    }
    glutPostRedisplay();
    glutTimerFunc(250, updateGirlFrame, 0);
}

static void updateGirlViewScene3(int value) {
    if (currentScene == 3) {
        if (girl.getPosX() >= 1400) {
            currentGirlState = LITTLE_GIRL_FRONT_VIEW;
            delayCounterScene3++;
            if (delayCounterScene3 >= delayDurationScene3) {
                currentGirlState = LITTLE_GIRL_SIDE_VIEW;
                currentGirlState = LITTLE_GIRL_MOVING;
                isDiagonalMovement = true;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateGirlViewScene3, 0);
}

static void updateGirlViewScene6(int value) {
    if (currentScene == 6) {
        if (girl.getPosX() >= 850 && !isVerticalMovement) {
            currentGirlState = LITTLE_GIRL_FRONT_VIEW;
            delayCounterScene6++;
            if (delayCounterScene6 >= delayDurationScene6) {
                currentGirlState = LITTLE_GIRL_SIDE_VIEW;
                currentGirlState = LITTLE_GIRL_MOVING;
                isVerticalMovement = true;
            }
        }

        if (girl.getPosY() >= 250 && isVerticalMovement && !isTotoroAppeared) {
            currentGirlState = LITTLE_GIRL_FRONT_VIEW;
            isCrying = true;
            girl.setCrying(true);
            cryingDelayCounter++;
            if (cryingDelayCounter >= cryingDurationCounter) {
                currentTotoroState = TOTORO_SIDE_VIEW_WALKING;
                isTotoroAppeared = true;
            }
        }

        if (isTotoroComforting && !isFinishCrying) {
            finishCryingDelayCounter++;
            if (finishCryingDelayCounter >= finishCryingDurationCounter) {
                girl.setCrying(false);
                isFinishCrying = true;
            }
        }

        if (isFinishCrying && !isFadeOutScene6) {
            fadeOutScene6DelayCounter++;
            if (fadeOutScene6DelayCounter >= fadeOutScene6DurationCounter) {
                isFadeOutScene6 = true;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateGirlViewScene6, 0);
}

static void updateGirlFadeInIntoPortal(int value) {
    if (currentScene == 3) {
        if (girl.getPosX() >= 1480) {
            girl.setOpacity(girl.getOpacity() - 0.1f);
        }

        if (girl.getOpacity() <= 0) {
            isEnterPortal = true;
            girl.setOpacity(0);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateGirlFadeInIntoPortal, 0);
}

static void updateGirlExitPortal(int value) {
    if (currentScene == 4) {
        if (girl.getOpacity() < 1) {
            girl.setOpacity(girl.getOpacity() + 0.1f);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateGirlExitPortal, 0);
}

static void updateExitPortalBounce(int value) {
    if (currentScene == 4 && isBouncing) {
        isBouncing = girl.bounceVertical(30.0f, 200.0f, 1.0f, 30);
    }
    glutPostRedisplay();
    glutTimerFunc(30, updateExitPortalBounce, 0);
}

static void updatedPortalActivationScene9(int value) {
    if (currentScene == 9 && !isPortalActivatedScene9 && isScene9Initialized) {
        if (catbus.getPosX() <= 1300) {
            portal.setOpacity(portal.getOpacity() + 0.03f);

            if (portal.getOpacity() >= 1.0f) {
                isPortalActivatedScene9 = true;
                portal.setOpacity(1.0f);
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updatedPortalActivationScene9, 0);
}

static void updatedPortalDeactivationScene9(int value) {
    if (currentScene == 9 && !isPortalDeactivatedScene9) {
        if (isCatbusEnterPortal) {
            portal.setOpacity(portal.getOpacity() - 0.03f);

            if (portal.getOpacity() <= 0) {
                portal.setOpacity(0);
                transitionScene9to10DelayCounter++;
                if (transitionScene9to10DelayCounter >= transitionScene9to10DurationCounter) {
                    isPortalDeactivatedScene9 = true;
                }
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updatedPortalDeactivationScene9, 0);
}

static void updatePortalActivationScene10(int value) {
    if (currentScene == 10 && !isPortalActivatedScene10 && isScene10Initialized) {
        portal.setOpacity(portal.getOpacity() + 0.03f);

        if (portal.getOpacity() >= 1.0f) {
            isPortalActivatedScene10 = true;
            portal.setOpacity(1.0f);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updatePortalActivationScene10, 0);
}

static void updatePortalDeactivationScene10(int value) {
    if (currentScene == 10 && !isPortalDeactivatedScene10) {
        if (isCatbusExitPortal) {
            portal.setOpacity(portal.getOpacity() - 0.03f);

            if (portal.getOpacity() <= 0) {
                portal.setOpacity(0);
                isPortalDeactivatedScene10 = true;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updatePortalDeactivationScene10, 0);
}

static void updateCatbusEnterPortal(int value) {
    if (currentScene == 9) {
        if (catbus.getPosX() <= 500) {
            catbus.setOpacity(catbus.getOpacity() - 0.03f);
        }

        if (catbus.getOpacity() <= 0) {
            isCatbusEnterPortal = true;
            catbus.setOpacity(0);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateCatbusEnterPortal, 0);
}

static void updateCatbusExitPortal(int value) {
    if (currentScene == 10) {
        if (isPortalActivatedScene10) {
            catbus.setOpacity(catbus.getOpacity() + 0.03f);
        }

        if (catbus.getOpacity() >= 1) {
            catbus.setOpacity(1.0f);
            portalDeactivationScene10DelayCounter++;
            if (portalDeactivationScene10DelayCounter >= portalDeactivationScene10DurationCounter) {
                isCatbusExitPortal = true;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateCatbusExitPortal, 0);
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
    else if (currentScene == 3) {
        clouds_scene3.at(0)->move(0.1f, true);
        clouds_scene3.at(1)->move(0.1f, true);
        clouds_scene3.at(2)->move(0.1f, false);
    }
    else if (currentScene == 4) {
        clouds_scene4.at(2)->move(0.1f, true);
        clouds_scene4.at(3)->move(0.1f, false);
        clouds_scene4.at(4)->move(0.1f, false);
        clouds_scene4.at(5)->move(0.1f, true);
    }
    else if (currentScene == 6) {
        clouds_scene6.at(0)->move(0.1f, true);
        clouds_scene6.at(1)->move(0.1f, true);
        clouds_scene6.at(2)->move(0.1f, false);
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

static void updateFadeOutEffectScene6(int value) {
    if (isFadeOutScene6 && !isDoneFadeOutScene6) {
        fadeOutScene6.updateFadeOutScreen();
        if (fadeOutScene6.getOpacity() >= 1) {
            isDoneFadeOutScene6 = true;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateFadeOutEffectScene6, 0);
}

static void totoroTimer(int value) {
    if (currentTotoroState == TOTORO_SIDE_VIEW_WALKING) {
        totoroSide.updateFrame();
        positionX -= 17.0f;
        if (positionX <= 1080.0f) {
            currentTotoroState = TOTORO_FRONT_VIEW;
            totoroFront.startBounce();
            isTotoroComforting = true;
        }
    }
    else if (currentTotoroState == TOTORO_FRONT_VIEW) {
        totoroFront.updateBounce();
        isTotoroComforting = true;
    }
    glutPostRedisplay();
    glutTimerFunc(100, totoroTimer, 0);
}

static void updateCatbusFrame(int value) {
    if (currentCatbusState == CATBUS_RUNNING) {
        catbus.updateFrame();
    }
    glutPostRedisplay();
    glutTimerFunc(30, updateCatbusFrame, 0);
}

static void updateCatbusPickup(int value) {
    if (currentScene == 8) {
        if (catbus.getPosX() <= 1100 && !isPickup) {
            currentCatbusState = CATBUS_STANDSTILL;
            pickupBeforeDelayCounter++;
            if (pickupBeforeDelayCounter >= pickupBeforeDurationCounter) {
                catbus.setIsBoarded(true);
                girl.setOpacity(0.0f);
                isPickup = true;
            }
        }

        if (isPickup) {
            currentCatbusState = CATBUS_RUNNING;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateCatbusPickup, 0);
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

    glutDisplayFunc(display);

    glutTimerFunc(100, totoroTimer, 0);
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
    glutTimerFunc(16, updateGirlExitPortal, 0);
    glutTimerFunc(30, updateExitPortalBounce, 0);
    glutTimerFunc(16, updateGirlViewScene6, 0);
    glutTimerFunc(16, updateFadeOutEffectScene6, 0);
    glutTimerFunc(30, updateCatbusFrame, 0);
    glutTimerFunc(16, updateCatbusPickup, 0);
    glutTimerFunc(16, updateCatbusEnterPortal, 0);
    glutTimerFunc(16, updatedPortalActivationScene9, 0);
    glutTimerFunc(16, updatedPortalDeactivationScene9, 0);
    glutTimerFunc(16, updatePortalActivationScene10, 0);
    glutTimerFunc(16, updateCatbusExitPortal, 0);
    glutTimerFunc(16, updatePortalDeactivationScene10, 0);

    glutFullScreen();
    glutMainLoop();
    
    return 0;
}