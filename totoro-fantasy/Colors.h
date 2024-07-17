#pragma once
#include "Color.h"

class Colors
{
public:
    static const Color DAY_CLOUD;
    static const Color DAY_DARK_CLOUD;
    static const Color NIGHT_CLOUD;
    static const Color NIGHT_DARK_CLOUD;
  
    static const Color DAY_SUN;
    static const Color NIGHT_FULL_MOON;
    static const Color MUSHROOM_1;
    static const Color TREE_STEM;
  
    static const Color ROCK;
    static const Color GRASS_DAY;
    static const Color GRASS_NIGHT;

    static const Color RAINBOW;

    static const Color ISLAND_DAY;
    static const Color ISLAND_NIGHT;
};

const Color Colors::DAY_CLOUD{ 0.75f, 0.85f, 1.0f };
const Color Colors::DAY_DARK_CLOUD{ 0.4f, 0.45f, 0.5f };
const Color Colors::NIGHT_CLOUD{ 0.1f, 0.2f, 0.3f };
const Color Colors::NIGHT_DARK_CLOUD{ 0.05f, 0.1f, 0.15f };
const Color Colors::DAY_SUN{ 1.0f, 1.0f, 0.0f };
const Color Colors::NIGHT_FULL_MOON{ 0.8f, 0.8f, 0.8f };
const Color Colors::TREE_STEM{ 0.33f, 0.27f, 0.27f };
const Color Colors::MUSHROOM_1{ 0.82f, 0.15f, 0.24f };

const Color Colors::ROCK{ 0.37f, 0.38f, 0.38f };

const Color Colors::GRASS_DAY{ 0.67, 0.97, 0.5 };
const Color Colors::GRASS_NIGHT{ 0.39, 0.64, 0.24 };

const Color Colors::RAINBOW{ 0, 0 ,0 };

const Color Colors::ISLAND_DAY{ 0.67, 0.97, 0.5 };
const Color Colors::ISLAND_NIGHT{ 0.39, 0.64, 0.24 };

// Define colors here