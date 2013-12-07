
#ifndef SYSTEM__HPP
#define SYSTEM__HPP

/// DEFINITION MACROS //////////////////////////////////////////
#define PI      3.14159265359
/// ////////////////////////////////////////////////////////////

/// INCLUSION MACROS //////////////////////////////////////////
#include <SFML/Graphics.hpp>    // SFML Graphics Library
#include <SFML/Audio.hpp>       // SFML Audio Library
#include <windows.h>            // Used for any windows-based functions
#include <fstream>              // Streams used to create and write/read text files
#include <sstream>              // String streams used for variable-string conversion
#include <cmath>                // Used for advanced math functions
#include <ctime>                // Used to gather time-based info (used for random seed)
/// ///////////////////////////////////////////////////////////

using namespace std;

/// REDEFINITION OF SFML OBJECT TYPES /////////////////////////
typedef sf::Texture         texture;
typedef sf::Sprite          sprite;
typedef sf::SoundBuffer     sound_buffer;
typedef sf::Sound           sound;
typedef sf::Music           bgm;
typedef sf::IntRect         intrect;
typedef sf::Font            font;
typedef sf::Text            text;
typedef sf::CircleShape     circle;
typedef sf::RectangleShape  rectangle;
/// ///////////////////////////////////////////////////////////

/// STRUCT DEFINITIONS ////////////////////////////////////////
struct resolution
{
    unsigned int w;
    unsigned int h;
};

struct coordinate
{
    float x;
    float y;
};
/// ///////////////////////////////////////////////////////////

/// ENUMERATION STATE DECLARATIONS ////////////////////////////

enum difficulty {   EASY,
                    MEDIUM,
                    HARD,
                    LUDICROUS};

enum gamestate  {   SPLASH,
                    TITLE,
                    MENU,
                    GAME,
                    PAUSE,
                    EXIT    };

/// ///////////////////////////////////////////////////////////

/**
    System class
        Creates and runs window
        Deletes window and closes program when it is called
**/

class System
{
private:

    sf::RenderWindow    window;
    sf::Event           event;
    resolution          windowres;
    unsigned int        color_depth;
    string              wincaption;
    bool                fullscreen;

public:

    System();
    ~System(){}

    // Changes the resolution, refreshes the window
    void                changeResolution(unsigned int w, unsigned int h);

    // Returns the resolution
    resolution          GetRes()       { return windowres; }

    // Toggles fullscreen, refreshes the window
    void                changeFullscreen();

    // Sets the vertical sync -- keeps the framerate stable
    void                setFrameRate()  { window.setVerticalSyncEnabled(true); }

    // Return the WINDOW and EVENT for use in GAME
    sf::RenderWindow&   GetWindow()    { return window; }
    sf::Event&          GetEvent()     { return event; }

    /** Debug Only **/

    // Runs a window
    void runWindow();

};

/** Global Debug Functions **/
void callFailure();

#endif // SYSTEM__HPP

