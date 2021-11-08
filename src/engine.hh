#ifndef ENGINE_HH
    #define ENGINE_HH

#include "internos.hh"
#include "personagem.hh"
#include "sistema.hh"
#include "sprites.hh"
#include "mapa.hh"
#include "audio.hh"
#include "fonte.hh"
#include <thread>

class Engine {
    public:
        void running();
        ~Engine();
        Engine();

    private:
        unique_ptr<Systema> game;
        unique_ptr<Mapa> tela1;
        shared_ptr<Personagem> player;
        unique_ptr<Fonte> fonte;
        unique_ptr<Fonte> avizos;
        unique_ptr<Audio> som;
        shared_ptr<Personagem> carro;

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
        SDL_Event evento;
        bool side;
        unique_ptr<thread> t1;
        unique_ptr<thread> t2;
};

#endif // ENGINE_H
