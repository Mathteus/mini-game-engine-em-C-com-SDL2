#include "engine.hh"

int main(int argc, char** argv){
	unique_ptr<Engine> engine(new Engine());
	return 0;
}

//comando compilar linux
// g++ main.cpp -o main -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf -lSDL2_mixer