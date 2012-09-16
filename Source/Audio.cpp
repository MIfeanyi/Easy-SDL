#include "Audio.hpp"

Audio::Audio()
{
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096);
    Sfx = NULL;
    Song = NULL;
    Playing = false;
}

Audio::Audio(string filename, int type)
{
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096);
    Playing = false;
    Sfx = NULL;
    Song = NULL;
    Load(filename, type);
}

void Audio::Load(string filename, int type)
{

    switch(type)
    {
    case MUSIC:
        Song = Mix_LoadMUS( filename.c_str() );
        break;
    case SFX:
        Sfx = Mix_LoadWAV( filename.c_str() );
        break;
    default:
        break;

    };
}

void Audio::PlaySong(int loop)
{
    Mix_PlayMusic(Song,loop);
}

void Audio::PlaySfx()
{
    Mix_PlayChannel( -1, Sfx, 0 );
}

void Audio::StopSong()
{
    Mix_HaltMusic();
}
Audio::~Audio()
{

    //Mix_FreeMusic(Sfx);
    Mix_CloseAudio();
}
