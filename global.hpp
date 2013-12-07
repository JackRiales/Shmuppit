#ifndef GLOBAL__HPP
#define GLOBAL__HPP

#include "engineSource\system.hpp"

class GlobalController
{
private:
    int                 score;
    bool                gameOverPrompt;
    text                gui_scoreText;
    text                gui_gameOverText;
    std::stringstream   gui_str_scoreText;
    bgm                 bgm_background;
public:
    GlobalController();
    ~GlobalController() {}
    ///////////////////////////////////////////////
    text    DrawNewText(unsigned int x, unsigned int y, int size, font& textFont, const std::string& textToDraw);
    void    DrawGUI(System& system);
    ///////////////////////////////////////////////
    void    SetGameOver(bool gameOver)  { gameOverPrompt = gameOver; }
    void    GameOver(System& system, font& gameOverFont);
    ///////////////////////////////////////////////
    void    PlayBGM();
    ///////////////////////////////////////////////
    int     GetScore()                  { return score; }
    bool    isGameOver()                { return gameOverPrompt; }
    text&   GetGameOverText()           { return gui_gameOverText; }
};

#endif // GLOBAL__HPP
