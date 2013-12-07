#ifndef GFXM__HPP
#define GFXM__HPP

/**
    Graphics Management Class
    Stores images and textures to be used in objects
**/

#include "system.hpp"

class GraphicsManager
{
private:
    /** Textures **/
    texture     tx_player;
    texture     tx_bullet;
    texture     tx_background;

    /// Enemies
    texture     tx_airsac;
    texture     tx_blimp;

    /** Fonts **/
    font        ft_global;
public:
    void        LoadAll();

                GraphicsManager(){ LoadAll(); }
                ~GraphicsManager(){}

    // Return the address of all textures
    texture&    GetPlayerTex()      { return tx_player; }
    texture&    GetBulletTex()      { return tx_bullet; }
    texture&    GetBackgroundTex()  { return tx_background; }
    texture&    GetAirsacTex()      { return tx_airsac; }
    texture&    GetBlimpTex()       { return tx_blimp; }

    font&       GetGlobalFont()     { return ft_global; }
};

#endif // GFXM__HPP
