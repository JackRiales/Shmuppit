#include "enemy.hpp"

Enemy::Enemy()
{
    SetSpeed( (float)rand()/(float)RAND_MAX/2, 0 );
    wavelength          = (float)rand()/(float)RAND_MAX+2.2;
    amplitude           = (float)rand()/(float)RAND_MAX+wavelength-3;

    int enemy_seed      = rand()%10;
    if(enemy_seed < 7)
    {
        type = AIRSAC;
        hp = 1;
        SetResolution( 32, 32 );
        rct_airsac1.top     = 0;
        rct_airsac1.left    = 0;
        rct_airsac1.width   = GetResolution().w;
        rct_airsac1.height  = GetResolution().h;
        rct_airsac2.top     = 0;
        rct_airsac2.left    = 32;
        rct_airsac2.width   = GetResolution().w;
        rct_airsac2.height  = GetResolution().h;
        rct_airsac3.top     = 0;
        rct_airsac3.left    = 64;
        rct_airsac3.width   = GetResolution().w;
        rct_airsac3.height  = GetResolution().h;
    }
    else if(enemy_seed >= 7)
    {
        type = BLIMP;
        hp = 3;
        SetResolution( 64, 64 );
        rct_blimp.top       = 0;
        rct_blimp.left      = 0;
        rct_blimp.width     = GetResolution().w;
        rct_blimp.height    = GetResolution().h;
    }
}

void Enemy::init(System& system, GraphicsManager& gfxm)
{
    int sprite_seed = rand()%3;
    switch(type)
    {
    case(AIRSAC):
        switch(sprite_seed)
        {
        case(0):
            CreateSprite(gfxm.GetAirsacTex(), rct_airsac1);
            break;
        case(1):
            CreateSprite(gfxm.GetAirsacTex(), rct_airsac2);
            break;
        case(2):
            CreateSprite(gfxm.GetAirsacTex(), rct_airsac3);
            break;
        }
        break;
    case(BLIMP):
        CreateSprite( gfxm.GetBlimpTex(), rct_blimp );
        break;
    }
    SetCoord( system.GetRes().w+32 , rand()%system.GetRes().h );
}

bool Enemy::isHit(Player& player, sound& hitSound)
{
    for(unsigned int i = 0; i < player.GetBulletGroup()->size(); i++)
    {
        if(GetSprite()->getGlobalBounds().intersects(player.GetBulletIndex(i)->GetSprite()->getGlobalBounds()))
        {
            hitSound.play();
            return true;
        }
    }
    return false;
}

bool Enemy::isDead()
{
    if(hp==0 || GetSprite()->getPosition().x < 0)
        return true;
    else
        return false;
}

void Enemy::behavior()
{
    if(type==AIRSAC)
        move( -GetHSpeed(), pth_sin(GetSprite()->getPosition().x, amplitude, wavelength) );
    else if(type==BLIMP)
        move( -GetHSpeed()/2, 0 );
}
