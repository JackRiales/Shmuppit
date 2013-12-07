
#ifndef OBM__H
#define OBM__H

/**
    Object Management Class
    Stores vectors of all objects
    Creates and destroys as needed in the main game loop
**/

#include "player.hpp"
#include "enemy.hpp"
#include "global.hpp"

class ObjectManager
{
private:
    std::vector<Player>     PlayerGroup;
    std::vector<Enemy>      EnemyGroup;
    GlobalController        Global;

    // Clock used for enemy creation
    sf::Clock               enemy_create;
public:
                            ObjectManager(){PlayerGroup.resize(1);
                                            EnemyGroup.resize(1);
                                            EnemyGroup[0].SetCoord(-100, 0);}
                            ~ObjectManager(){}

    // Return given index of an object vector
    Player*                 GetPlayerIndex(int index)   { return &PlayerGroup[index]; }
    Enemy*                  GetEnemyIndex(int index)    { return &EnemyGroup[index]; }
    GlobalController*       GetGlobalController()       { return &Global; }

    // Return Object Vectors
    std::vector<Player>*    GetPlayerGroup()            { return &PlayerGroup; }
    std::vector<Enemy>*     GetEnemyGroup()             { return &EnemyGroup; }

    // Check for enemy creation
    void                    CheckForPlayerDeath()       { for(unsigned int i = 0; i < PlayerGroup.size(); i++)
                                                            {
                                                                for(unsigned int i2 = 0; i2 < EnemyGroup.size(); i2++)
                                                                {
                                                                    if(PlayerGroup[i].GetSprite()->getGlobalBounds().intersects(EnemyGroup[i2].GetSprite()->getGlobalBounds())){
                                                                        PlayerGroup.erase(PlayerGroup.begin()+i);
                                                                        Global.SetGameOver(true);
                                                                    }
                                                                }
                                                            }
                                                        }
    void                    CheckForEnemyCreate()       { if(enemy_create.getElapsedTime() > sf::milliseconds(500))
                                                            {
                                                                int willThereBeEnemy = rand()%10;
                                                                if(willThereBeEnemy >= 4)
                                                                    EnemyGroup.resize(EnemyGroup.size()+1);
                                                                enemy_create.restart();
                                                            }
                                                        }
    void                    CheckForEnemyDeath(sound& hit)
                                                        {   for(unsigned int i = 0; i < EnemyGroup.size(); i++)
                                                            {
                                                                for(unsigned int i2 = 0; i2 < PlayerGroup.size(); i2++)
                                                                {
                                                                    if(EnemyGroup[i].isHit(PlayerGroup[i2], hit))
                                                                        EnemyGroup.erase(EnemyGroup.begin()+i);
                                                                }
                                                            }
                                                        }
};

#endif // OBM__H
