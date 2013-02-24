#include "FFonte.h"

FFonte::FFonte() {
	
}
TTF_Font * FFonte::NoCarregar(char * arquivo, int tam) {
	TTF_Font * retornoFonte;
	try {
		if (!(retornoFonte = TTF_OpenFont(arquivo, tam)))
			throw;
	} catch (...) {
		string msgErro = "FEntidade::Erro TTF_OpenFont ";
		msgErro += SDL_GetError();
		debug(msgErro,89);
		return NULL;
	}
	return retornoFonte;
}
bool FFonte::NoEscrever(SDL_Surface * superfDest, TTF_Font * fonte, string texto, int x, int y, SDL_Color corTexto) {
	try {
		SDL_Surface * tempSuperf;
		if ((tempSuperf = TTF_RenderText_Solid(fonte, texto.c_str(), corTexto)) == NULL)
			throw;
		SDL_Rect deslocamento;

		//seta as posições x e y
		deslocamento.x = x;
		deslocamento.y = y;

		//plota a superficie fonte na superficie destino
		try {
			if (SDL_BlitSurface( tempSuperf, NULL, superfDest, &deslocamento ) == -1)
				throw;
		} catch (...) {
		string msgErro = "FEntidade::Erro SDL_BlitSurface ";
		msgErro += SDL_GetError();
		debug(msgErro,89);
		}
	} catch (...) {
		string msgErro = "FEntidade::Erro TTF_RenderText_Solid ";
		msgErro += SDL_GetError();
		debug(msgErro,89);
		return false;
		
	}
	return true;
}
