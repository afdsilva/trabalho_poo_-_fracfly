#ifndef _FMap_H_
	#define _FMap_H_

#include <SDL/SDL.h>
#include <vector>

#include "FAzulejo.h"
#include "FSuperficie.h"

class FMap {
	public:
		SDL_Surface * superficieConjAzulejo;
		
	private:
		std::vector<FAzulejo> listaAzulejo;
		
	public:
		FMap();
		
	public:
		bool NoCarregar(char * arquivo);
		void NaRenderizacao(SDL_Surface * planoExibicao, int mapX, int mapY);
		
	public:
		FAzulejo * GetAzulejo(int x, int y);

};

#endif
