#ifndef SFXM__HPP
#define SFXM__HPP

#include "system.hpp"

/**
    Sound Management Class
    Holds music and sound files
**/

class SoundManager
{
private:
    sound_buffer    sfx_shoot;
    sound_buffer    sfx_hit;
    sound_buffer    sfx_kill;

    sound           hit;
public:
    void            LoadAll();

                    SoundManager()      { LoadAll(); }
                    ~SoundManager()     { /** Keep void **/ }

    sound_buffer&   GetShootBuffer()    { return sfx_shoot;}
    sound_buffer&   GetHitBuffer()      { return sfx_hit;  }
    sound_buffer&   GetKillBuffer()     { return sfx_kill; }
    sound&          GetHitSound()       { return hit;       }
};


#endif // SFXM__HPP
