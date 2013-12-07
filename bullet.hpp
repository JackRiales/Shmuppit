#ifndef BULLET__HPP
#define BULLET__HPP

#include "engineSource/AI.hpp"

enum bullettype {
                STRAIGHT,
                WAVY
                };

class Bullet: public AI
{
private:
    intrect bullrect;
    bool    active;
public:
    Bullet();
    ~Bullet(){}

    void init(texture& tx);
    void behavior(bullettype tp, double bulletSpeed);
    void CheckIfDestroyed(Object* object);

    bool&   isActive()      { return active; }
};

#endif // BULLET__HPP
