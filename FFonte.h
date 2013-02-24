#ifndef _FFONTE_H_
	#define _FFONTE_H_
 
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "male_libs.h"

class FFonte {
	public:
		FFonte();
		
	public:
		static TTF_Font * NoCarregar(char * arquivo, int tam);
		static bool NoEscrever(SDL_Surface * superfDest, TTF_Font * fonte, string texto, int x, int y, SDL_Color corTexto);
};

#endif
