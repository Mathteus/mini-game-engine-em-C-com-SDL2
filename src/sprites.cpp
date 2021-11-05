#include "sprites.hh"

Sprites::Sprites() : wpos(0), hpos(0), animw(0), animh(0), frameTime(0), is_animate(false), is_visible(true), flipe(false) {}

Sprites::Sprites(const char* path, int xframes, int yframes, int width, int height) : wpos(0), hpos(0), animw(0), animh(0), frameTime(0), is_animate(false), is_visible(true), flipe(false) {
    imagem = IMG_Load(path);
    texturaImage = SDL_CreateTextureFromSurface(Systema::get_renderer(), imagem);
    SDL_QueryTexture(texturaImage, NULL, NULL, &wpos, &hpos);
    animw = wpos / xframes;  animh = hpos / yframes;
    animacao.w = animw; animacao.h = animh;
    posicao.w = width; posicao.h = height;
    animacao.x = animacao.y = posicao.x = posicao.y = 0;
}

Sprites::~Sprites(){
    SDL_DestroyTexture(texturaImage);
    SDL_FreeSurface(imagem);
}

void Sprites::renderizar() {
    if (is_visible)
        SDL_RenderCopy(Systema::get_renderer(), texturaImage, &animacao, &posicao);
}

void Sprites::run_animate() {
    if (is_animate) {
        frameTime++;
        if (60 / frameTime == 4) {
            if (animacao.x < wpos) {
                frameTime = 0;
                animacao.x += animw;
            }
            if (animacao.x >= wpos) {
                animacao.x = 0;
                animacao.y += animh;
            }
            if (animacao.y >= hpos) {
                animacao.y = 0;
            }
        }
    }
}


