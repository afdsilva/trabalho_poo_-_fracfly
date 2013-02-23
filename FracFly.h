#ifndef _FRACFLY_H
	#define _FRACFLY_H

#include <SDL/SDL.h>
#include <SDL/SDL_rotozoom.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>

#include "Definicoes.h"
 
#include "FEvento.h"
#include "FEntidade.h"
#include "FNave.h"

using namespace std;

class FracFly : public FEvento {
	private:
		bool rodando;
		
		//superficies
		SDL_Surface * planoExibicao;
		
	private:
		//entidades
		FNave	nave;
		
	public:
		FracFly();
		int naExec();
		
		bool NoInic();
		void NoEvento(SDL_Event * evento);
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
