#ifndef SISTEMA_HH
	#define SISTEMA_HH

#include "internos.hh"

class Systema {
private:
	bool isRunning{false};
	int frameStart;
	int fps;
	int frameTime;
	int flags;
	SDL_Window* janela;
	static SDL_Renderer* renderer;
	SDL_Rect mouse;

public:
	Systema(const char* titulo, int width, int height, bool fullscreen);
	~Systema();
	void update();
	void renderizar();
	void stopGame();
	bool running();
	static SDL_Renderer* get_renderer();
};

#endif
