
#include "game.hpp"

void Game::initAll()
{
    for(unsigned int i = 0; i < obm.GetPlayerGroup()->size(); i++)
        obm.GetPlayerIndex(i)->Init(system, gfxm.GetPlayerTex(), sfxm.GetShootBuffer());
    background.setTexture(gfxm.GetBackgroundTex());
}

void Game::run()
{
    initAll();
    obm.GetGlobalController()->PlayBGM();
    while(system.GetWindow().isOpen())
    {
        while(system.GetWindow().pollEvent(system.GetEvent()))
        {
            if(system.GetEvent().type == sf::Event::Closed || system.GetEvent().key.code == sf::Keyboard::Escape)
                system.GetWindow().close();
            if(system.GetEvent().key.code == sf::Keyboard::F1)
                system.changeFullscreen();
        }

        /// CLEAR THE SCREEN FOR DRAW
        system.GetWindow().clear(sf::Color::Black);

        /// Background Block ///////////////////////////////////////////////////
        system.GetWindow().draw(background);
        /// ////////////////////////////////////////////////////////////////////

        /// Player Block ///////////////////////////////////////////////////////
        for(unsigned int i = 0; i < obm.GetPlayerGroup()->size(); i++)
        {
            obm.GetPlayerIndex(i)->CheckState();
            obm.GetPlayerIndex(i)->update(system, gfxm);
            obm.GetPlayerIndex(i)->drawToScreen(system.GetWindow());
            for(unsigned int i2 = 0; i2 < obm.GetEnemyGroup()->size(); i2++)
            {
                obm.GetPlayerIndex(i)->CheckForBulletDestruction(obm.GetEnemyIndex(i2));
            }
        }
        obm.CheckForPlayerDeath();
        /// /////////////////////////////////////////////////////////////////////

        /// Enemy Block ////////////////////////////////////////////////////////
        obm.CheckForEnemyCreate();
        for(unsigned int i = 0; i < obm.GetEnemyGroup()->size(); i++)
        {
            if(!obm.GetEnemyIndex(i)->GetSprite()->getTexture())
                obm.GetEnemyIndex(i)->init(system, gfxm);
            obm.GetEnemyIndex(i)->behavior();
            obm.GetEnemyIndex(i)->drawToScreen(system.GetWindow());
        }
        obm.CheckForEnemyDeath(sfxm.GetHitSound());
        /// ////////////////////////////////////////////////////////////////////

        /// Bullet Block ///////////////////////////////////////////////////////
        for(unsigned int i = 0; i < obm.GetPlayerGroup()->size(); i++)
        {
            for(unsigned int i2 = 0; i2 < obm.GetPlayerIndex(i)->GetBulletGroup()->size(); i2++)
            {
                obm.GetPlayerIndex(i)->GetBulletIndex(i2)->behavior(obm.GetPlayerIndex(i)->GetShotType(),
                                                                    obm.GetPlayerIndex(i)->GetBulletSpeed());
                obm.GetPlayerIndex(i)->GetBulletIndex(i2)->drawToScreen(system.GetWindow());
            }
        }
        /// ////////////////////////////////////////////////////////////////////

        /// Global Block ///////////////////////////////////////////////////////
        obm.GetGlobalController()->GameOver(system, gfxm.GetGlobalFont());
        if(obm.GetGlobalController()->isGameOver())
            system.GetWindow().draw(obm.GetGlobalController()->GetGameOverText());
        /// ////////////////////////////////////////////////////////////////////

        /// DISPLAY THE IMAGE TO THE SCREEN
        system.GetWindow().display();
    }
}
