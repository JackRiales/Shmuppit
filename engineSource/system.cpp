
#include "system.hpp"

// UPON CREATION ////////////////////////////////////////
System::System()
{
    windowres.w     = 800;          // Change as you wish for a game
    windowres.h     = 600;          // ^
    color_depth     = 32;           // ^
    wincaption      = "Shmuppit";   // Title bar string

    fullscreen      = false;        // Avoid

    window.create(sf::VideoMode(windowres.w,windowres.h,color_depth), wincaption, sf::Style::Close);
    setFrameRate();
}
//////////////////////////////////////////////////////////

// CHANGE RESOLUTION TO THE GIVEN VALUES /////////////////
void System::changeResolution(unsigned int w, unsigned int h)
{
    windowres.w = w;
    windowres.h = h;

    if(!fullscreen)
        window.create(sf::VideoMode(windowres.w,windowres.h,color_depth), wincaption, sf::Style::Close);
    else
        window.create(sf::VideoMode(windowres.w,windowres.h,color_depth), wincaption, sf::Style::Fullscreen);
}
///////////////////////////////////////////////////////////

// TOGGLE THE FULLSCREEN //////////////////////////////////
void System::changeFullscreen()
{
    switch(fullscreen)
    {
    case(true):
        fullscreen = false;
        window.create(sf::VideoMode(windowres.w,windowres.h,color_depth), wincaption, sf::Style::Close);
    case(false):
        fullscreen = true;
        window.create(sf::VideoMode(windowres.w,windowres.h,color_depth), wincaption, sf::Style::Fullscreen);
    }
}
////////////////////////////////////////////////////////////

/********************************* Debug Only ***************************************/

// Opens and runs a window
void System::runWindow()
{
    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                window.close();
        }
        window.clear(sf::Color(155,155,155));
        window.display();
    }
}

// Calls a failure prompt, called when something fails to initialize
// Requires windows header library
void callFailure()
{ MessageBox(NULL, "Error Failure -- Please Debug", NULL, MB_OK); }

/**************************************************************************************/
