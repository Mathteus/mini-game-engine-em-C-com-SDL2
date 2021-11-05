#include "engine.hh"

Engine::Engine() : diretion(right), contador_fps(""), startTime(0), frameCount(0) {
	game = new Systema("Game Test", 1280, 720, false);
	bg = new Background("../imagens/paisagem.jpeg", 1280, 720);

	sprite_one = new Sprites("../imagens/persona.png", 1, 1, 120, 120);
	player_one = new Personagem(sprite_one, "one");
	player_one->position(50, 50);

	fonte = new Fonte("../fontes/arial.ttf", "Teste de fonte", 20, 2, 2);

	som = new Audio("../sounds/rain.wav");
	som->start(1);

	startTime = SDL_GetTicks();
	frameCount = 0;
}

void Engine::inputs(){
    SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				game->stopGame();
				break;

			case SDL_KEYUP:
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.scancode) {
					case SDL_SCANCODE_ESCAPE:
						game->stopGame();
						break;

					case SDL_SCANCODE_D:
						diretion = right;
						player_one->mover(diretion);
						break;

					case SDL_SCANCODE_A:
						diretion = left;
						player_one->mover(diretion);
						break;

					case SDL_SCANCODE_W:
						diretion = up;
						player_one->mover(diretion);
						break;

					case SDL_SCANCODE_S:
						diretion = down;
						player_one->mover(diretion);
						break;

					default:
						diretion = stop;
						break;
			}
		}
	}
}

void Engine::tela_menu(){}
void Engine::tela_jogo(){}
void Engine::tela_end(){}

void Engine::code(){
	switch(opt){
		case 0:
			Engine::tela_menu();
			break;

		case 1:
			Engine::tela_jogo();
			break;

		case 2:
			Engine::tela_end();
			break;

		default:
			break;
	}

	frameCount++;
	contador_fps = "FPS: ";
	contador_fps += to_string(1000*frameCount/(SDL_GetTicks() - startTime));
	const char* txt = strcpy((char *) malloc(contador_fps.length () + 1), contador_fps.c_str ());
	fonte->texto(txt);
}

void Engine::objetos(){
	bg->renderizar();
	player_one->renderizar();
	fonte->renderizar();
}

void Engine::renderizadores(){
    game->renderizar();
	Engine::objetos();
	game->update();
}

void Engine::running(){
	while(game->running()){
		inputs();
		code();
		renderizadores();
	}
}

Engine::~Engine(){
	delete sprite_one;
	delete game;
	delete player_one;
	delete bg;
	delete fonte;
	delete som;
}
