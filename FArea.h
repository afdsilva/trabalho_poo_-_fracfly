#ifndef _FAREA_H_
	#define _FAREA_H_

#include "male_libs.h"
#include "FMap.h"

class FArea {
	public:
		static FArea 		controleArea;
	public:
		std::vector<FMap> 	listaMapas;
		
	private:
		int 			tamArea;
		SDL_Surface * 	superficieConjAzulejo;
		
	public:
		FArea();
		bool 	NoCarregar(char * arquivo);
		void 	NaRenderizacao(SDL_Surface * planoExibicao, int cameraX, int cameraY);
		void 	NaLimpeza();
		
	public:
		FMap * 		GetMap(int x, int y);
		FAzulejo * 	GetAzulejo(int x, int y);

};

#endif
