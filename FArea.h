#ifndef _FAREA_H_
	#define _FAREA_H_

#include "FMap.h"

class FArea {
	public:
		static FArea ControleArea;
	public:
		std::vector<FMap> ListaMapas;
		
	private:
		int TamArea;
		SDL_Surface * Surf_ConjAzulejo;
		
	public:
		FArea();
		bool NoCarregar(char * Arquivo);
		void NaRenderizacao(SDL_Surface * Plano_Exibicao, int CameraX, int CameraY);
		void NaLimpeza();
};

#endif
