#ifndef _FMap_H_
	#define _FMap_H_

#include <SDL/SDL.h>
#include <vector>

#include "FAzulejo.h"
#include "FSuperficie.h"

class FMap {
	public:
		SDL_Surface * Surf_ConjAzulejo;
		
	private:
		std::vector<FAzulejo> ListaAzulejo;
		
	public:
		FMap();
		
	public:
		bool NoCarregar(char * File);
		void NaRenderizacao(SDL_Surface * Plano_Exibicao, int MapX, int MapY);
};

#endif
