#include "mapa.hh"

Mapa::Mapa(const char* path, int width, int height) : xpos(0), ypos(0), wpos(0), hpos(0), animw(0), animh(0), visible(true) {
    imagem = IMG_Load(path);
    texturaImage = SDL_CreateTextureFromSurface(Systema::get_renderer(), imagem);
    SDL_QueryTexture(texturaImage, NULL, NULL, &wpos, &hpos);
    animacao.w = wpos; animacao.h = hpos;
    animacao.x = animacao.y = posicao.x = posicao.y = 0;
    posicao.w = width; posicao.h = height;
    camera.x = camera.y = 0; camera.w = 1280; camera.h = 720;
}

void Mapa::atualizar_camera(int x, int y, int w, int h){
    camera.x = ( x + w / 2 ) - 1280 / 2;
	camera.y = ( y + h / 2 ) - 720 / 2;
}

void Mapa::renderizar() {
    if(camera.x < 0)
		camera.x = 0;

	if(camera.y < 0)
		camera.y = 0;

	if(camera.x > 3000 - camera.w)
		camera.x = 3000 - camera.w;

	if(camera.y > 1500 - camera.h)
		camera.y = 1500 - camera.h;

    if(visible)
        SDL_RenderCopy(Systema::get_renderer(), texturaImage, &camera, &posicao);
}

void Mapa::set_visible(bool visivel){
    visible = visivel;
}

bool Mapa::get_visible(){
    return visible;
}

Mapa::~Mapa(){
    SDL_DestroyTexture(texturaImage);
    SDL_FreeSurface(imagem);
}
