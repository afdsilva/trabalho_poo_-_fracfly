#ifndef _FRACFLY_H
	#define _FRACFLY_H

#include <SDL/SDL.h>
#include <SDL/SDL_rotozoom.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>

#include "FSuperficie.h"
#include "FAnimacao.h"
#include "FEvento.h"
#include "FEntidade.h"
#include "FEntidade_Arma.h"
#include "FEntidade_Tiro.h"

using namespace std;

class FracFly : public FEvento {
	private:
		bool Rodando;
		
		SDL_Surface * Plano_Exibicao;
		SDL_Surface * Surf_bg;
		
	private:
		FEntidade_Arma Arma1;
		FEntidade_Arma Arma2;
		FEntidade_Tiro Tiro;
		
	public:
		FracFly();
		int naExec();
		
		bool NoInic();
		void NoEvento(SDL_Event * Evento);
			void OnExit();
			void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
			void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
			void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);
			void OnLButtonDown(int mX, int mY);
			void OnLButtonUp(int mX, int mY);
			void OnRButtonDown(int mX, int mY);
			void OnRButtonUp(int mX, int mY);
			void OnMButtonDown(int mX, int mY);
			void OnMButtonUp(int mX, int mY);
			
		void NoLaco();
		void NaRenderizacao();
		void NaLimpeza();

};


#endif
