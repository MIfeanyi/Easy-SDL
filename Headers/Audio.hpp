#ifndef AUDIO_H
#define AUDIO_H

#include<string>
#include <SDL/SDL.h>
#include<SDL/SDL_mixer.h>

using namespace std;

enum AudioType
{
    MUSIC = 0,
    SFX
};

class Audio
{
public:
    /** Default constructor */
    Audio();
    Audio(string filename, int type);
    void PlaySong(int loop);
    void StopSong();
    void Load(string filename, int type);
    void PlaySfx();

    bool Playing;
    /** Default destructor */
    virtual ~Audio();
protected:

    Mix_Music *Song;
    Mix_Chunk *Sfx;

private:
};

#endif // AUDIO_H
