#ifndef PLAYER__HPP
#define PLAYER__HPP

#include "enemy.hpp"
#include "bullet.hpp"

class Enemy;

enum playerstate{
                IDLE,
                MOVEUP,
                MOVEDOWN,
                };

class Player: public Object
{
private:
    playerstate         state;
    bullettype          shot;
    std::vector<Bullet> vct_bullet;
    sound               snd_shoot;
    double              bulletSpeed;
    bool                canShoot;
    bool                dead;
    int                 hp;
    intrect             spr1,
                        spr2;
public:
    Player();
    ~Player();

    void                Init(System& system, texture& tx, sound_buffer& shoot);
    void                Shoot(texture& tx);
    void                CheckState();
    void                CheckForBulletDestruction(Enemy* enemy);
    void                SetDead(const bool& isDead);
    void                update(System& system, GraphicsManager& gfxm);

    // Return Instance and Private values
    playerstate*        GetState()                          { return &state; }
    std::vector<Bullet>*GetBulletGroup()                    { return &vct_bullet; }
    Bullet*             GetBulletIndex(unsigned int index)  { return &vct_bullet[index]; }
    bullettype          GetShotType()                       { return shot; }
    int                 GetHP()                             { return hp; }
    double              GetBulletSpeed()                    { return bulletSpeed; }
    bool                canFire()                           { return canShoot; }
    bool                isDead()                            { return dead; }

};

#endif // PLAYER__HPP

