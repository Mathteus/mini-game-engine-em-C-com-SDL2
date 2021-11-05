#include "background.hh"

Background::Background(const char* path, int width, int height) : xpos(0), ypos(0), wpos(0), hpos(0), animw(0), animh(0), visible(true) {
    imagem = IMG_Load(path);
    texturaImage = SDL_CreateTextureFromSurface(Systema::get_renderer(), imagem);
    SDL_QueryTexture(texturaImage, NULL, NULL, &wpos, &hpos);
    animacao.w = wpos; animacao.h = hpos;
    animacao.x = animacao.y = posicao.x = posicao.y = 0;
    posicao.w = width; posicao.h = height;
}

void Background::renderizar() {
    if(visible)
        SDL_RenderCopy(Systema::get_renderer(), texturaImage, NULL, &posicao);
}

void Background::set_visible(bool visivel){
    visible = visivel;
}

bool Background::get_visible(){
    return visible;
}

Background::~Background(){
    SDL_DestroyTexture(texturaImage);
    SDL_FreeSurface(imagem);
}
