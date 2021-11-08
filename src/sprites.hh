#ifndef SPRITES_HH
    #define SPRITES_HH

#include "internos.hh"
#include "sistema.hh"

class Sprites {
    private:
        friend class Personagem;
        int wpos, hpos, animw, animh;
        int frameTime;
        bool is_visible, is_flipped, is_animate;
        double angle;
        SDL_Surface* imagem;
        SDL_Rect animacao, posicao;
        SDL_Texture* texturaImage;
        SDL_RendererFlip flip;
        SDL_Point point;

    public:
        Sprites(const char* path, int xframes, int yframes, int width, int height);
        Sprites();
        ~Sprites();
        void renderizar();
        void run_animate();
};

#endif
