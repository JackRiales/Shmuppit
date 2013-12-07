#ifndef GAME__HPP
#define GAME__HPP

#include "engineSource\gfxm.hpp"
#include "engineSource\sfxm.hpp"
#include "obm.hpp"

class Game
{
private:
    System          system;
    ObjectManager   obm;
    GraphicsManager gfxm;
    SoundManager    sfxm;

    sprite background;
public:
    void    initAll();
    void    run();
};

#endif // GAME__HPP
