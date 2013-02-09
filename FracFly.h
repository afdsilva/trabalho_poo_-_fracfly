#ifndef FRACFLY_H
	#define FRACFLY_H
	
#include <SDL/SDL.h>
#include <iostream>

using namespace std;

class FracFly {
	private:
		bool Rodando;
		
		SDL_Surface * Plano_Exibicao;
		
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
