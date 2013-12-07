#include "sfxm.hpp"

void SoundManager::LoadAll()
{
    if(!sfx_shoot.loadFromFile("asset/snd/sfx/PeaShoot.wav"))
        callFailure();
    if(!sfx_hit.loadFromFile("asset/snd/sfx/Hit.wav"))
        callFailure();
    if(!sfx_kill.loadFromFile("asset/snd/sfx/Kill.wav"))
        callFailure();

    hit.setBuffer(sfx_hit);
    hit.setLoop(false);
    hit.stop();
}
