#ifndef _FRACFLY_H
	#define _FRACFLY_H

#include <SDL/SDL.h>

#include "Definicoes.h"

#include "FGerenciadorEstados.h" 
#include "FFPS.h" 

#include "FEvento.h"
#include "FEntidade.h"

class FracFly : public FEvento {
	private:
		bool rodando;
		
		//superficies
		SDL_Surface * planoExibicao;
		
	public:
		FracFly();
		int naExec();
	
	public:
		bool NoInic();
		void NoEvento(SDL_Event * evento);
			void OnExit();
			
		void NoLaco();
		void NaRenderizacao();
		void NaLimpeza();

};


#endif
