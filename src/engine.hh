#ifndef ENGINE_HH
    #define ENGINE_HH

#include "internos.hh"
#include "personagem.hh"
#include "sistema.hh"
#include "sprites.hh"
#include "background.hh"
#include "audio.hh"
#include "fonte.hh"
#include <thread>

class Engine {
    public:
        void running();
        ~Engine();
        Engine();

    private:
        Systema* game;
        Background* bg;
        Sprites* sprite_one;
        Personagem* player;
        Fonte* fonte;
        Fonte* avizos;
        Audio* som;
        Sprites* sprite_carro;
        Personagem* carro;

    private:
        void inputs();
        void code();
        void renderizadores();
        void objetos();
        void tela_menu();
        void tela_jogo();
	    void tela_end();
        void acoes_player_one();
        void acoes_player_two();

    private:
        int opt, retornos;
        enum direcoes { up=3, down=4, left=2, right=1, stop=5};
        direcoes diretion;
        string contador_fps, debuge;
        int frameCount, startTime;
        SDL_Thread* p1;
        SDL_Thread* p2;
        SDL_Event evento;
        bool side;
        thread* t1;
        thread* t2;
};

#endif // ENGINE_H
