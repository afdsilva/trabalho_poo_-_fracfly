/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/

#include "FSuperficie.h"
#include <iostream>
using namespace std;

FSuperficie::FSuperficie() {
}
 
SDL_Surface * FSuperficie::NoCarregar(char * arquivo) {
	Excecoes::linhaErro = 8;
	Excecoes::classErro = "FSuperficie::NoCarregar";
	Excecoes::msgErro.clear();
	SDL_Surface * retorno;
	try {
		SDL_Surface * _temp = NULL;
		if ((_temp = IMG_Load(arquivo)) == NULL) {
			Excecoes::msgErro+= "Nao foi possivel carregar o arquivo ";
			Excecoes::msgErro+= arquivo;
			throw Excecoes::TratamentoExcecao();
		}
		retorno = SDL_DisplayFormatAlpha(_temp);
		SDL_FreeSurface(_temp);
	} catch(int e) {
		retorno = NULL;
	}

    return retorno;
}

bool FSuperficie::NoDesenhar(SDL_Surface * surfDest, SDL_Surface * surfOri, int x, int y) {
	Excecoes::linhaErro = 29;
	Excecoes::classErro = "FSuperficie::NoDesenhar";
	Excecoes::msgErro.clear();
	bool retorno = true;
	try {
		if(surfDest == NULL || surfOri == NULL) {
			Excecoes::msgErro+= "sem superficie";
			throw Excecoes::TratamentoExcecao();
		}

		SDL_Rect destR;

		destR.x = x;
		destR.y = y;

		SDL_BlitSurface(surfOri, NULL, surfDest, &destR);
	} catch (...) {
		retorno = false;
	}
 
    return retorno;
}

bool FSuperficie::NoDesenhar(SDL_Surface * surfDest, SDL_Surface * surfOri, int x, int y, int x2, int y2, int w, int h) {
	Excecoes::linhaErro = 53;
	Excecoes::classErro = "FSuperficie::NoDesenhar";
	Excecoes::msgErro.clear();
	bool retorno = true;
	try {
		if(surfDest == NULL || surfOri == NULL) {
			Excecoes::msgErro+= "sem superficie";
			throw Excecoes::TratamentoExcecao();
		}

		SDL_Rect destR;

		destR.x = x;
		destR.y = y;

		SDL_Rect oriR;

		oriR.x = x2;
		oriR.y = y2;
		oriR.w = w;
		oriR.h = h;

		SDL_BlitSurface(surfOri, &oriR, surfDest, &destR);
	} catch (...) {
		retorno = false;
	}
    return retorno;
}

bool FSuperficie::Transparencia(SDL_Surface * surfDest, int r, int g, int b) {
	Excecoes::linhaErro = 83;
	Excecoes::classErro = "FSuperficie::Transparencia";
	Excecoes::msgErro.clear();
	bool retorno = true;
	try {
		if(surfDest == NULL) {
			Excecoes::msgErro+= "sem superficie";
			throw Excecoes::TratamentoExcecao();
		}
 
    SDL_SetColorKey(surfDest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(surfDest->format, r, g, b));
	} catch (...) {
		retorno = false;
	}
 
    return retorno;
}
