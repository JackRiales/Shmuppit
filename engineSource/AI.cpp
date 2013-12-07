
#include "AI.hpp"


/** Pathing **/

// Regular line based on slope
float AI::pth_line(float x, float slope)
{
    float y;
    y = slope * x;
    return y;
}

// Absolute Value function
float AI::pth_abs(float x)
{
    float y;
    y = abs(x);
    return y;
}

// Logarithmic function
float AI::pth_log(float x)
{
    float y;
    y = log(x);
    return y;
}

// Sine wave path, takes in amplitude and wavelength values
float AI::pth_sin(float x, float amplitude, float wavelength)
{
    float y;
    y = amplitude * sin(x / (PI / 2 * wavelength));
    return y;
}
// Cosine wave
float AI::pth_cos(float x, float amplitude, float wavelength)
{
    float y;
    y = amplitude * cos(x / (PI / 2 * wavelength));
    return y;
}

/*************/

/** Manipulators **/

float AI::mp_pth_inverse(float y)
{
    return y * -1;
}

/*************/

/// Destruction Functions

bool& AI::isDestroyed()
{
    return destroyed;
}

void AI::SetDestroyed(const bool& dst)
{
    destroyed = dst;
}
