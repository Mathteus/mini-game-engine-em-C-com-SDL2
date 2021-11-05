#ifndef BACKGROUND_HH
    #define BACKGROUND_HH

#include "internos.hh"
#include "sistema.hh"

class Background {

    private:
        int xpos, ypos, wpos, hpos, animw, animh;
        bool visible;
        SDL_Surface* imagem;
        SDL_Rect animacao, posicao;
        SDL_Texture* texturaImage;

    public:
        Background(const char* path, int width, int height);
        ~Background();
        void renderizar();
        void set_visible(bool visivel);
        bool get_visible();
};

#endif
