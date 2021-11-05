#ifndef ENGINE_HH
    #define ENGINE_HH

#include "internos.hh"
#include "personagem.hh"
#include "sistema.hh"
#include "sprites.hh"
#include "background.hh"
#include "audio.hh"
#include "fonte.hh"

class Engine {
    public:
        void running();
        ~Engine();
        Engine();

    private:
        Systema* game;
        Background* bg;
        Sprites* sprite_one;
        Personagem* player_one;
        Fonte* fonte;
        Audio* som;

    private:
        void inputs();
        void code();
        void renderizadores();
        void objetos();
        void tela_menu();
        void tela_jogo();
	    void tela_end();

    private:
        int opt{1};
        enum direcoes { up=3, down=4, left=2, right=1, stop=5};
        direcoes diretion;
        string contador_fps;
        int frameCount, startTime;
};

#endif // ENGINE_H
