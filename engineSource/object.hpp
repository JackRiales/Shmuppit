
#ifndef OBJECT__HPP
#define OBJECT__HPP

#include "gfxm.hpp"

/**
    OBJECT CLASS
    This class is a base that defines functions for all objects in
    the game. Players, bullets, etc will inherit from this class.
**/

class Object
{
private:

    /// Resolution of the object
    resolution  res;

    /// Sprite object
    sprite      spr;

    /// Speed parameters
    float       hspeed;
    float       vspeed;

public:

    /// SPRITE FUNCTIONS /////////////////////////////////////////////////
                void        CreateSprite(texture& tx, intrect& rect);
                void        SetResolution(unsigned int w, unsigned int h);
                void        CenterOrigin();
                void        ChangeTexture(texture& newtex, bool resetSize);
                void        ChangeFrame(intrect frame);
                void        SetTransparency(int transparency);
    /// //////////////////////////////////////////////////////////////////

    /// MOVEMENT FUNCTIONS ///////////////////////////////////////////////
                void        SetCoord(float x, float y);
                void        SetSpeed(float speed_x, float speed_y);
                void        BorderCollision(System& system);
                void        move(float speed_x, float speed_y);
                void        rotate(float angle);
                void        MoveIncremental(float min_x, float max_x, float min_y, float max_y, float howFast_x, float howFast_y, bool isDecreasing);
    /// //////////////////////////////////////////////////////////////////

    /// Returns if this object is colliding with the given object sprite
                bool        collide(Object& objector);

    /// Updates and draws the entity
                void        drawToScreen(sf::RenderWindow& window);

    /// Destroys object
    virtual     void        destroy()       { delete this; }
    virtual     Object*     clone()         { Object* object_clone = this; return object_clone; }

    /// Returns the private values
    virtual     Object*     GetInstance()   { return this; }
                sprite*     GetSprite()     { return &spr; }
                resolution  GetResolution() { return res; }
                float       GetHSpeed()     { return hspeed; }
                float       GetVSpeed()     { return vspeed; }

                Object()                    {}
    virtual     ~Object()                   {}
};

#endif // OBJECT__HPP
