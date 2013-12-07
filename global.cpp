#include "global.hpp"

GlobalController::GlobalController()
{
    score = 0;
    gameOverPrompt = false;
}

text    GlobalController::DrawNewText( unsigned int x, unsigned int y, int size, font& textFont, const std::string& textToDraw )
{
    text    newText;
    newText.setFont(textFont);
    newText.setCharacterSize(size);
    newText.setPosition( x, y );
    newText.setString(textToDraw);
    return newText;
}

void    GlobalController::GameOver(System& system, font& gameOverFont)
{
    if(gameOverPrompt)
    {
        gui_gameOverText.setFont(gameOverFont);
        gui_gameOverText.setPosition(system.GetRes().w/2, system.GetRes().h/2);
        gui_gameOverText.setString("GAME OVER");
    }
}

void    GlobalController::PlayBGM()
{
    bgm_background.openFromFile("asset/snd/mus/bgm_background.ogg");
    bgm_background.setVolume(bgm_background.getVolume()/3);
    bgm_background.play();
}
