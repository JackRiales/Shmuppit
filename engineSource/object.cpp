
#include "object.hpp"

/** SPRITE FUNCTIONS **/

// CREATE A SPRITE AND ASSIGN IT TO THE GIVEN TEXTURE /////////
void Object::CreateSprite(texture& tx, intrect& rect)
{
    spr.setTexture(tx);
    spr.setTextureRect(rect);
}
///////////////////////////////////////////////////////////////

// SET THE OBJECT'S SPRITE RESOLUTION /////////////////////////
void Object::SetResolution(unsigned int w, unsigned int h)
{
    res.w = w;
    res.h = h;
}
///////////////////////////////////////////////////////////////

// CENTERS THE SPRITES ORIGIN POINT ///////////////////////////
void Object::CenterOrigin()
{
    spr.setOrigin(res.w/2, res.h/2);
}
///////////////////////////////////////////////////////////////

// ASSIGN A NEW TEXTURE TO THE OBJECT'S SPRITE ////////////////
void Object::ChangeTexture(texture& newtex, bool resetSize)
{
    spr.setTexture(newtex, resetSize);
}
///////////////////////////////////////////////////////////////

// SET THE OBJECT'S SPRITE TO A NEW FRAME /////////////////////
void Object::ChangeFrame(intrect frame)
{
    spr.setTextureRect(frame);
}
///////////////////////////////////////////////////////////////

// SET THE OBJECT'S TRANSPARENCY TO A VALUE BETWEEN 0 AND 255 /
void Object::SetTransparency(int transparency)
{
    spr.setColor(sf::Color(255, 255, 255, transparency));
}
///////////////////////////////////////////////////////////////

/***************************************************************/

/** MOVEMENT AND DISPLACEMENT FUNCTIONS **/

// SET THE COORDINATE OF THE OBJECT IN A SINGLE FRAME /////////
void Object::SetCoord(float x, float y)
{
    spr.setPosition(x, y);
}
///////////////////////////////////////////////////////////////

// SET THE SPEED //////////////////////////////////////////////
void Object::SetSpeed(float speed_x, float speed_y)
{
    hspeed = speed_x;
    vspeed = speed_y;
}
///////////////////////////////////////////////////////////////

// DETECTS IF THE SPRITE IS BEYOND THE BORDER OF THE SCREEN ///
// AND HANDLES THE EFFECT /////////////////////////////////////
void Object::BorderCollision(System& system)
{
    if(spr.getPosition().x < 16)
        SetCoord(16, spr.getPosition().y);
    else if(spr.getPosition().x > system.GetRes().w-16)
        SetCoord(system.GetRes().w-16, spr.getPosition().y);

    if(spr.getPosition().y < 16)
        SetCoord(spr.getPosition().x, 16);
    else if(spr.getPosition().y > system.GetRes().h-16)
        SetCoord(spr.getPosition().x, system.GetRes().h-16);
}
///////////////////////////////////////////////////////////////

// MOVE AN OBJECT ACROSS THE PLANE AT A GIVEN SPEED ///////////
void Object::move(float speed_x, float speed_y)
{
    spr.move(speed_x, speed_y);
}
///////////////////////////////////////////////////////////////

// ROTATES AN OBJECT TO AN ANGLE //////////////////////////////
// CENTER THE ORIGIN BEFORE USE ///////////////////////////////
void Object::rotate(float angle)
{
    spr.rotate(angle);
}
///////////////////////////////////////////////////////////////

// MOVE WITH AN INCREASING OR DECREASING MOVE RANGE ///////////
// WILL BY DEFAULT INCREASE SPEED, CHECKS IF DECREASING WITH //
// BOOLEAN ////////////////////////////////////////////////////
void Object::MoveIncremental(float min_x, float max_x, float min_y, float max_y, float howFast_x, float howFast_y, bool isDecreasing)
{
    if(!isDecreasing)
    {
        for(int x = min_x; x < max_x; x += howFast_x)
        {
            for(int y = min_y; y < max_x; y += howFast_y)
            {
                move(x,y);
            }
        }
    }
    else
    {
        for(int x = min_x; x > max_x; x -= howFast_x)
        {
            for(int y = min_y; y > max_y; y -= howFast_y)
            {
                move(x,y);
            }
        }
    }
}
///////////////////////////////////////////////////////////////

/************************************************************************/

// RETURNS IF AN OBJECT IS IN COLLISION WITH ANOTHER OBJECT ///
bool Object::collide(Object& objector)
{
    if(spr.getGlobalBounds().intersects(objector.GetSprite()->getGlobalBounds()))
        return true;
    else
        return false;
}
///////////////////////////////////////////////////////////////

// DRAWS THE SPRITE TO THE SCREEN, SHOULD BE CALLED LAST //////
void Object::drawToScreen(sf::RenderWindow& window)
{
    window.draw(spr);
}
///////////////////////////////////////////////////////////////
