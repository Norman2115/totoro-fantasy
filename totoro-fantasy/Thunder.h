#include <vector>
#include <cstdlib>
#include <ctime>
#include "Cloud.h"
#include "Colors.h"
#include "Color.h"
#include <iostream>

class Thunder {
private:
    std::vector<Cloud*> clouds;
    float duration;
    bool isThundering;
    std::clock_t thunderStartTime;

public:
    Thunder(std::vector<Cloud*> clouds, float duration)
        : clouds(clouds), duration(duration), isThundering(false), thunderStartTime(0) {
        std::srand(std::time(nullptr)); // Seed random number generator
    }

    void startThunder() {
        isThundering = true;
        thunderStartTime = std::clock();
    }

    void update() {
        if (isThundering) {
            float currentTime = (std::clock() - thunderStartTime) / (float)CLOCKS_PER_SEC;
            if (currentTime < duration) {
                for (auto cloud : clouds) {
                    float probabilityThreshold = 0.1f;
                    float randomProbability = static_cast<float>(std::rand()) / RAND_MAX;

                    if (randomProbability < probabilityThreshold) {
                        cloud->setColor(Colors::THUNDER_CLOUD);
                    }
                    else {
                        cloud->setColor(cloud->getOriginalColor());
                    }
                }
            }
            else {
                isThundering = false;
                for (auto cloud : clouds) {
                    cloud->setColor(cloud->getOriginalColor());
                }
            }
        }
    }
};