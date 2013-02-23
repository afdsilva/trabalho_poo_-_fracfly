#ifndef _FESTADOJOGO_H_
	#define _FESTADOJOGO_H_

#include "FEstado.h"

#include "FArea.h"
#include "FCamera.h"
#include "FEntidade.h"
#include "FSuperficie.h"

#include "FNave.h"

class FEstadoJogo : public FEstado {
	private:
		static FEstadoJogo instancia;
		
		FNave 		jogador;
		FEntidade	cursor;
		
	private:
		FEstadoJogo();
	
	public:
		void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
		void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
		void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);
		void OnLButtonDown(int mX, int mY);
		void OnLButtonUp(int mX, int mY);
		void OnRButtonDown(int mX, int mY);
		void OnRButtonUp(int mX, int mY);
		void OnMButtonDown(int mX, int mY);
		void OnMButtonUp(int mX, int mY);
	
	public:
		void NaAtivacao();
		void NaDesativacao();
		void NoLaco();
		void NaRenderizacao(SDL_Surface * planoExibicao);
		
	public:
		static FEstadoJogo * GetInstancia();
};

#endif
