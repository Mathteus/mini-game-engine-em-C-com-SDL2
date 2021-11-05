#include "engine.hh"

Engine::Engine() : diretion(right), contador_fps(""), startTime(0), frameCount(0), opt(1), retornos(0), side(true) {
	game = new Systema("Game Test", 1280, 720, false);
	bg = new Background("../imagens/paisagem.jpeg", 1280, 720);

	sprite_one = new Sprites("../imagens/persona.png", 1, 1, 120, 120);
	player = new Personagem(sprite_one, "one");
	player->position(50, 50);

	sprite_carro = new Sprites("../imagens/bus1.png", 1, 1, 60, 60);
	carro = new Personagem(sprite_carro, "car");
	carro->position(600, 600);

	fonte = new Fonte("../fontes/arial.ttf", "Teste de fonte", 20, 2, 2);
	avizos = new Fonte("../fontes/arial.ttf", "Para Sair Aperte [ESC]", 18, 1000, 2);

	som = new Audio("../sounds/rain.wav");
	som->start(1);

	startTime = SDL_GetTicks();
	frameCount = 0;

	t1 = new thread(std::bind(&Engine::acoes_player_one, this));
	t2 = new thread(std::bind(&Engine::acoes_player_two, this));

	Engine::running();
}

void Engine::acoes_player_one(){
	switch(diretion){
		case right:
			player->mover(diretion);
			break;

		case left:
			player->mover(diretion);
			break;

		case up:
			player->mover(diretion);
			break;
		
		case down:
			player->mover(diretion);
			break;
		
		default:
			break;
	}
}

void Engine::acoes_player_two(){
	if(carro->get_x() > 700)
		side = false;
	else if(carro->get_x() < 100)
		side = true;

	/*if(side)
		carro->mover(right);
	else
		carro->mover(left);*/
}

void Engine::inputs(){
	while (SDL_PollEvent(&evento)) {
		switch (evento.type) {
			case SDL_QUIT:
				game->stopGame();
				break;

			case SDL_KEYUP:
				break;

			case SDL_KEYDOWN:
				switch (evento.key.keysym.scancode) {
					case SDL_SCANCODE_ESCAPE:
						game->stopGame();
						break;

					case SDL_SCANCODE_D:
						if(player->colisao_direita(carro->get_x(), carro->get_y(), 60, 60)){
							diretion = right;
							Engine::acoes_player_one();
						} else {
							cout << "else direita\n";
						}
						if(player->colisao_direita(carro->get_x(), carro->get_y(), 60, 60) && diretion != right){
							diretion = right;
							Engine::acoes_player_one();
						}
						break;

					case SDL_SCANCODE_A:
						if(player->colisao_esquerda(carro->get_x(), carro->get_y(), 60, 60)){
							diretion = left;
							Engine::acoes_player_one();
						} else {
							cout << "else esquerda\n";
						}
						if(player->colisao_esquerda(carro->get_x(), carro->get_y(), 60, 60) && diretion != left){
							diretion = left;
							Engine::acoes_player_one();
						}
						break;

					case SDL_SCANCODE_W:
						if(player->colisao_emcima(carro->get_x(), carro->get_y(), 60, 60)){
							diretion = up;
							Engine::acoes_player_one();
						} else {
							cout << "else cima\n";
						}
						if(player->colisao_emcima(carro->get_x(), carro->get_y(), 60, 60) && diretion != up){
							diretion = up;
							Engine::acoes_player_one();
						}
						break;

					case SDL_SCANCODE_S:
						if(player->colisao_embaixo(carro->get_x(), carro->get_y(), 60, 60)){
							diretion = down;
							Engine::acoes_player_one();
						} else {
							cout << "else baixo\n";
						}
						if(player->colisao_embaixo(carro->get_x(), carro->get_y(), 60, 60) && diretion != down){
							diretion = down;
							Engine::acoes_player_one();
						}
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

	Engine::acoes_player_two();

	frameCount++;
	contador_fps = "FPS: ";
	contador_fps += to_string(1000*frameCount/(SDL_GetTicks() - startTime));
	const char* txt = strcpy((char *) malloc(contador_fps.length () + 1), contador_fps.c_str ());
	fonte->texto(txt);	
}

void Engine::objetos(){
	bg->renderizar();
	player->renderizar();
	carro->renderizar();
	fonte->renderizar();
	avizos->renderizar();
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
	delete player;
	delete bg;
	delete fonte;
	delete som;
	t1->join();
	t2->join();
	delete t1;
	delete t2;
}
