#include "player.hpp"

Player::Player(){}
Player::~Player(){}

void Player::Init(System& system, texture& tx, sound_buffer& shoot)
{
    SetResolution( 32, 32 );
    SetSpeed( 1, 2 );
    CenterOrigin();
    canShoot = true;

    spr1.top    = 0;
    spr1.left   = 0;
    spr1.width  = GetResolution().w;
    spr1.height = GetResolution().h;
    spr2.top    = 0;
    spr2.left   = 0;
    spr2.width  = GetResolution().w;
    spr2.height = GetResolution().h;

    // Variable definitions
    hp          = 100;
    bulletSpeed = 5;
    state       = IDLE;
    shot        = STRAIGHT;

    // Create the bullet prototype and keep it off-screen
    vct_bullet.resize(1);
    vct_bullet[0].SetCoord( -100, 0 );

    // Create the player sprite and initialize his position
    CreateSprite(tx, spr1);
    SetCoord( GetResolution().w, (system.GetRes().h)/2);

    // Initialize the shoot sound with the sound buffer
    snd_shoot.setBuffer(shoot);
    snd_shoot.setLoop(false);
    snd_shoot.stop();
}

void Player::Shoot(texture& tx)
{
    vct_bullet.resize(vct_bullet.size()+1);
    vct_bullet[vct_bullet.size()-1].init(tx);
    vct_bullet[vct_bullet.size()-1].SetCoord( GetSprite()->getPosition().x, GetSprite()->getPosition().y );
}

void Player::CheckState()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        state = MOVEUP;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        state = MOVEDOWN;
}

void Player::CheckForBulletDestruction(Enemy* enemy)
{
    for(unsigned int i = 0; i < vct_bullet.size(); i++)
    {
        vct_bullet[i].CheckIfDestroyed(enemy);
        if(vct_bullet[i].isDestroyed())
        {
            vct_bullet.erase(vct_bullet.begin()+i);
        }
    }
}

void Player::SetDead(const bool& isDead)
{
    dead  = isDead;
}

void Player::update(System& system, GraphicsManager& gfxm)
{
    /// MOVEMENT ///
    if(state==MOVEUP)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            move( GetHSpeed()/2, -GetVSpeed() );
        else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
            move( -GetHSpeed()/2, -GetVSpeed() );
        else
            move( 0, -GetVSpeed() );
        BorderCollision(system);
        state   = IDLE;
    }
    else if (state==MOVEDOWN)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            move( GetHSpeed(), GetVSpeed() );
        else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
            move( -GetHSpeed(), GetVSpeed() );
        else
            move( 0, GetVSpeed() );
        BorderCollision(system);
        state   = IDLE;
    }
    else
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            move( GetHSpeed(), 0 );
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            move( -GetHSpeed(), 0 );
        BorderCollision(system);
    }

    /// SHOTS ///
    if(canShoot)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            Shoot(gfxm.GetBulletTex());
            snd_shoot.play();
            canShoot = false;
        }
    }
    else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        canShoot = true;
}
