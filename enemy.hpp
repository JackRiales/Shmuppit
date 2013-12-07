#ifndef ENEMY__HPP
#define ENEMY__HPP

#include "engineSource\AI.hpp"
#include "player.hpp"

class Player;

enum enemy_type {
                AIRSAC,
                BLIMP
                };

class Enemy: public AI
{
private:
    unsigned    int         hp;
                float       amplitude,
                            wavelength;
                enemy_type  type;
                intrect     rct_airsac1,
                            rct_airsac2,
                            rct_airsac3,
                            rct_blimp;
public:
                Enemy();
                ~Enemy(){}

    void        init(System& system, GraphicsManager& gfxm);

    bool        isHit(Player& player, sound& hitSound);
    bool        isDead();

    void        behavior();

    /// Return private values
    unsigned int    GetHP()         { return hp; }
    float           GetAmplitude()  { return amplitude; }
    float           GetWavelength() { return wavelength; }
    enemy_type      GetType()       { return type; }
};

#endif // ENEMY__HPP
