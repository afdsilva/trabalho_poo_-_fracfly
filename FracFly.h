#ifndef _FRACFLY_H
	#define _FRACFLY_H

#include <SDL/SDL.h>

#include "FSuperficie.h"

#include <iostream>

using namespace std;

class FracFly {
	private:
		bool Rodando;
		
		SDL_Surface * Plano_Exibicao;
		
		SDL_Surface * Surf_Test;
		
	public:
		FracFly();
		int naExec();
		
		bool NoInic();
		void NoEvento(SDL_Event * Evento);
		void NoLaco();
		void NaRenderizacao();
		void NaLimpeza();

};


#endif
