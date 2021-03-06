#ifndef PERSONAGEM_HH
    #define PERSONAGEM_HH

#include "internos.hh"
#include "sprites.hh"


class Personagem {
	private:
		vector<pair<Sprites*, string>> animates;
		Sprites* atual = new Sprites();
		const float speed;
		bool is_colliding;
		
	public:
		bool r, l, u, d;
		Personagem(const char* path, int xframes, int yframes, int width, int height, string descr);
		//Personagem(Personagem&& old);
		~Personagem();
		void add_animate(const char* path, int xframes, int yframes, int width, int height, string descr);
		void swap_animate(string descr);
		void set_visible(bool visivel);
		void set_animate(bool animar);
		void set_flipped(bool flipped);
		bool get_animate();
		bool get_visible();
		bool get_flipped();
		void run_animate();
		void renderizar();
		void mover(int direction);
		bool colisao_esquerda(int xpos, int ypos, int height, int width);
		bool colisao_direita(int xpos, int ypos, int height, int width);
		bool colisao_emcima(int xpos, int ypos, int height, int width);
		bool colisao_embaixo(int xpos, int ypos, int height, int width);
		bool rigidiBody(int xpos, int ypos, int height, int width);
		void position(int xpos, int ypos);
		double get_x();
		double get_y();
};

#endif
