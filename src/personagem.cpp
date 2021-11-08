#include "personagem.hh"

Personagem::Personagem(const char* path, int xframes, int yframes, int width, int height, string descr) : speed(5.0f), is_colliding(true), r(false), l(false), u(false), d(false) {
	this->atual = new Sprites(path, xframes, yframes, width, height);
	this->animates.push_back(make_pair(atual, descr));
	swap_animate(descr);
}

Personagem::~Personagem(){
	delete atual;
	for(auto spr : animates)
        delete spr.first;
	for(size_t a=0; a<animates.size(); a++)
		animates.pop_back();
}

void Personagem::add_animate(const char* path, int xframes, int yframes, int width, int height, string descr) {
	this->atual = new Sprites(path, xframes, yframes, width, height);
	this->animates.push_back(make_pair(atual, descr));
}

void Personagem::position(int xpos, int ypos){
	for(auto spr : animates){
        spr.first->posicao.x = xpos;
		spr.first->posicao.y = ypos;
    }
}

void Personagem::swap_animate(string descr) {
	int count{0};
	for (auto vetor : animates) {
		if (vetor.second == descr) {
			vetor.first->is_visible = true;
			this->atual = vetor.first;
		} else {
			count++;
			vetor.first->is_visible = false;
		}
	}
	if(count == animates.size())cout << "nao foi possivel achar sua skin...\n";
}


void Personagem::run_animate(){
    this->atual->run_animate();
}

void Personagem::renderizar(){
    this->atual->renderizar();
}

void Personagem::mover(int direction){
    for(auto spr : animates){
		switch(direction){
			case 1:
				spr.first->posicao.x += speed;
				break;

			case 2:
				spr.first->posicao.x -= speed;
				break;

			case 3:
				spr.first->posicao.y -= speed;
				break;

			case 4:
				spr.first->posicao.y += speed;
				break;

			default:
				break;
		}
    }
}

void Personagem::set_visible(bool visivel){
    this->atual->is_visible = visivel;
}

void Personagem::set_animate(bool animar){
    this->atual->is_animate = animar;
}

void Personagem::set_flipped(bool flipped){
	this->atual->is_flipped = flipped;
}

bool Personagem::get_flipped(){
	return this->atual->is_flipped;
}

bool Personagem::get_visible(){
	return this->atual->is_visible;
}

bool Personagem::get_animate(){
	return this->atual->is_animate;
}

double Personagem::get_x(){
	return this->atual->posicao.x;
}

double Personagem::get_y(){
	return this->atual->posicao.y;
}

bool Personagem::colisao_direita(int xpos, int ypos, int height, int width){
	if((atual->posicao.x + atual->posicao.w) == xpos){
		if(atual->posicao.y <= (ypos + height) && (atual->posicao.y + atual->posicao.h) >= ypos){
			is_colliding = false;
		}
	}
	return is_colliding;
}

bool Personagem::colisao_esquerda(int xpos, int ypos, int height, int width){
	if(atual->posicao.x == (xpos + width)){
		if(atual->posicao.y <= (ypos + height) && (atual->posicao.y + atual->posicao.h) >= ypos){
			is_colliding = false;
		}
	}
	return is_colliding;
}

bool Personagem::colisao_embaixo(int xpos, int ypos, int height, int width){
	if((atual->posicao.y + atual->posicao.h) == ypos){
		if(atual->posicao.x <= (xpos + width) && (atual->posicao.x + atual->posicao.w) >= xpos){
			is_colliding = false;
		}
	}
	return is_colliding;
}

bool Personagem::colisao_emcima(int xpos, int ypos, int height, int width){
	if(atual->posicao.y == (ypos + height)){
		if(atual->posicao.x <= (xpos + width) && (atual->posicao.x + atual->posicao.w) >= xpos){
			is_colliding = false;
		}
	}
	return is_colliding;
}


bool Personagem::rigidiBody(int xpos, int ypos, int height, int width){
	bool retornado{false};
	if(atual->posicao.y == (ypos + height)){
		if(atual->posicao.x <= (xpos + width) && (atual->posicao.x + atual->posicao.w) >= xpos){
			retornado = true;
		}
	} else if((atual->posicao.y + atual->posicao.h) == ypos){
		if(atual->posicao.x <= (xpos + width) && (atual->posicao.x + atual->posicao.w) >= xpos){
			retornado = true;
		}
	} else if(atual->posicao.x == (xpos + width)){
		if(atual->posicao.y <= (ypos + height) && (atual->posicao.y + atual->posicao.h) >= ypos){
			retornado = true;
		}
	} else if((atual->posicao.x + atual->posicao.w) == xpos){
		if(atual->posicao.y <= (ypos + height) && (atual->posicao.y + atual->posicao.h) >= ypos){
			retornado = true;
		}
	}

	return retornado;
}