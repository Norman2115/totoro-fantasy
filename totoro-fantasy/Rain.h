#include <GL/glut.h>
#include <cstdlib>
#include <ctime>

class Rain {
private:
    struct RainDroplet {
        float x, y;
        float speed;
    };

    RainDroplet* droplets;
    int numDroplets;

public:
    Rain(int numDroplets) : numDroplets(numDroplets) {
        droplets = new RainDroplet[numDroplets];
        initRain();
    }

    ~Rain() {
        delete[] droplets;
    }

    void initRain() {
        srand(static_cast<unsigned>(time(0)));
        for (int i = 0; i < numDroplets; ++i) {
            droplets[i].x = static_cast<float>(rand() % 1920); // Range: 0 to 1919
            droplets[i].y = static_cast<float>(rand() % 1080); // Range: 0 to 1079
            droplets[i].speed = static_cast<float>((rand() % 50) + 50); // Speed: 50 to 100
        }
    }

    void updateRain() {
        for (int i = 0; i < numDroplets; ++i) {
            droplets[i].y -= droplets[i].speed * 0.03f; // Update position based on speed
            if (droplets[i].y < 0) {
                droplets[i].y = 1080; // Reset to the top if it goes off the bottom
                droplets[i].x = static_cast<float>(rand() % 1920); // Randomize x position again
            }
        }
    }

    void renderRain() {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glColor4f(0.0f, 0.0f, 1.0f, 0.5f); // Blue color with 50% opacity for rain
        glPushAttrib(GL_LINE_BIT);
        glLineWidth(3);
        glBegin(GL_LINES);
        for (int i = 0; i < numDroplets; ++i) {
            glVertex2f(droplets[i].x, droplets[i].y);
            glVertex2f(droplets[i].x, droplets[i].y - 10); // Draw a line segment
        }
        glEnd();
        glPopAttrib();
        glDisable(GL_BLEND);
    }
};
