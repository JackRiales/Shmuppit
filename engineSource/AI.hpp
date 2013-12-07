
#ifndef AI__HPP
#define AI__HPP

#include "object.hpp"

class AI: public Object
{
private:
    bool        destroyed;
public:
    /* Path Functions -- Automatic Movement Based on X position*/
    float       pth_line(float x, float slope);
    float       pth_abs(float x);
    float       pth_log(float x);
    float       pth_sin(float x, float amplitude, float wavelength);
    float       pth_cos(float x, float amplitude, float wavelength);

    /* Manipulators */
    float       mp_pth_inverse(float y);

    /// Check for destroyed / Set destroyed
    bool&       isDestroyed();
    void        SetDestroyed(const bool& dst);
};

#endif // AI__H
