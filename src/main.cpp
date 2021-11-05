#include "engine.hh"

int main(int argc, char** argv){
	Engine* engine = new Engine();
	engine->running();
	delete engine;
	return 0;
}

//comando compilar linux
// g++ main.cpp -o main -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf -lSDL2_mixer