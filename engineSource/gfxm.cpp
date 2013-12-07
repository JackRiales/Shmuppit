#include "gfxm.hpp"

void GraphicsManager::LoadAll()
{
    /// Textures
    if(!tx_player.loadFromFile("asset/textures/spr_puppet.png"))
        callFailure();
    if(!tx_bullet.loadFromFile("asset/textures/spr_bullet.png"))
        callFailure();
    if(!tx_background.loadFromFile("asset/textures/bg_space.png"))
        callFailure();

    if(!tx_airsac.loadFromFile("asset/textures/spr_airsac.png"))
        callFailure();
    if(!tx_blimp.loadFromFile("asset/textures/spr_blimp.png"))
        callFailure();

    /// Fonts
    if(!ft_global.loadFromFile("asset/ft/digital.ttf"))
        callFailure();
}
