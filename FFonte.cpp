#include "FFonte.h"

FFonte::FFonte() {
	
}
TTF_Font * FFonte::NoCarregar(char * arquivo, int tam) {
	Excecoes::linhaErro = 6;
	Excecoes::classErro = "FFonte::NoCarregar";
	TTF_Font * retornoFonte;
	try {
		if (!(retornoFonte = TTF_OpenFont(arquivo, tam))) {
			Excecoes::msgErro = "TTF_OpenFont ";
			Excecoes::msgErro += SDL_GetError();
			throw Excecoes::TratamentoExcecao();
		}
	} catch (...) {
		retornoFonte = NULL;
	}
	return retornoFonte;
}
bool FFonte::NoEscrever(SDL_Surface * superfDest, TTF_Font * fonte, string texto, int x, int y, SDL_Color corTexto) {
	Excecoes::linhaErro = 21;
	Excecoes::classErro = "FFonte::NoEscrever";
	bool retorno = true;
	try {
		SDL_Surface * tempSuperf;
		if ((tempSuperf = TTF_RenderText_Solid(fonte, texto.c_str(), corTexto)) == NULL) {
			Excecoes::msgErro = "TTF_RenderText_Solid ";
			Excecoes::msgErro += SDL_GetError();
			throw Excecoes::TratamentoExcecao();
		}
		SDL_Rect deslocamento;

		//seta as posições x e y
		deslocamento.x = x;
		deslocamento.y = y;

		//plota a superficie fonte na superficie destino
		if (SDL_BlitSurface( tempSuperf, NULL, superfDest, &deslocamento ) == -1) {
			Excecoes::msgErro = "SDL_BlitSurface ";
			Excecoes::msgErro += SDL_GetError();
			throw Excecoes::TratamentoExcecao();
		}
	} catch (...) {
		retorno = false;
	}
	return retorno;
}
