#include "bullet.hpp"

Bullet::Bullet()
{
    bullrect.top    = 0;
    bullrect.left   = 0;
    bullrect.width  = 16;
    bullrect.height = 16;
    active          = false;
    SetDestroyed(false);
}

void Bullet::init(texture& tx)
{
    CreateSprite(tx, bullrect);
    active=true;
}

void Bullet::behavior(bullettype tp, double bulletSpeed)
{
    if(active)
    {
        switch(tp)
        {
            case(STRAIGHT):
                move( bulletSpeed, 0 );
                break;

            case(WAVY):
                move( bulletSpeed, pth_sin( GetSprite()->getPosition().x, 1, 1 ) );
                break;
        }
    }
}

void Bullet::CheckIfDestroyed(Object* object)
{
    if(GetSprite()->getGlobalBounds().intersects(object->GetSprite()->getGlobalBounds()) || GetSprite()->getPosition().x > 1000)
        SetDestroyed(true);
}
