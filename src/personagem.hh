#ifndef PERSONAGEM_HH
    #define PERSONAGEM_HH

#include "internos.hh"
#include "sprites.hh"


class Personagem {
	private:
		vector<pair<Sprites*, string>> animates;
		Sprites* atual = new Sprites();
		const float speed;

	public:
		Personagem(Sprites* sprite, string descr);
		~Personagem();
		void add_animate(Sprites* sprite, string descr);
		void swap_animate(string descr);
		void set_visible(bool visivel);
		void set_animate(bool animar);
		bool get_animate();
		bool get_visible();
		void run_animate();
		void renderizar();
		void mover(int direction);
		bool rigidiBody(double xpos, double ypos, int height, int width);
		void position(double xpos, double ypos);
		double get_x();
		double get_y();
};

#endif
