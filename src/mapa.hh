#ifndef MAPA_HH
#define MAPA_HH

#include "internos.hh"
#include "sistema.hh"

class Mapa {

    private:
        int xpos, ypos, wpos, hpos, animw, animh;
        bool visible;
        SDL_Surface* imagem;
        SDL_Rect animacao, posicao;
        SDL_Texture* texturaImage;
        SDL_Rect camera;

    public:
        Mapa(const char* path, int width, int height);
        ~Mapa();
        void renderizar();
        void set_visible(bool visivel);
        bool get_visible();
        void atualizar_camera(int x, int y, int w, int h);
};

#endif
