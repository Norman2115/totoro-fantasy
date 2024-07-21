#include <windows.h>
#include <iostream>
#include <gl/glut.h>
#include <vector>
#include <cmath>
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
#include "Subtitle.h"


float currentScene = 1;

/////   Declare global variables    /////

Sound sound;
//bool isRainSoundPlaying = false;
//bool isThunderSoundPlaying = false;
//bool isPortalSoundPlaying = false;
Portal portal;
Totoro totoroFront;
TotoroSide totoroSide;
LittleGirl girl(500, 150, 180, 0, false);
Mother mother(600, 200, 230);
Catbus catbus{ 3000, 0, 600, false };
Rain rain{ 500 };
Subtitle subtitle("This is the initial subtitle");

// For totoro side view walking
int state = 0;
float positionX = 1980.0f;
const float startX = 1.0f;
const float endX = 1020.0f;
int steps = 0;

// For sunset effect
int transitionTime = 15000; // 15 seconds
int sunsetSteps = 100;
int delay = transitionTime / sunsetSteps;
int currentStep = 0;

// For scene 11 keypress animation
float stepSize = 5.0f; // Step size for each move
float leftLimit = 0.0f, rightLimit = 1920.0f, bottomLimit = 0.0f, topLimit = 250.0f;

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

std::vector<Cloud*> clouds_scene5{
    new DayCloudTwo{ 1080, 920, 130, Colors::DAY_CLOUD },
    new DayCloudTwo{ 400, 880, 130, Colors::DAY_CLOUD },
    new DayCloudOne{ 1600, 830, 130, Colors::DAY_CLOUD },
    new DayCloudOne{ -10, 850, 130, Colors::DAY_CLOUD },
    new DayCloudOne{ 1950, 900, 130, Colors::DAY_CLOUD },
    new DayCloudTwo{ 1320, 695, 15, Colors::DAY_CLOUD }
};


std::vector<Cloud*> clouds_scene8{
    new DayCloudTwo(1000, 940, 120, Colors::NIGHT_CLOUD),
    new DayCloudOne(440, 910, 120, Colors::NIGHT_CLOUD),
    new DayCloudOne(1700, 860, 120, Colors::NIGHT_CLOUD),
    new DayCloudTwo(0, 860, 120, Colors::NIGHT_CLOUD)
};

std::vector<Cloud*> clouds_scene8Half{
    new DayCloudTwo(1080, 950, 130, Colors::NIGHT_CLOUD),
    new DayCloudTwo(400, 900, 130, Colors::NIGHT_CLOUD),
    new DayCloudOne(1600, 850, 130, Colors::NIGHT_CLOUD)
};

std::vector<Cloud*> clouds_scene9{
    new DayCloudTwo(1000, 440, 120, Colors::NIGHT_CLOUD),
    new DayCloudOne(440, 410, 120, Colors::NIGHT_CLOUD),
    new DayCloudOne(1700, 360, 120, Colors::NIGHT_CLOUD),
    new DayCloudTwo(0, 360, 120, Colors::NIGHT_CLOUD),
    new DayCloudTwo(1930, 460, 120, Colors::NIGHT_CLOUD)
};


std::vector<Cloud*> clouds_scene10{
    new DayCloudTwo(1080, 950, 110, Colors::DAY_CLOUD),
    new DayCloudTwo(400, 900, 110, Colors::DAY_CLOUD),
    new DayCloudOne(1600, 850, 110, Colors::DAY_CLOUD),
    new DayCloudTwo(1930, 885, 110, Colors::DAY_CLOUD)
};

std::vector<Cloud*> clouds_scene11{
    new DayCloudTwo(1080, 900, 140, Colors::DAY_CLOUD),
    new DayCloudTwo(400, 850, 140, Colors::DAY_CLOUD),
    new DayCloudOne(1600, 800, 140, Colors::DAY_CLOUD),
    new DayCloudTwo(1930, 900, 140, Colors::DAY_CLOUD)
};

///// Tree /////

TreeTwo tree8_scene3;
TreeTwo tree9_scene3;
TreeOne tree10_scene3;
TreeTwo tree11_scene3;
TreeTwo tree12_scene3;
TreeTwo tree13_scene3;

///// Grass /////

std::vector<Elements*> grass_scene5 {
    new GrassLineTwo(200, 220, 45, Colors::GRASS_NIGHT),
    new GrassLineOne(280, 230, 55, Colors::GRASS_NIGHT),
    new GrassLineTwo(30, 218, 46, Colors::GRASS_NIGHT),
    new GrassLineOne(40, 150, 60, Colors::GRASS_NIGHT),
    new GrassLineOne(190, 80, 59, Colors::GRASS_NIGHT),
    new GrassLineOne(760, 190, 61, Colors::GRASS_NIGHT),
    new GrassLineOne(1230, 44, 62, Colors::GRASS_NIGHT),
    new GrassLineOne(1450, 90, 59, Colors::GRASS_NIGHT),
    new GrassLineTwo(350, 160, 46, Colors::GRASS_NIGHT),
    new GrassLineTwo(550, 190, 44, Colors::GRASS_NIGHT),
    new GrassLineTwo(900, 120, 43, Colors::GRASS_NIGHT),
    new GrassLineTwo(1200, 200, 44, Colors::GRASS_NIGHT),
    new GrassLineTwo(1800, 110, 46, Colors::GRASS_NIGHT),
    new GrassLineTwo(1600, 220, 47, Colors::GRASS_NIGHT),
    new GrassLineOne(1290, 220, 59, Colors::GRASS_NIGHT),
    new GrassLineTwo(1895, 203, 48, Colors::GRASS_NIGHT)
};

std::vector<Elements*> grass_scene8half{
    new GrassTwo(190, 250, 55, Colors::GRASS_NIGHT),
    new GrassOne(456, 249, 50, Colors::GRASS_NIGHT),
    new GrassTwo(1210, 250, 50, Colors::GRASS_NIGHT),
    new GrassOne(266, 250, 52, Colors::GRASS_NIGHT),
    new GrassOne(766, 250, 55, Colors::GRASS_NIGHT),
    new GrassOne(1730, 249, 53, Colors::GRASS_NIGHT),
    new GrassTwo(1820, 250, 49, Colors::GRASS_NIGHT),
    new GrassTwo(810, 248, 52, Colors::GRASS_NIGHT),
    new GrassTwo(20, 248, 52, Colors::GRASS_NIGHT),
    new GrassOne(50, 150, 60, Colors::GRASS_NIGHT),
    new GrassOne(180, 70, 59, Colors::GRASS_NIGHT),
    new GrassOne(1240, 80, 62, Colors::GRASS_NIGHT),
    new GrassOne(1550, 60, 59, Colors::GRASS_NIGHT),
    new GrassTwo(300, 140, 46, Colors::GRASS_NIGHT),
    new GrassTwo(540, 120, 44, Colors::GRASS_NIGHT),
    new GrassTwo(890, 95, 43, Colors::GRASS_NIGHT),
    new GrassTwo(1100, 150, 44, Colors::GRASS_NIGHT),
    new GrassTwo(1830, 30, 46, Colors::GRASS_NIGHT),
    new GrassTwo(1450, 180, 47, Colors::GRASS_NIGHT)
};

///// Mushrooms /////

std::vector<Mushroom1*> mushrooms_scene5{
    new mushroomTwo(695, 880, 13, Colors::MUSHROOM_DAY),
    new mushroomThree(710, 880, 10, Colors::MUSHROOM_DAY),
    new mushroomThree(1305, 733, 15, Colors::MUSHROOM_DAY),
    new mushroomOne(450, 250, 300, Colors::MUSHROOM_DAY),
    new mushroomThree(600, 250, 275, Colors::MUSHROOM_DAY),
    new mushroomThree(1000, 250, 150, Colors::MUSHROOM_DAY),
    new mushroomThree(1500, 250, 300, Colors::MUSHROOM_DAY),
    new mushroomThree(1600, 250, 200, Colors::MUSHROOM_DAY)
};

std::vector<Mushroom1*> mushrooms_scene8half{
    new mushroomThree(360, 250, 500, Colors::MUSHROOM_NIGHT),
    new mushroomThree(820, 250, 600, Colors::MUSHROOM_NIGHT),
    new mushroomThree(1500, 250, 500, Colors::MUSHROOM_NIGHT),
    new mushroomThree(500, 250, 400, Colors::MUSHROOM_NIGHT),
    new mushroomThree(1210, 250, 350, Colors::MUSHROOM_NIGHT),
    new mushroomThree(1650, 250, 150, Colors::MUSHROOM_NIGHT),
    new mushroomThree(155, 250, 120, Colors::MUSHROOM_NIGHT)
};

///// Flower /////

std::vector<Flower*> flowers_scene5{
    new Flower(1650, 90, 40, Colors::FLOWER_BLUE),
    new Flower(1000, 170, 40, Colors::FLOWER_PURPLE),
    new Flower(550, 60, 40, Colors::FLOWER_RED)
};

std::vector<Flower*> flowers_scene8half{
    new  Flower(1050, 100, 40, Colors::FLOWER_BLUE),
    new Flower(400, 190, 40, Colors::FLOWER_CYAN),
    new Flower(100, 90, 40, Colors::FLOWER_RED),
    new Flower(800, 50, 40, Colors::FLOWER_PURPLE),
    new Flower(1300, 190, 40, Colors::FLOWER_RED),
    new Flower(1800, 120, 40, Colors::FLOWER_PURPLE)
};

///// Island /////

std::vector <Island*> islands_scene5{

};


///// Sun /////

DaySunOne sun_scene5(160, 930, 110, Colors::DAY_SUN);

///// Flags //////
bool isScene1End = false;
bool isScene2End = false;
bool isScene3End = false;
bool isScene4End = false;
bool isScene5End = false;
bool isScene6End = false;
bool isScene8End = false;
bool isScene8HalfEnd = false;
bool isScene9End = false;
bool isScene10End = false;  
bool isScene11End = false;

bool thunderTriggeredOnScene2 = false;
bool thunderTriggeredOnScene3 = false;

bool isScene1Initialized = false;
bool isScene2Initialized = false;
bool isScene3GirlPosInitialized = false;
bool isScene4Initialized = false;
bool isScene4AfterBounceInitialized = false;
bool isScene5Initialized = false;
bool isScene6Initialized = false;
bool isScene8Initialized = false;
bool isScene9Initialized = false;
bool isScene10Initialized = false;
bool isScene11Initialized = false;
bool isSunsetAngleInitialized = false;
bool isScene8HalfInitialized = false;
bool isScene11AfterDropOffInitialized = false;

bool isDiagonalMovement = false;
bool isVerticalMovement = false;
bool isGirlEnterPortal = false;
bool isGirlExitPortal = false;
bool isCatbusEnterPortal = false;
bool isCatbusExitPortal = false;
bool activatePortalScene4 = false;
bool isPortalActivatedScene4 = false;
bool isPortalDeactivatedScene4 = false;
bool isPortalActivatedScene9 = false;
bool isPortalDeactivatedScene9 = false;
bool isPortalActivatedScene10 = false;
bool isPortalDeactivatedScene10 = false;
bool isBouncing = true;
bool isCrying = false;
bool isTotoroAppeared = false;
bool isTotoroComforting = false;
bool isFinishCrying = false;

bool isPickup = false;
bool isDropOff = false;
bool isCatbusReachedGround = false;

bool isGirlAtScreenCenterScene5 = false;
bool isSunPartiallySet = false;

bool isCatbusAtScreenCenterScene8Half = false;
bool isCatbusFastForwardDurationEnd = false;

bool keyPressed = false;
bool isSpecialKeyPressed = false;
bool isWalkingAnimationActive = false;

///// Timer and Delay Variables /////

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

int transitionScene6to8DelayCounter = 0;
const int transitionScene6to8DurationCounter = 110;

int pickupDelayCounter = 0;
const int pickupDurationCounter = 60;

int transitionScene9to10DelayCounter = 0;
const int transitionScene9to10DurationCounter = 5;

int portalActivationScene4DelayCounter = 0;
const int portalActivationScene4DurationCounter = 20;

int portalDeactivationScene4DelayCounter = 0;
const int portalDeactivationScene4DurationCounter = 120;

int portalActivationScene10DelayCounter = 0;
const int portalActivationScene10DurationCounter = 20;

int portalDeactivationScene10DelayCounter = 0;
const int portalDeactivationScene10DurationCounter = 60;

int dropOffDelayCounter = 0;
const int dropOffDurationCounter = 60;

int catbusRunCounter = 0;
const int catbusRunDuration = 500;

int hugDelayAfterDropOffCounter = 0;
const int hugDelayAfterDropOffDuration = 120;

int afterHugEndingDelayCounter = 0;
const int afterHugEndingDelayDuration = 120;

/////   Declare states  /////

enum LittleGirlState {
    LITTLE_GIRL_FRONT_VIEW,
    LITTLE_GIRL_SIDE_VIEW,
    LITTLE_GIRL_MOVING,
    LITTLE_GIRL_HUG
};

enum TotoroState {
    TOTORO_INITIAL_STATE,
    TOTORO_FRONT_VIEW,
    TOTORO_SIDE_VIEW_WALKING
};

enum CatbusState {
    CATBUS_INITIAL_STATE,
    CATBUS_STANDSTILL,
    CATBUS_RUNNING
};

enum MotherState {
    MOTHER_FRONT_VIEW,
    MOTHER_HUG
};

LittleGirlState currentGirlState = LITTLE_GIRL_FRONT_VIEW;
TotoroState currentTotoroState = TOTORO_INITIAL_STATE;
CatbusState currentCatbusState = CATBUS_RUNNING;
MotherState currentMotherState = MOTHER_FRONT_VIEW;

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
    GrassTwo grass1(200, 203, 45, Colors::GRASS_NIGHT);
    grass1.draw();
    GrassTwo grass2(400, 203, 47, Colors::GRASS_NIGHT);
    grass2.draw();
    GrassTwo grass3(1200, 200, 46, Colors::GRASS_NIGHT);
    grass3.draw();
    GrassOne grass4(260, 203, 55, Colors::GRASS_NIGHT);
    grass4.draw();
    GrassOne grass5(760, 200, 60, Colors::GRASS_NIGHT);
    grass5.draw();
    GrassOne grass6(1700, 199, 57, Colors::GRASS_NIGHT);
    grass6.draw();
    GrassTwo grass7(1800, 200, 44, Colors::GRASS_NIGHT);
    grass7.draw();
    GrassTwo grass8(830, 198, 46, Colors::GRASS_NIGHT);
    grass8.draw();
    GrassTwo grass9(30, 203, 46, Colors::GRASS_NIGHT);
    grass9.draw();
    //Lower Level
    GrassOne grass10(50, 100, 60, Colors::GRASS_NIGHT);
    grass10.draw();
    GrassOne grass11(180, 70, 59, Colors::GRASS_NIGHT);
    grass11.draw();
    GrassOne grass12(750, 160, 61, Colors::GRASS_NIGHT);
    grass12.draw();
    GrassOne grass13(1240, 30, 62, Colors::GRASS_NIGHT);
    grass13.draw();
    GrassOne grass14(1550, 60, 59, Colors::GRASS_NIGHT);
    grass14.draw();
    GrassTwo grass15(300, 110, 46, Colors::GRASS_NIGHT);
    grass15.draw();
    GrassTwo grass17(890, 65, 43, Colors::GRASS_NIGHT);
    grass17.draw();
    GrassTwo grass18(1100, 150, 44, Colors::GRASS_NIGHT);
    grass18.draw();
    GrassTwo grass19(1830, 90, 46, Colors::GRASS_NIGHT);
    grass19.draw();
    GrassTwo grass20(1450, 180, 47, Colors::GRASS_NIGHT);
    grass20.draw();
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
    case LITTLE_GIRL_HUG:
        girl.hug();
    }

    subtitle.draw();

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
    GrassTwo grass21(1613, 386, 40, Colors::GRASS_NIGHT);
    grass21.draw();
    TreeTwo tree3;
    tree3.draw(1300, 320, 250, Colors::TREE_NIGHT);
    GrassTwo grass20(1317, 322, 30, Colors::GRASS_NIGHT);
    grass20.draw();

    //Upper Level
//Upper Level
    GrassTwo grass1(1550, 388, 57, Colors::GRASS_NIGHT);
    grass1.drawWithRotation(9);
    GrassTwo grass2(800, 160, 55, Colors::GRASS_NIGHT);
    grass2.drawWithRotation(25);
    GrassTwo grass3(600, 45, 55, Colors::GRASS_NIGHT);
    grass3.drawWithRotation(33);
    GrassTwo grass4(400, 157, 20, Colors::GRASS_NIGHT);
    grass4.drawWithRotation(340);
    GrassTwo grass5(30, 258, 20, Colors::GRASS_NIGHT);
    grass5.drawWithRotation(345);
    GrassOne grass9(1750, 400, 65, Colors::GRASS_NIGHT);
    grass9.drawWithRotation(1);
    GrassOne grass10(900, 208, 60, Colors::GRASS_NIGHT);
    grass10.drawWithRotation(22);
    GrassOne grass11(550, 98, 30, Colors::GRASS_NIGHT);
    grass11.drawWithRotation(335);

    //Lower Level
    GrassOne grass12(90, 40, 30, Colors::GRASS_NIGHT);
    grass12.drawWithRotation(330);
    GrassTwo grass7(440, 85, 20, Colors::GRASS_NIGHT);
    grass7.drawWithRotation(335);
    GrassOne grass13(950, 85, 46, Colors::GRASS_NIGHT);
    grass13.drawWithRotation(30);
    GrassTwo grass14(1400, 250, 43, Colors::GRASS_NIGHT);
    grass14.drawWithRotation(13);
    GrassTwo grass8(1800, 200, 50, Colors::GRASS_NIGHT);
    grass8.drawWithRotation(10);

    House house;
    house.draw(20.0f, 350.0f, 250, false, false);
    GrassTwo grass15(65, 227, 20, Colors::GRASS_NIGHT);
    grass15.drawWithRotation(0);
    GrassOne grass16(10, 227, 20, Colors::GRASS_NIGHT);
    grass16.drawWithRotation(0);
    GrassOne grass17(145, 225, 20, Colors::GRASS_NIGHT);
    grass17.drawWithRotation(0);

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
    GrassOne grass22(1568, 153, 50, Colors::GRASS_NIGHT);
    grass22.draw();
    TreeTwo tree9;
    tree9.draw(1850, 80, 210, Colors::TREE_NIGHT);
    GrassTwo grass23(1840, 82, 30, Colors::GRASS_NIGHT);
    grass23.draw();

    //Fourth Layer
    TreeTwo tree10;
    tree10.draw(1470, -60, 225, Colors::TREE_NIGHT);
    TreeOne tree4;
    tree4.draw(1200, -150, 250, Colors::TREE_NIGHT);
    TreeOne tree11;
    tree11.draw(1720, -210, 255, Colors::TREE_NIGHT);

    rain.renderRain();

    subtitle.draw();

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
    SmallRockOne rock1(1800, 210, 150, Colors::ROCK);
    rock1.draw();
    GrassTwo grass1(200, 250, 45, Colors::GRASS_NIGHT);
    grass1.draw();
    GrassTwo grass2(460, 249, 47, Colors::GRASS_NIGHT);
    grass2.draw();
    GrassOne grass3(260, 250, 55, Colors::GRASS_NIGHT);
    grass3.draw();
    GrassOne grass4(760, 250, 60, Colors::GRASS_NIGHT);
    grass4.draw();
    GrassTwo grass5(30, 248, 46, Colors::GRASS_NIGHT);
    grass5.draw();
    GrassTwo grass6(1150, 250, 46, Colors::GRASS_NIGHT);
    grass6.draw();
    SmallRockTwo rock2(1190, 235, 150, Colors::ROCK);
    rock2.draw();

    //Lower Level
    GrassOne grass7(40, 150, 60, Colors::GRASS_NIGHT);
    grass7.draw();
    GrassOne grass8(190, 80, 59, Colors::GRASS_NIGHT);
    grass8.draw();
    GrassOne grass9(760, 190, 61, Colors::GRASS_NIGHT);
    grass9.draw();
    GrassOne grass10(1230, 44, 62, Colors::GRASS_NIGHT);
    grass10.draw();
    GrassOne grass11(1450, 90, 59, Colors::GRASS_NIGHT);
    grass11.draw();
    GrassTwo grass12(350, 160, 46, Colors::GRASS_NIGHT);
    grass12.draw();
    GrassTwo grass13(550, 190, 44, Colors::GRASS_NIGHT);
    grass13.draw();
    GrassTwo grass14(900, 120, 43, Colors::GRASS_NIGHT);
    grass14.draw();
    GrassTwo grass15(1200, 200, 44, Colors::GRASS_NIGHT);
    grass15.draw();
    GrassTwo grass16(1800, 110, 46, Colors::GRASS_NIGHT);
    grass16.draw();
    GrassTwo grass17(1600, 220, 47, Colors::GRASS_NIGHT);
    grass17.draw();
    GrassOne grass18(1290, 220, 59, Colors::GRASS_NIGHT);
    grass18.draw();
    GrassTwo grass19(1895, 203, 48, Colors::GRASS_NIGHT);
    grass19.draw();
    GrassOne grass20(1676, 205, 55, Colors::GRASS_NIGHT);
    grass20.draw();

    //Second Layer
    TreeTwo tree6;
    tree6.draw(1040, 225, 330, Colors::TREE_NIGHT);
    GrassOne grass21(1060, 224, 55, Colors::GRASS_NIGHT);
    grass21.draw();
    TreeTwo tree7;
    tree7.draw(220, 215, 320, Colors::TREE_NIGHT);
    GrassTwo grass22(209, 217, 38, Colors::GRASS_NIGHT);
    grass22.draw();

    portal.draw(1500.0f, 410.0f, 90.0f, 140.0f);

    switch (currentGirlState) {
    case LITTLE_GIRL_FRONT_VIEW:
        girl.drawFrontView();
        break;
    case LITTLE_GIRL_SIDE_VIEW:
    case LITTLE_GIRL_MOVING:
        girl.drawSideView();
        break;
    case LITTLE_GIRL_HUG:
        girl.hug();
    }

    //Third Layer
    tree8_scene3.draw(900, 150, 350, Colors::TREE_NIGHT);
    GrassOne grass23(875, 152, 45, Colors::GRASS_NIGHT);
    grass23.draw();
    tree9_scene3.draw(500, 90, 360, Colors::TREE_NIGHT);
    GrassTwo grass24(515, 91, 30, Colors::GRASS_NIGHT);
    grass24.draw();

    //Fourth Layer
    tree10_scene3.draw(100, -200, 360, Colors::TREE_NIGHT);
    tree11_scene3.draw(630, -240, 370, Colors::TREE_NIGHT);
    tree12_scene3.draw(980, -320, 360, Colors::TREE_NIGHT);
    tree13_scene3.draw(420, -470, 360, Colors::TREE_NIGHT);
    TreeTwo tree14;
    tree14.draw(1900, -400, 360, Colors::TREE_NIGHT);

    rain.renderRain();

    subtitle.draw();

    glFlush();
    glutSwapBuffers();
}

static void displayScene4() {
    glClear(GL_COLOR_BUFFER_BIT);
    sound.stopPortalSound();
  
    Background::Scene4();
    RainbowOne rainbow;

    DaySunOne sun(160, 930, 110, Colors::DAY_SUN);
    sun.draw();

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

    mushroomThree mushroom2(1800, 250, 300, Colors::MUSHROOM_DAY);
    mushroom2.draw(true);
    mushroomOne mushroom3(1700, 250, 100, Colors::MUSHROOM_DAY);
    mushroom3.draw(true);
    mushroomOne mushroom5(1000, 250, 300, Colors::MUSHROOM_DAY);
    mushroom5.draw(true);
    mushroomOne mushroom6(1100, 250, 140, Colors::MUSHROOM_DAY);
    mushroom6.draw(true);

    mushroomOne mushroom4(720, 768, 30, Colors::MUSHROOM_DAY);
    mushroom4.draw(false);
    mushroomTwo mushroom7(680, 768, 10, Colors::MUSHROOM_DAY);
    mushroom7.draw(false);
    mushroomThree mushroom8(1790, 640, 30, Colors::MUSHROOM_DAY);
    mushroom8.draw(false);

    //Upper Level
    GrassOne grass1(190, 250, 55, Colors::GRASS_DAY);
    grass1.draw();
    GrassTwo grass2(456, 249, 50, Colors::GRASS_DAY);
    grass2.draw();
    GrassOne grass3(1210, 250, 50, Colors::GRASS_DAY);
    grass3.draw();
    GrassTwo grass4(266, 250, 52, Colors::GRASS_DAY);
    grass4.draw();
    GrassTwo grass5(766, 250, 55, Colors::GRASS_DAY);
    grass5.draw();
    GrassTwo grass6(1730, 249, 53, Colors::GRASS_DAY);
    grass6.draw();
    GrassOne grass7(1820, 250, 49, Colors::GRASS_DAY);
    grass7.draw();
    GrassOne grass8(810, 248, 52, Colors::GRASS_DAY);
    grass8.draw();
    GrassOne grass9(20, 248, 52, Colors::GRASS_DAY);
    grass9.draw();

    //Lower Level
    GrassTwo grass10(50, 150, 60, Colors::GRASS_DAY);
    grass10.draw();
    GrassTwo grass11(180, 70, 59, Colors::GRASS_DAY);
    grass11.draw();
    GrassTwo grass13(1240, 80, 62, Colors::GRASS_DAY);
    grass13.draw();
    GrassTwo grass14(1550, 60, 59, Colors::GRASS_DAY);
    grass14.draw();
    GrassOne grass15(300, 140, 46, Colors::GRASS_DAY);
    grass15.draw();
    GrassOne grass16(540, 120, 44, Colors::GRASS_DAY);
    grass16.draw();
    GrassOne grass17(890, 95, 43, Colors::GRASS_DAY);
    grass17.draw();
    GrassOne grass18(1100, 150, 44, Colors::GRASS_DAY);
    grass18.draw();
    GrassOne grass19(1830, 30, 46, Colors::GRASS_DAY);
    grass19.draw();
    GrassOne grass20(1450, 180, 47, Colors::GRASS_DAY);
    grass20.draw();

    switch (currentGirlState) {
        case LITTLE_GIRL_FRONT_VIEW:
            girl.drawFrontView();
            break;
        case LITTLE_GIRL_SIDE_VIEW:
        case LITTLE_GIRL_MOVING:
            girl.drawSideView();
            break;
        case LITTLE_GIRL_HUG:
            girl.hug();
    }

    // Flowers
    Flower flower1(80, 200, 40, Colors::FLOWER_BLUE);
    flower1.draw(40);
    Flower flower3(1050, 190, 40, Colors::FLOWER_ORANGE);
    flower3.draw(50);
    Flower flower4(790, 20, 40, Colors::FLOWER_PURPLE);
    flower4.draw(60);
    Flower flower5(1800, 100, 40, Colors::FLOWER_RED);
    flower5.draw(80);
    Flower flower6(400, 50, 40, Colors::FLOWER_YELLOW);
    flower6.draw(90);

    subtitle.draw();

    glFlush();
    glutSwapBuffers();
}

static void displayScene5() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene5(girl, islands_scene5, grass_scene5, clouds_scene5, mushrooms_scene5, flowers_scene5, sun_scene5, currentStep, sunsetSteps);
    subtitle.draw();
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

    mushroomThree mushroom5(250, 250, 500, Colors::MUSHROOM_NIGHT);
    mushroom5.draw(true);
    mushroomThree mushroom6(820, 250, 600, Colors::MUSHROOM_NIGHT);
    mushroom6.draw(true);
    mushroomThree mushroom7(1500, 250, 500, Colors::MUSHROOM_NIGHT);
    mushroom7.draw(true);

    mushroomThree mushroom1(-150, 250, 800, Colors::MUSHROOM_NIGHT);
    mushroom1.draw(true);
    mushroomThree mushroom2(500, 250, 700, Colors::MUSHROOM_NIGHT);
    mushroom2.draw(true);
    mushroomThree mushroom4(1800, 250, 750, Colors::MUSHROOM_NIGHT);
    mushroom4.draw(true);
    mushroomThree mushroom3(1200, 250, 820, Colors::MUSHROOM_NIGHT);
    mushroom3.draw(true);

    GrassTwo grass1(190, 250, 55, Colors::GRASS_NIGHT);
    grass1.draw();
    GrassOne grass2(456, 249, 50, Colors::GRASS_NIGHT);
    grass2.draw();
    GrassTwo grass3(1210, 250, 50, Colors::GRASS_NIGHT);
    grass3.draw();
    GrassOne grass4(266, 250, 52, Colors::GRASS_NIGHT);
    grass4.draw();
    GrassOne grass5(766, 250, 55, Colors::GRASS_NIGHT);
    grass5.draw();
    GrassOne grass6(1730, 249, 53, Colors::GRASS_NIGHT);
    grass6.draw();
    GrassTwo grass7(1820, 250, 49, Colors::GRASS_NIGHT);
    grass7.draw();
    GrassTwo grass8(810, 248, 52, Colors::GRASS_NIGHT);
    grass8.draw();
    GrassTwo grass9(20, 248, 52, Colors::GRASS_NIGHT);
    grass9.draw();

    // Flowers
    Flower flower1(1050, 100, 40, Colors::FLOWER_BLUE);
    flower1.draw(60);
    Flower flower2(400, 190, 40, Colors::FLOWER_CYAN);
    flower2.draw(100);
    Flower flower3(100, 90, 40, Colors::FLOWER_RED);
    flower3.draw(130);
    Flower flower4(800, 120, 40, Colors::FLOWER_PURPLE);
    flower4.draw(20);
    Flower flower5(1300, 190, 40, Colors::FLOWER_RED);
    flower5.draw(60);
    Flower flower6(1800, 50, 40, Colors::FLOWER_PURPLE);
    flower6.draw(40);

    //Lower Level
    GrassOne grass10(50, 150, 60, Colors::GRASS_NIGHT);
    grass10.draw();
    GrassOne grass11(180, 70, 59, Colors::GRASS_NIGHT);
    grass11.draw();
    GrassOne grass13(1240, 80, 62, Colors::GRASS_NIGHT);
    grass13.draw();
    GrassOne grass14(1550, 60, 59, Colors::GRASS_NIGHT);
    grass14.draw();
    GrassTwo grass15(300, 140, 46, Colors::GRASS_NIGHT);
    grass15.draw();
    GrassTwo grass16(540, 120, 44, Colors::GRASS_NIGHT);
    grass16.draw();
    GrassTwo grass17(890, 95, 43, Colors::GRASS_NIGHT);
    grass17.draw();
    GrassTwo grass18(1100, 150, 44, Colors::GRASS_NIGHT);
    grass18.draw();
    GrassTwo grass19(1830, 30, 46, Colors::GRASS_NIGHT);
    grass19.draw();
    GrassTwo grass20(1450, 180, 47, Colors::GRASS_NIGHT);
    grass20.draw();

    switch (currentGirlState) {
        case LITTLE_GIRL_FRONT_VIEW:
            girl.drawFrontView();
            break;
        case LITTLE_GIRL_SIDE_VIEW:
        case LITTLE_GIRL_MOVING:
            girl.drawSideView();
            break;
        case LITTLE_GIRL_HUG:
            girl.hug();
    }
    
    switch (currentTotoroState) {
        case TOTORO_INITIAL_STATE:
            break;
        case TOTORO_FRONT_VIEW:
            totoroFront.draw(1080.0f, 450.0f, 300.0f);
            break;
        case TOTORO_SIDE_VIEW_WALKING:
            totoroSide.draw(positionX, 420.0f, 270.0f);
            break;
    }

    subtitle.draw();

    glFlush();
    glutSwapBuffers();
}

static void displayScene7() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene6_7();

    mushroomThree mushroom5(250, 250, 500, Colors::MUSHROOM_NIGHT);
    mushroom5.draw(true);
    mushroomThree mushroom6(820, 250, 600, Colors::MUSHROOM_NIGHT);
    mushroom6.draw(true);
    mushroomThree mushroom7(1500, 250, 500, Colors::MUSHROOM_NIGHT);
    mushroom7.draw(true);

    mushroomThree mushroom1(-150, 250, 800, Colors::MUSHROOM_NIGHT);
    mushroom1.draw(true);
    mushroomThree mushroom2(500, 250, 700, Colors::MUSHROOM_NIGHT);
    mushroom2.draw(true);
    mushroomThree mushroom3(1200, 250, 820, Colors::MUSHROOM_NIGHT);
    mushroom3.draw(true);
    mushroomThree mushroom4(1800, 250, 750, Colors::MUSHROOM_NIGHT);
    mushroom4.draw(true);

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

    for (auto& cloud : clouds_scene8) {
        cloud->draw();
    }

    IslandOne island1;
    island1.draw(1400, 900, 100, Colors::ISLAND_NIGHT);
    mushroomThree mushroom1(1390, 928, 20, Colors::MUSHROOM_NIGHT);
    mushroom1.draw(false);
    mushroomTwo mushroom2(1410, 928, 10, Colors::MUSHROOM_NIGHT);
    mushroom2.draw(false);

    BusSignBoard sign;
    sign.draw(1200, 530, 100, 3);
  
    //Upper Level
    GrassOne grass1(1750, 450, 60, Colors::GRASS_NIGHT);
    grass1.drawWithRotation(2);
    GrassOne grass2(800, 320, 58, Colors::GRASS_NIGHT);
    grass2.drawWithRotation(12);
    GrassOne grass3(300, 128, 55, Colors::GRASS_NIGHT);
    grass3.drawWithRotation(24);
    GrassTwo grass4(1850, 448, 65, Colors::GRASS_NIGHT);
    grass4.drawWithRotation(358);
    GrassTwo grass5(900, 350, 60, Colors::GRASS_NIGHT);
    grass5.drawWithRotation(15);
    GrassTwo grass6(550, 237, 60, Colors::GRASS_NIGHT);
    grass6.drawWithRotation(22);
    GrassOne grass7(1300, 425, 56, Colors::GRASS_NIGHT);
    grass7.drawWithRotation(5);
    GrassOne grass8(1500, 445, 58, Colors::GRASS_NIGHT);
    grass8.drawWithRotation(5);
    GrassTwo grass9(80, 10, 40, Colors::GRASS_NIGHT);
    grass9.drawWithRotation(30);

    // Flowers
    Flower flower1(1550, 370, 40, Colors::FLOWER_ORANGE);
    flower1.draw(60);
    Flower flower2(1000, 200, 40, Colors::FLOWER_YELLOW);
    flower2.draw(100);
    Flower flower3(1300, 90, 40, Colors::FLOWER_BLUE);
    flower3.draw(130);
    Flower flower4(1850, 30, 40, Colors::FLOWER_PURPLE);
    flower4.draw(20);
    Flower flower5(500, 60, 40, Colors::FLOWER_RED);
    flower5.draw(40);

    //Inner Level
    GrassOne grass10(380, 90, 60, Colors::GRASS_NIGHT);
    grass10.drawWithRotation(20);
    GrassOne grass11(1000, 300, 58, Colors::GRASS_NIGHT);
    grass11.drawWithRotation(8);
    GrassOne grass12(1700, 350, 55, Colors::GRASS_NIGHT);
    grass12.drawWithRotation(3);
    GrassTwo grass13(600, 75, 65, Colors::GRASS_NIGHT);
    grass13.drawWithRotation(355);
    GrassTwo grass14(1200, 180, 60, Colors::GRASS_NIGHT);
    grass14.drawWithRotation(15);
    GrassTwo grass15(1500, 60, 60, Colors::GRASS_NIGHT);
    grass15.drawWithRotation(12);
    GrassOne grass16(1850, 100, 58, Colors::GRASS_NIGHT);
    grass16.drawWithRotation(357);

    totoroFront.draw(1000.0f, 520.0f, 270.0f);
    girl.drawFrontView();

    switch (currentCatbusState) {
        case CATBUS_INITIAL_STATE:
            break;
        case CATBUS_RUNNING:
            catbus.drawRunningView();
            break;
        case CATBUS_STANDSTILL:
            catbus.drawStandstillView();
    }

    subtitle.draw();

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
    mushroomOne mushroom11(1818, 730, 20, Colors::MUSHROOM_NIGHT);
    mushroom11.draw(false);
    mushroomThree mushroom12(1840, 730, 13, Colors::MUSHROOM_NIGHT);
    mushroom12.draw(false);

    for (auto& cloud : clouds_scene8Half) {
        cloud->draw();
    }

    mushrooms_scene8half.at(0)->draw(true);
    mushrooms_scene8half.at(1)->draw(true);
    mushrooms_scene8half.at(2)->draw(true);
    mushrooms_scene8half.at(3)->draw(true);
    mushrooms_scene8half.at(4)->draw(true);
    mushrooms_scene8half.at(5)->draw(true);
    mushrooms_scene8half.at(6)->draw(true);

    //Upper Level
    grass_scene8half.at(0)->draw();
    grass_scene8half.at(1)->draw();
    grass_scene8half.at(2)->draw();
    grass_scene8half.at(3)->draw();
    grass_scene8half.at(4)->draw();
    grass_scene8half.at(5)->draw();
    grass_scene8half.at(6)->draw();
    grass_scene8half.at(7)->draw();
    grass_scene8half.at(8)->draw();


    // Flowers
    flowers_scene8half.at(0)->draw(60);
    flowers_scene8half.at(0)->draw(100);
    flowers_scene8half.at(0)->draw(130);
    flowers_scene8half.at(0)->draw(20);
    flowers_scene8half.at(0)->draw(60);
    flowers_scene8half.at(0)->draw(40);

    //Lower Level
    grass_scene8half.at(9)->draw();
    grass_scene8half.at(10)->draw();
    grass_scene8half.at(11)->draw();
    grass_scene8half.at(12)->draw();
    grass_scene8half.at(13)->draw();
    grass_scene8half.at(14)->draw();
    grass_scene8half.at(15)->draw();
    grass_scene8half.at(16)->draw();
    grass_scene8half.at(17)->draw();
    grass_scene8half.at(18)->draw();

    catbus.drawRunningView();

    subtitle.draw();

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
  
    mushroomThree mushroom4(800, -250, 400, Colors::MUSHROOM_NIGHT);
    mushroom4.draw(true);
    mushroomOne mushroom5(350, -165, 200, Colors::MUSHROOM_NIGHT);
    mushroom5.draw(true);

    IslandTwo island1;
    island1.draw(1300, 380, 100, Colors::ISLAND_NIGHT);
    mushroomOne mushroom6(1310, 400, 20, Colors::MUSHROOM_NIGHT);
    mushroom6.draw(false);
    mushroomTwo mushroom7(1290, 400, 10, Colors::MUSHROOM_NIGHT);
    mushroom7.draw(false);

    for (auto& cloud : clouds_scene9) {
        cloud->draw();
    }

    catbus.drawRunningView();

    subtitle.draw();

    glFlush();
    glutSwapBuffers();

}

static void displayScene10() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene10();

    DaySunOne sun(150, 940, 110, Colors::DAY_SUN);
    sun.draw();

    for (auto& cloud : clouds_scene10) {
        cloud->draw();
    }

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
    GrassTwo grass1(30, 496, 20, Colors::GRASS_DAY);
    grass1.drawWithRotation(358);
    GrassTwo grass2(123, 495, 17, Colors::GRASS_DAY);
    grass2.drawWithRotation(355);
    GrassOne grass3(250, 483, 20, Colors::GRASS_DAY);
    grass3.drawWithRotation(347);
    GrassTwo grass5(550, 420, 20, Colors::GRASS_DAY);
    grass5.drawWithRotation(345);
    GrassOne grass6(700, 369, 25, Colors::GRASS_DAY);
    grass6.drawWithRotation(342);
    GrassOne grass7(900, 280, 25, Colors::GRASS_DAY);
    grass7.drawWithRotation(332);
    GrassTwo grass8(1050, 195, 25, Colors::GRASS_DAY);
    grass8.drawWithRotation(325);
    GrassOne grass9(1250, 52, 25, Colors::GRASS_DAY);
    grass9.drawWithRotation(315);
    GrassTwo grass10(1300, 108, 20, Colors::GRASS_DAY);
    grass10.drawWithRotation(10);
    GrassOne grass11(1350, 120, 20, Colors::GRASS_DAY);
    grass11.drawWithRotation(15);
    GrassTwo grass12(1500, 153, 20, Colors::GRASS_DAY);
    grass12.drawWithRotation(5);

    //Lower Level
    GrassTwo grass13(60, 100, 20, Colors::GRASS_DAY);
    grass13.drawWithRotation(358);
    GrassTwo grass14(100, 400, 20, Colors::GRASS_DAY);
    grass14.drawWithRotation(355);
    GrassOne grass15(220, 150, 20, Colors::GRASS_DAY);
    grass15.drawWithRotation(355);
    GrassOne grass17(500, 300, 25, Colors::GRASS_DAY);
    grass17.drawWithRotation(342);
    GrassOne grass18(780, 50, 25, Colors::GRASS_DAY);
    grass18.drawWithRotation(332);
    GrassTwo grass19(1100, 70, 25, Colors::GRASS_DAY);
    grass19.drawWithRotation(2);
    GrassTwo grass20(1450, 25, 20, Colors::GRASS_DAY);
    grass20.drawWithRotation(350);

    catbus.drawRunningView();

    subtitle.draw();

    glFlush();
    glutSwapBuffers();

}

static void displayScene11() {
    glClear(GL_COLOR_BUFFER_BIT);
    Background::Scene11();

    DaySunOne sun(155, 940, 110, Colors::DAY_SUN);
    sun.draw();

    for (auto& cloud : clouds_scene11) {
        cloud->draw();
    }

    House house;
    house.draw(200.0f, 600.0f, 700.0f, true, true);

    //Upper Level
    GrassTwo grass1(200, 250, 45, Colors::GRASS_DAY);
    grass1.draw();
    GrassTwo grass2(400, 253, 47, Colors::GRASS_DAY);
    grass2.draw();
    GrassTwo grass3(1200, 250, 46, Colors::GRASS_DAY);
    grass3.draw();
    GrassOne grass4(260, 250, 55, Colors::GRASS_DAY);
    grass4.draw();
    GrassOne grass5(760, 250, 60, Colors::GRASS_DAY);
    grass5.draw();
    GrassOne grass6(1700, 249, 57, Colors::GRASS_DAY);
    grass6.draw();
    GrassTwo grass7(1800, 250, 44, Colors::GRASS_DAY);
    grass7.draw();
    GrassTwo grass8(830, 248, 46, Colors::GRASS_DAY);
    grass8.draw();
    GrassTwo grass9(30, 248, 46, Colors::GRASS_DAY);
    grass9.draw();

    //Lower Level
    GrassOne grass10(50, 100, 60, Colors::GRASS_DAY);
    grass10.draw();
    GrassOne grass11(180, 70, 59, Colors::GRASS_DAY);
    grass11.draw();
    GrassOne grass12(750, 160, 61, Colors::GRASS_DAY);
    grass12.draw();
    GrassOne grass13(1240, 30, 62, Colors::GRASS_DAY);
    grass13.draw();
    GrassOne grass14(1550, 60, 59, Colors::GRASS_DAY);
    grass14.draw();
    GrassTwo grass15(300, 140, 46, Colors::GRASS_DAY);
    grass15.draw();
    GrassTwo grass17(890, 65, 43, Colors::GRASS_DAY);
    grass17.draw();
    GrassTwo grass18(1100, 150, 44, Colors::GRASS_DAY);
    grass18.draw();
    GrassTwo grass19(1830, 90, 46, Colors::GRASS_DAY);
    grass19.draw();
    GrassTwo grass20(1450, 180, 47, Colors::GRASS_DAY);
    grass20.draw();

    switch (currentGirlState) {
        case LITTLE_GIRL_FRONT_VIEW:
            girl.drawFrontView();
            break;
        case LITTLE_GIRL_SIDE_VIEW:
        case LITTLE_GIRL_MOVING:
            girl.drawSideView();
            break;
        case LITTLE_GIRL_HUG:
            girl.hug();
    }

    switch (currentCatbusState) {
        case CATBUS_INITIAL_STATE:
            break;
        case CATBUS_RUNNING:
            catbus.drawRunningView();
            break;
        case CATBUS_STANDSTILL:
            catbus.drawStandstillView();
    }

    switch (currentMotherState) {
        case MOTHER_FRONT_VIEW:
            mother.drawFrontView();
            break;
        case MOTHER_HUG:
            mother.hug();
            break;
    }

    subtitle.draw();

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
    else if (currentScene == 8.5) {
        displayScene8Half();
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
    else if (currentScene == 12) {
        displayScene12();
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

static void updateScene(int value) {
    if (currentScene == 1) {
        if (!isScene1Initialized) {
            subtitle.setText("After a heated argument with his mother");
            isScene1Initialized = true;
        }

        if (currentGirlState == LITTLE_GIRL_MOVING) {
            girl.move(4.0f);
        }

        if (girl.getPosX() > 1920) {
            isScene1End = true;
            currentScene = 2;
            triggerThunder(0);
        }
    }
    else if (currentScene == 2) {
        if (!isScene2Initialized) {
            currentGirlState = LITTLE_GIRL_MOVING;
            girl.setCurrentAngle(2.2f);
            subtitle.setText("Rain started pouring down, as the girl start walks into the forest");
            isScene2Initialized = true;
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
            girl.setOpacity(1.0f);
            subtitle.setText("In the heart of the forest, there lies a mysterious portal");
            isScene3GirlPosInitialized = true;
        }
        if (currentGirlState == LITTLE_GIRL_MOVING) {
            if (!isDiagonalMovement) {
                girl.move(4.0f);
            }
            else {
                girl.moveDiagonally(1.8f, 1.8f);
            }
        }

        if (isGirlEnterPortal) {
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
            portal.setOpacity(0.0f);
            subtitle.setText("She was greeted by a wonderful and mystical new place");
            isScene4Initialized = true;
        }

        if (!isBouncing) {
            if (!isScene4AfterBounceInitialized) {
                currentGirlState = LITTLE_GIRL_SIDE_VIEW;
                currentGirlState = LITTLE_GIRL_MOVING;
            }
            girl.move(4.0f);

            if (girl.getPosX() > 1920) {
                isScene4End = true;
                currentScene = 5;
            }
        }
    }
    else if (currentScene == 5) {
        if (!isScene5Initialized) {
            currentGirlState = LITTLE_GIRL_MOVING;
            girl.setPosX(0);
            girl.setPosY(200);
            girl.setCharacterSize(210);
            subtitle.setText("The little girl happily explores the land with excitement");
            isScene5Initialized = true;
        }

        if (currentGirlState == LITTLE_GIRL_MOVING) {
            if (!isGirlAtScreenCenterScene5) {
                girl.move(6.0f);
            }
            else {
                girl.move(0.0f);
            }
        }

        if (girl.getPosX() >= 960 && !isSunPartiallySet) {
            isGirlAtScreenCenterScene5 = true;
        }

        if (girl.getPosX() >= 1920) {
            isScene5End = true;
            currentScene = 6;
        }
    }
    else if (currentScene == 6) {
        if (!isScene6Initialized) {
            currentGirlState = LITTLE_GIRL_MOVING;
            girl.setPosX(0);
            girl.setPosY(200);
            girl.setCharacterSize(210);
            subtitle.setText("Despite this, she couldn't help but started to miss the comfort of her own home");
            isScene6Initialized = true;
        }

        if (currentGirlState == LITTLE_GIRL_MOVING) {
            if (!isVerticalMovement) {
                girl.move(4.0f);
            }
            else {
                girl.moveVertically(1.8f);
            }
        }
        if (isScene6End) {
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
            subtitle.setText("Totoro brought the little girl to a bus stop, a way to bring her home");
            isScene8Initialized = true;
        }

        if (currentCatbusState == CATBUS_RUNNING) {
            catbus.moveInArc(0.1f, 0.05f);

            if (catbus.getPosX() < 10) {
                isScene8End = true;
                currentScene = 8.5;
            }
        }
    }
    else if (currentScene == 8.5) {
        if (!isScene8HalfInitialized) {
            currentCatbusState = CATBUS_RUNNING;
            catbus.setPosX(2000);
            catbus.setPosY(230);
            catbus.setBusSize(600);
            catbus.setIsBoarded(true);
            subtitle.setText("Press [ L ] to turn on/off the magical headlights");
            isScene8HalfInitialized = true;
        }

        if (currentCatbusState == CATBUS_RUNNING) {
            if (!isCatbusAtScreenCenterScene8Half) {
                if (catbus.getPosX() <= 800) {
                    catbus.moveDiagonal(-30.0f, 8.0f);
                }
                else {
                    catbus.move(30.0f);
                }
            }
            else {
                catbus.move(0.0f);
            }
        }

        if (catbus.getPosX() <= 960 && !isCatbusFastForwardDurationEnd) {
            isCatbusAtScreenCenterScene8Half = true;
        }

        if (catbus.getPosX() <= 0) {
            isScene8HalfEnd = true;
            currentScene = 9;
        }
    }
    else if (currentScene == 9) {
        if (!isScene9Initialized) {
            catbus.setPosX(1920);
            catbus.setPosY(550);
            catbus.setBusSize(450);
            catbus.setOpacity(1.0f);
            portal.setOpacity(0.0f);
            catbus.setIsBoarded(true);
            subtitle.setText("The Catbus's magical journey made her feel like she was floating through a dream");
            isScene9Initialized = true;
        }

        if (currentCatbusState == CATBUS_RUNNING) {
            catbus.move(8.0f);
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
            catbus.setIsBoarded(true);
            catbus.setIsDay(true);
            subtitle.setText("The sight of her beloved home growing ever closer filled her with an overwhelming sense of relief and joy");
            isScene10Initialized = true;
        }

        if (catbus.getPosX() <= 800) {
            isCatbusReachedGround = true;
        }

        if (currentCatbusState == CATBUS_RUNNING) {
            if (!isCatbusReachedGround) {
                catbus.moveDiagonal(-6.0f, -2.0f);
                if (catbus.getBusSize() > 350.0f) {
                    catbus.setBusSize(catbus.getBusSize() - 1.5f);
                }
            }
            else {
                catbus.moveDiagonal(-5.0f, 3.8f);
            }
        }

        if (catbus.getPosX() <= 600) {
            isScene10End = true;
            currentScene = 11;
        }
    }
    else if (currentScene == 11) {
        if (!isScene11Initialized) {
            currentCatbusState = CATBUS_RUNNING;
            catbus.setPosX(1920);
            catbus.setPosY(200);
            catbus.setBusSize(500);
            catbus.setIsBoarded(true);
            catbus.setIsDay(true);
            currentGirlState = LITTLE_GIRL_FRONT_VIEW;
            girl.setPosX(1150);
            girl.setPosY(200);
            girl.setOpacity(0.0f);
            mother.setPosX(600);
            mother.setPosY(200);
            mother.setCharacterSize(230);
            subtitle.setText("As she arrived, she saw her mother standing outside, her face filled with worry and hope as she anxiously awaited her return");
            isScene11Initialized = true;
        }

        if (currentCatbusState == CATBUS_RUNNING) {
            catbus.move(8.0f);
        }

        if (isDropOff && !isScene11AfterDropOffInitialized) {
            currentGirlState = LITTLE_GIRL_FRONT_VIEW;
            isScene11AfterDropOffInitialized = true;
        }

        float posXDiff = abs(girl.getPosX() - mother.getPosX());
        float posYDiff = abs(girl.getPosY() - mother.getPosY());

        if ((posXDiff <= 40.0f && posYDiff <= 40.0f) && currentGirlState == LITTLE_GIRL_HUG) {
            afterHugEndingDelayCounter++;
            if (afterHugEndingDelayCounter >= afterHugEndingDelayDuration) {
                isScene11End = true;
                currentScene = 12;
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateScene, 0);
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

        if (isFinishCrying) {
            transitionScene6to8DelayCounter++;
            if (transitionScene6to8DelayCounter >= transitionScene6to8DurationCounter) {
                isScene6End = true;
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
            isGirlEnterPortal = true;
            girl.setOpacity(0);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateGirlFadeInIntoPortal, 0);
}

static void updateGirlExitPortal(int value) {
    if (currentScene == 4) {
        portalActivationScene4DelayCounter++;
        if (portalActivationScene4DelayCounter >= portalActivationScene4DurationCounter) {
            activatePortalScene4 = true;
        }

        if (isPortalActivatedScene4) {
            if (girl.getOpacity() < 1) {
                girl.setOpacity(girl.getOpacity() + 0.1f);
            }
            portalDeactivationScene4DelayCounter++;
            if (portalDeactivationScene4DelayCounter >= portalDeactivationScene4DurationCounter) {
                isGirlExitPortal = true;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateGirlExitPortal, 0);
}

static void updateExitPortalBounce(int value) {
    if (currentScene == 4 && isBouncing && isPortalActivatedScene4) {
        isBouncing = girl.bounceVertical(30.0f, 200.0f, 1.0f, 30);
    }
    glutPostRedisplay();
    glutTimerFunc(30, updateExitPortalBounce, 0);
}

static void updatePortalActivationScene4(int value) {
    if (currentScene == 4 && !isPortalActivatedScene4 && activatePortalScene4) {
        portal.setOpacity(portal.getOpacity() + 0.03f);

        if (portal.getOpacity() >= 1.0f) {
            isPortalActivatedScene4 = true;
            portal.setOpacity(1.0f);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updatePortalActivationScene4, 0);
}

static void updatePortalDeactivationScene4(int value) {
    if (currentScene == 4 && !isPortalDeactivatedScene4) {
        if (isGirlExitPortal) {
            portal.setOpacity(portal.getOpacity() - 0.03f);

            if (portal.getOpacity() <= 0) {
                portal.setOpacity(0);
                isPortalDeactivatedScene4 = true;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updatePortalDeactivationScene4, 0);
}   

static void updatePortalActivationScene9(int value) {
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
    glutTimerFunc(16, updatePortalActivationScene9, 0);
}

static void updatePortalDeactivationScene9(int value) {
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
    glutTimerFunc(16, updatePortalDeactivationScene9, 0);
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
    else if (currentScene == 5) {
        if (isGirlAtScreenCenterScene5 && !isSunPartiallySet) {
            clouds_scene5.at(0)->moveInfinite(8.0f, false);
            clouds_scene5.at(1)->moveInfinite(8.0f, true);
            clouds_scene5.at(2)->moveInfinite(8.0f, true);
            clouds_scene5.at(3)->moveInfinite(8.0f, true);
            clouds_scene5.at(4)->moveInfinite(8.0f, false);
            clouds_scene5.at(5)->move(6.0f, true);
        }
        else {
            clouds_scene5.at(0)->moveInfinite(0.1f, false);
            clouds_scene5.at(1)->moveInfinite(0.1f, true);
            clouds_scene5.at(2)->moveInfinite(0.1f, true);
            clouds_scene5.at(3)->moveInfinite(0.1f, true);
            clouds_scene5.at(4)->moveInfinite(0.1f, false);
            clouds_scene5.at(5)->move(0.1f, true);
        }
    }
    else if (currentScene == 6) {
        clouds_scene6.at(0)->move(0.1f, true);
        clouds_scene6.at(1)->move(0.1f, true);
        clouds_scene6.at(2)->move(0.1f, false);
    }
    else if (currentScene == 8) {
        clouds_scene8.at(0)->move(0.1f, true);
        clouds_scene8.at(1)->move(0.1f, true);
        clouds_scene8.at(2)->move(0.1f, false);
        clouds_scene8.at(3)->move(0.1f, true);
    }
    else if (currentScene == 8.5) {
        if (isCatbusAtScreenCenterScene8Half && !isCatbusFastForwardDurationEnd) {
            clouds_scene8Half.at(0)->moveInfinite(0.15f, false);
            clouds_scene8Half.at(1)->moveInfinite(0.15f, false);
            clouds_scene8Half.at(2)->moveInfinite(0.15f, false);
        }
        else {
            clouds_scene8Half.at(0)->moveInfinite(0.1f, false);
            clouds_scene8Half.at(1)->moveInfinite(0.1f, false);
            clouds_scene8Half.at(2)->moveInfinite(0.1f, false);
        }
    }
    else if (currentScene == 9) {
        clouds_scene9.at(0)->move(0.1f, false);
        clouds_scene9.at(1)->move(0.1f, false);
        clouds_scene9.at(2)->move(0.1f, false);
        clouds_scene9.at(3)->move(0.1f, true);
        clouds_scene9.at(4)->move(0.1f, true);
    }
    else if (currentScene == 10) {
        clouds_scene10.at(0)->move(0.1f, true);
        clouds_scene10.at(1)->move(0.1f, false);
        clouds_scene10.at(2)->move(0.1f, false);
        clouds_scene10.at(3)->move(0.1f, false);
    }
    else if (currentScene == 11) {
        clouds_scene11.at(0)->move(0.1f, false);
        clouds_scene11.at(1)->move(0.1f, false);
        clouds_scene11.at(2)->move(0.1f, true);
        clouds_scene11.at(3)->move(0.1f, false);
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
            pickupDelayCounter++;
            if (pickupDelayCounter >= pickupDurationCounter) {
                currentTotoroState = TOTORO_FRONT_VIEW;
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

static void updateCatbusDropOff(int value) {
    if (currentScene == 11) {
        if (catbus.getPosX() <= 1200 && !isDropOff) {
            currentCatbusState = CATBUS_STANDSTILL;
            catbus.setIsBoarded(false);
            dropOffDelayCounter++;
            if (dropOffDelayCounter >= dropOffDurationCounter) {
                isDropOff = true;
            }
        }

        if (isDropOff) {
            currentCatbusState = CATBUS_RUNNING;
            girl.setOpacity(1.0f);
            catbus.setMovingRight(true);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateCatbusDropOff, 0);
}

static void updateSunset(int value) {
    if (currentScene == 5) {
        if (currentStep <= sunsetSteps) {
            currentStep++;
        }

        if (!isSunsetAngleInitialized) {
            sun_scene5.setCurrentAngle(Constants::PI / 2.27);
            isSunsetAngleInitialized = true;
        }
        
        if (!isGirlAtScreenCenterScene5) {
            sun_scene5.moveInArc(0.01f, 0.05f);
        }
        else {
            sun_scene5.moveInArc(0.18f, 0.05f);
        }

        if (sun_scene5.getPosX() >= 1800) {
            isSunPartiallySet = true;
            isGirlAtScreenCenterScene5 = false;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(delay, updateSunset, 0);
}

static void infiniteBackgroundScrollingScene5(int value) {
    if (currentScene == 5) {
        if (isGirlAtScreenCenterScene5 && !isSunPartiallySet) {
            mushrooms_scene5.at(3)->moveInfinite(7.0f, false);
            mushrooms_scene5.at(4)->moveInfinite(7.0f, false);
            mushrooms_scene5.at(5)->moveInfinite(7.0f, false);
            mushrooms_scene5.at(6)->moveInfinite(7.0f, false);
            mushrooms_scene5.at(7)->moveInfinite(7.0f, false);

            for (auto& grass : grass_scene5) {
                grass->moveInfinite(8.0f, false);
            }

            for (auto& flower : flowers_scene5) {
                flower->moveInfinite(8.0f, false);
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, infiniteBackgroundScrollingScene5, 0);
}

static void updateCatbusFastForwardTimer(int value) {
    if (currentScene == 8.5) {
        if (isCatbusAtScreenCenterScene8Half && !isCatbusFastForwardDurationEnd) {
            catbusRunCounter++;
            if (catbusRunCounter >= catbusRunDuration) {
                isCatbusFastForwardDurationEnd = true;
                isCatbusAtScreenCenterScene8Half = false;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateCatbusFastForwardTimer, 0);
}

static void infiniteBackgroundScrollingScene8Half(int value) {
    if (currentScene == 8.5) {
        if (isCatbusAtScreenCenterScene8Half && !isCatbusFastForwardDurationEnd) {
            for (auto& mushroom : mushrooms_scene8half) {
                mushroom->moveInfinite(30.0f, true);
            }

            for (auto& grass : grass_scene8half) {
                grass->moveInfinite(30.0f, true);
            }

            for (auto& flower : flowers_scene8half) {
                flower->moveInfinite(30.0f, true);
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, infiniteBackgroundScrollingScene8Half, 0);
}

static void updateMotherGivingHugDelay(int value) {
    if (currentScene == 11 && isDropOff) {
        hugDelayAfterDropOffCounter++;
        if (hugDelayAfterDropOffCounter >= hugDelayAfterDropOffDuration) {
            currentMotherState = MOTHER_HUG;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateMotherGivingHugDelay, 0);
}

static void handleKeypressScene11(int key, int x, int y) {
    if (currentScene == 11) {
        float posX = girl.getPosX();
        float posY = girl.getPosY();

        if (!isWalkingAnimationActive) {
            currentGirlState = LITTLE_GIRL_MOVING;
            isWalkingAnimationActive = true;
        }

        switch (key) {
            case GLUT_KEY_LEFT:
                girl.setMovingRight(false);
                if (posX - stepSize > leftLimit) {
                    posX -= stepSize;
                    girl.setPosX(posX);
                }
                keyPressed = true;
                break;
            case GLUT_KEY_RIGHT:
                girl.setMovingRight(true);
                if (posX + stepSize < rightLimit) {
                    posX += stepSize;
                    girl.setPosX(posX);
                }
                keyPressed = true;
                break;
            case GLUT_KEY_UP:
                if (posY + stepSize < topLimit) {
                    posY += stepSize;
                    girl.setPosY(posY);
                }
                keyPressed = true;
                break;
            case GLUT_KEY_DOWN:
                if (posY - stepSize > bottomLimit) {
                    posY -= stepSize;
                    girl.setPosY(posY);
                }
                keyPressed = true;
                break;
        }

        glutPostRedisplay();
    }
}

static void handleNormalKeyPress(unsigned char key, int x, int y) {
    if (currentScene == 11) {
        keyPressed = true;

        switch (key) {
            case 'H':
            case 'h':
                if (currentGirlState != LITTLE_GIRL_HUG) {
                    currentGirlState = LITTLE_GIRL_HUG;
                }
                else {
                    currentGirlState = LITTLE_GIRL_FRONT_VIEW;
                }
                break;
        }
    }

    if (currentScene == 8.5 || currentScene == 9) {
        keyPressed = true;
        switch (key) {
            case 'L':
            case 'l':
                if (catbus.getIsLightOn()) {
                    catbus.setIsLightOn(false);
                }
                else {
                    catbus.setIsLightOn(true);
                }
                break;
        }
    }
}

static void handleKeyRelease(unsigned char key, int x, int y) {
    if (currentScene == 11 && currentGirlState != LITTLE_GIRL_HUG) {
        keyPressed = false;

        if (!keyPressed) {
            isWalkingAnimationActive = false;
            currentGirlState = LITTLE_GIRL_FRONT_VIEW;
            glutPostRedisplay();
        }
    }
}

static void handleSpecialKeyRelease(int key, int x, int y) {
    if (currentScene == 11 && currentGirlState != LITTLE_GIRL_HUG) {
        keyPressed = false;

        if (!keyPressed) {
            isWalkingAnimationActive = false;
            currentGirlState = LITTLE_GIRL_FRONT_VIEW;
            glutPostRedisplay();
        }
    }
}

///// Subtitles /////

int nextSubstitleScene1DelayCounter = 0;
const int nextSubtitleScene1DelayDuration = 200;

static void updateNextSubtitleScene1(int value) {
    if (currentScene == 1) {
        nextSubstitleScene1DelayCounter++;
        if (nextSubstitleScene1DelayCounter >= nextSubtitleScene1DelayDuration) {
            subtitle.setText("The little girl decided to run away from home");
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateNextSubtitleScene1, 0);
}   

int nextSubstitleScene3DelayCounter = 0;
const int nextSubtitleScene3DelayDuration = 360;

static void updateNextSubtitleScene3(int value) {
    if (currentScene == 3) {
        nextSubstitleScene3DelayCounter++;
        if (nextSubstitleScene3DelayCounter >= nextSubtitleScene3DelayDuration) {
            subtitle.setText("The little girl walks in the portal");
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateNextSubtitleScene3, 0);
}

int nextSubstitleScene4DelayCounter = 0;
const int nextSubtitleScene4DelayDuration = 260;

static void updateNextSubtitleScene4(int value) {
    if (currentScene == 4) {
        nextSubstitleScene4DelayCounter++;
        if (nextSubstitleScene4DelayCounter >= nextSubtitleScene4DelayDuration) {
            subtitle.setText("Feeling relieved that she is far from home");
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateNextSubtitleScene4, 0);
}

int nextSubstitleScene5DelayCounter = 0;
const int nextSubtitleScene5DelayDuration = 520;

static void updateNextSubtitleScene5(int value) {
    if (currentScene == 5) {
        nextSubstitleScene5DelayCounter++;
        if (nextSubstitleScene5DelayCounter >= nextSubtitleScene5DelayDuration) {
            subtitle.setText("Despite this, she couldn't help but started to miss the comfort of her own home");
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateNextSubtitleScene5, 0);
}

int nextSubstitleScene6DelayCounter1 = 0;
const int nextSubtitleScene6DelayDuration1 = 120;
int nextSubstitleScene6DelayCounter2 = 0;
const int nextSubtitleScene6DelayDuration2 = 120;
bool isSubtitleChangedScene6_1 = false;
bool isSubtitleChangedScene6_2 = false;

static void updateNextSubtitleScene6(int value) {
    if (currentScene == 6) {
        if (!isSubtitleChangedScene6_1) {
            nextSubstitleScene6DelayCounter1++;
            if (nextSubstitleScene6DelayCounter1 >= nextSubtitleScene6DelayDuration1) {
                subtitle.setText("Eventually, she stopped and stood behind a giant mushroom");
            }
        }

        if (isCrying && !isSubtitleChangedScene6_1) {
            subtitle.setText("Tears began to stream down as she started to cry, longing to return home");
            isSubtitleChangedScene6_1 = true;
        }

        if (isTotoroAppeared && !isSubtitleChangedScene6_2) {
            nextSubstitleScene6DelayCounter2++;
            if (nextSubstitleScene6DelayCounter2 >= nextSubtitleScene6DelayDuration2) {
                subtitle.setText("The sound of the girl's sobs soon attracted the attention of Totoro");
                isSubtitleChangedScene6_2 = true;
            }
        }

        if (isFinishCrying) {
            subtitle.setText("Feeling the warmth and kindness radiating from Totoro, the girl gradually stopped crying");
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateNextSubtitleScene6, 0);
}

int nextSubstitleScene8DelayCounter = 0;
const int nextSubtitleScene8DelayDuration = 150;

static void updateNextSubtitleScene8(int value) {
    if (currentScene == 8) {
        nextSubstitleScene8DelayCounter++;
        if (nextSubstitleScene8DelayCounter >= nextSubtitleScene8DelayDuration) {
            subtitle.setText("The bus arrived with Totoro waving goodbye");
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateNextSubtitleScene8, 0);
}

int nextSubstitleScene8HalfDelayCounter = 0;
const int nextSubtitleScene8HalfDelayDuration = 230;

static void updateNextSubtitleScene8Half(int value) {
    if (currentScene == 8.5) {
        nextSubstitleScene8HalfDelayCounter++;
        if (nextSubstitleScene8HalfDelayCounter >= nextSubtitleScene8HalfDelayDuration) {
            subtitle.setText("As the girl enjoyed the ride on the Catbus, she felt a sense of wonder and excitement");
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateNextSubtitleScene8Half, 0);
}

int nextSubstitleScene11DelayCounter = 0;
const int nextSubtitleScene11DelayDuration = 240;
bool isSubtitleChangedScene11_1 = false;
bool isSubtitleChangedScene11_2 = false;

static void updateNextSubtitleScene11(int value) {
    if (currentScene == 11) {
        if (!isSubtitleChangedScene11_1) {
            nextSubstitleScene11DelayCounter++;
            if (nextSubstitleScene11DelayCounter >= nextSubtitleScene11DelayDuration) {
                subtitle.setText("Move using the arrow keys, then press \"H\" to give her a hug!");
            }
        }

        float posXDiff = abs(girl.getPosX() - mother.getPosX());
        float posYDiff = abs(girl.getPosY() - mother.getPosY());

        if ((currentGirlState == LITTLE_GIRL_HUG) && (posXDiff > 40.0f || posYDiff > 40.0f) && !isSubtitleChangedScene11_2) {
            subtitle.setText("Move closer!");
            isSubtitleChangedScene11_1 = true;
        }
        else if ((currentGirlState == LITTLE_GIRL_HUG) && (posXDiff <= 40.0f && posYDiff <= 40.0f)) {
            subtitle.setText("You have reunited the girl and her mother!");
            isSubtitleChangedScene11_1 = true;
            isSubtitleChangedScene11_2 = true;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateNextSubtitleScene11, 0);
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
    glutSpecialFunc(handleKeypressScene11);
    glutSpecialUpFunc(handleSpecialKeyRelease);
    glutKeyboardFunc(handleNormalKeyPress);
    glutKeyboardUpFunc(handleKeyRelease);

    glutTimerFunc(100, totoroTimer, 0);
    portal.startTimer();
    glutTimerFunc(1000, changeGirlStateAfterDelay, 0);
    glutTimerFunc(1000, changeGirlStateAfterDelay, 1);
    glutTimerFunc(16, updateScene, 0);
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
    glutTimerFunc(30, updateCatbusFrame, 0);
    glutTimerFunc(16, updateCatbusPickup, 0);
    glutTimerFunc(16, updateCatbusEnterPortal, 0);
    glutTimerFunc(16, updatePortalActivationScene4, 0);
    glutTimerFunc(16, updatePortalDeactivationScene4, 0);
    glutTimerFunc(16, updatePortalActivationScene9, 0);
    glutTimerFunc(16, updatePortalDeactivationScene9, 0);
    glutTimerFunc(16, updatePortalActivationScene10, 0);
    glutTimerFunc(16, updateCatbusExitPortal, 0);
    glutTimerFunc(16, updatePortalDeactivationScene10, 0);
    glutTimerFunc(16, infiniteBackgroundScrollingScene5, 0);
    glutTimerFunc(delay, updateSunset, 0);
    glutTimerFunc(16, infiniteBackgroundScrollingScene8Half, 0);
    glutTimerFunc(16, updateCatbusFastForwardTimer, 0);
    glutTimerFunc(16, updateCatbusDropOff, 0);
    glutTimerFunc(16, updateMotherGivingHugDelay, 0);

    glutTimerFunc(16, updateNextSubtitleScene1, 0);
    glutTimerFunc(16, updateNextSubtitleScene3, 0);
    glutTimerFunc(16, updateNextSubtitleScene4, 0);
    glutTimerFunc(16, updateNextSubtitleScene5, 0);
    glutTimerFunc(16, updateNextSubtitleScene6, 0);
    glutTimerFunc(16, updateNextSubtitleScene8, 0);
    glutTimerFunc(16, updateNextSubtitleScene8Half, 0);
    glutTimerFunc(16, updateNextSubtitleScene11, 0);

    glutFullScreen();
    glutMainLoop();
    
    return 0;
}