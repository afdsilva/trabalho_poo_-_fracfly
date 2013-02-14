#ifndef _FRACFLY_H
	#define _FRACFLY_H

#include <SDL/SDL.h>
#include <iostream>
#include <string>
#include <string.h>

#include "FSuperficie.h"
#include "FAnimacao.h"
#include "FEvento.h"

using namespace std;

class FracFly : public FEvento {
	private:
		bool Rodando;
		
		SDL_Surface * Plano_Exibicao;
		
		SDL_Surface * Surf_Test;
		SDL_Surface * Surf_bg;
		
		FAnimacao Anim_Yoshi;
		
	public:
		FracFly();
		int naExec();
		
		bool NoInic();
		void NoEvento(SDL_Event * Evento);
			void OnExit();
			void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
			void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
			
		void NoLaco();
		void NaRenderizacao();
		void NaLimpeza();

};


#endif
