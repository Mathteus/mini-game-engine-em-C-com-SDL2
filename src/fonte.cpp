#include "fonte.hh"

Fonte::Fonte(const char* pt, const char* txt, int size, int xpos, int ypos) : visible(true) {
    path = pt; texto_g = txt;
    font = TTF_OpenFont(path, size);
    cor_font = {255,255,255,255};
    surtext = TTF_RenderText_Solid(font, txt, cor_font);
    text = SDL_CreateTextureFromSurface(Systema::get_renderer(), surtext);
    local_txt = {xpos, ypos, 0, 0};
    SDL_QueryTexture(text, NULL, NULL, &local_txt.w, &local_txt.h);
}

void Fonte::cor_fonte(Uint8 r, Uint8 g, Uint8 b, Uint8 a){
    const char* txt = strcpy((char *) malloc(texto_g.length () + 1), texto_g.c_str ());
    cor_font = {r,g,b,a};
    surtext = TTF_RenderText_Solid(font, txt, cor_font);
    text = SDL_CreateTextureFromSurface(Systema::get_renderer(), surtext);
    //free(txt);
}

void Fonte::poisicao(int xpos, int ypos){
    local_txt = {xpos, ypos, 0, 0};
    SDL_QueryTexture(text, NULL, NULL, &local_txt.w, &local_txt.h);
}

void Fonte::renderizar(){
    if(visible)
        SDL_RenderCopy(Systema::get_renderer(), text, NULL, &local_txt);
}

void Fonte::size(int fsize){
    const char* txt = strcpy((char *) malloc(texto_g.length () + 1), texto_g.c_str ());
    font = TTF_OpenFont(path, fsize);
    surtext = TTF_RenderText_Solid(font, txt, cor_font);
    text = SDL_CreateTextureFromSurface(Systema::get_renderer(), surtext);
    //free(txt);
}

void Fonte::texto(const char* texto){
    texto_g = texto;
    surtext = TTF_RenderText_Solid(font, texto, cor_font);
    text = SDL_CreateTextureFromSurface(Systema::get_renderer(), surtext);
}

void Fonte::set_visible(bool visivel){
    visible = visivel;
}

bool Fonte::get_visible(){
    return visible;
}

Fonte::~Fonte(){
    TTF_CloseFont(font);
    SDL_DestroyTexture(text);
    delete path;
}
