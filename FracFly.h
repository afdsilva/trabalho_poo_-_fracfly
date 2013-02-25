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
		
		SDL_Surface * planoExibicao;
	
	public:
		FEntidade cursor;
		
	public:
		FracFly();
		int naExec();
	
	public:
		bool NoInic();
		void NoEvento(SDL_Event * evento);
			void OnExit();
			void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);
			void OnLButtonDown(int mX, int mY);
			void OnLButtonUp(int mX, int mY);
			
		void NoLaco();
		void NaRenderizacao();
		void NaLimpeza();

};


#endif
