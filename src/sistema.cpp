#include "sistema.hh"

SDL_Renderer* Systema::renderer = nullptr;

Systema::Systema(const char* titulo, int width, int height, bool fullscreen) : frameStart(0), fps(1000/60), frameTime(0) {
	if (fullscreen){ flags = SDL_WINDOW_FULLSCREEN; } else { flags = SDL_WINDOW_RESIZABLE;}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
		if(!(IMG_Init(IMG_INIT_PNG)))
			cout << "Falha ao carregar IMG PNG. erro: " << SDL_GetError() << endl;

		if(!(TTF_Init()))
			cout << "Falha ao carregar TTF. ";

		if(!(Mix_Init(MIX_INIT_FLAC|MIX_INIT_MID|MIX_INIT_MOD|MIX_INIT_OPUS|MIX_INIT_MP3)))
            cout << "Falha ao carregar mp3. erro: " << SDL_GetError() << endl;

		if (!(IMG_Init(IMG_INIT_JPG)))
			cout << "Falha ao carregar IMG JPG. erro: " << SDL_GetError() << endl;

		janela = SDL_CreateWindow(titulo, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		if (janela == nullptr)
			cout << "Falha ao abrir a janela. erro: " << SDL_GetError() << endl;

		Systema::renderer = SDL_CreateRenderer(janela, -1, 0);
		SDL_SetRenderDrawColor(Systema::renderer, 0, 0, 0, 255);
		if (Systema::renderer == nullptr)
			cout << "Falha ao abrir o renderer. erro: " << SDL_GetError() << endl;

		isRunning = true;
	}
	else
	{
		cout << "Erro ao iniciar o SDL2. Erro: " << SDL_GetError() << endl;
	}
}

void Systema::update() {
	SDL_RenderPresent(Systema::renderer);
	frameStart = SDL_GetTicks();
	frameTime = SDL_GetTicks() - frameStart;
	if (fps > frameTime)
		SDL_Delay(fps - frameTime);
}

void Systema::renderizar(){ 
	SDL_RenderClear(Systema::renderer); 
}

void Systema::stopGame(){ 
	this->isRunning = false; 
}

bool Systema::running(){ 
	return this->isRunning;
}

SDL_Renderer* Systema::get_renderer(){ 
	return Systema::renderer; 
}

Systema::~Systema(){
	SDL_DestroyWindow(janela);
	SDL_DestroyRenderer(Systema::renderer);
	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}
