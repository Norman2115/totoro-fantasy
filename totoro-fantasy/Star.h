#pragma once
#include <gl/glut.h>
#include <vector>
#include <ctime>

class Star
{
private:
    static std::vector<std::pair<float, float>> cords;

    static void generate() {
        srand(static_cast<unsigned>(time(0)));

        for (int i = 0; i < 100; ++i) {
            float x = static_cast<float>(rand() % 1920);
            float y = static_cast<float>(rand() % 1080);
            cords.push_back(std::make_pair(x, y));
        }
    }

public:
    static void draw(bool isFantasy = false) {
        if (cords.empty()) {
            generate();
        }

        if (isFantasy) {
            glColor3f(1, 0.11, 0.94);
        }
        else {
            glColor3f(1, 1, 1);
        }

        glPointSize(2.0f);
        glBegin(GL_POINTS);
        for (auto& cord : cords) {
            glVertex2f(cord.first, cord.second);
        }
        glEnd();
    }
};

std::vector<std::pair<float, float>> Star::cords;
