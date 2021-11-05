#include "audio.hh"

Audio::Audio(const char* path){
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    self = Mix_LoadWAV(path);
}

void Audio::start(int vezes){
    Mix_PlayChannel(-1, self, vezes);
}

void Audio::pause(){
    Mix_Pause(-1);
}

Audio::~Audio(){
    Mix_CloseAudio();
    Mix_FreeChunk(self);
}
