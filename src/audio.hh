#ifndef AUDIO_HH
#define AUDIO_HH

#include "internos.hh"

class Audio {
private:
    Mix_Chunk* self;

public:
    Audio(const char* path);
    ~Audio();
    void start(int vezes);
    void pause();
    void play();
    void next();
    void prev();
};

#endif
