#ifndef FONTE_HH
    #define FONTE_Hh

#include "internos.hh"
#include "sistema.hh"

class Fonte {
private:
    TTF_Font* font;
    SDL_Color cor_font;
    SDL_Surface* surtext;
    SDL_Texture* text;
    SDL_Rect local_txt;
    const char* path;
    string texto_g;
    bool visible;

public:
    Fonte(const char* pt, const char* texto, int size, int xpos, int ypos);
    ~Fonte();
    void cor_fonte(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void poisicao(int xpos, int ypos);
    void renderizar();
    void size(int fsize);
    void texto(const char* texto);
    void set_visible(bool visivel);
    bool get_visible();
};

#endif
