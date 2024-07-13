#pragma once
#include "Color.h"

class Colors
{
public:
    static const Color DAY_CLOUD;
    static const Color DAY_DARK_CLOUD;
    static const Color NIGHT_CLOUD;
    static const Color NIGHT_DARK_CLOUD;
};

const Color Colors::DAY_CLOUD{ 0.75f, 0.85f, 1.0f };
const Color Colors::DAY_DARK_CLOUD{ 0.4f, 0.45f, 0.5f };
const Color Colors::NIGHT_CLOUD{ 0.1f, 0.2f, 0.3f };
const Color Colors::NIGHT_DARK_CLOUD{ 0.05f, 0.1f, 0.15f };


// Define colors here