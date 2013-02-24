#include "FFonte.h"

FFonte::FFonte() {
	
}
TTF_Font * FFonte::NoCarregar(char * arquivo, int tam) {
	TTF_Font * retornoFonte;
	if (!(retornoFonte = TTF_OpenFont(arquivo, tam))) {
		//cout << "Erro OpenFont " << SDL_GetError() << endl;
		return NULL;
	}
	return retornoFonte;
}
bool FFonte::NoEscrever(SDL_Surface * superfDest, TTF_Font * fonte, char * mensagem, int x, int y, SDL_Color corTexto) {

	//if (corTexto == NULL) corTexto = {255, 255, 255};

	SDL_Surface * tempSuperf;

	tempSuperf = TTF_RenderText_Solid(fonte, mensagem, corTexto);
    SDL_Rect deslocamento;

	//seta as posições x e y
    deslocamento.x = x;
    deslocamento.y = y;

    //plota a superficie fonte na superficie destino
	SDL_BlitSurface( tempSuperf, NULL, superfDest, &deslocamento );
	
	return true;
}
