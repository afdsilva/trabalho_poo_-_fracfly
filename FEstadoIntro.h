/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/

#ifndef _FESTADOINTO_H_
	#define _FESTADOINTO_H_

#include "FEstado.h"
#include "FSuperficie.h"

class FEstadoIntro : public FEstado {
	private:
		static FEstadoIntro instancia;
		SDL_Surface * logo;
		int tempoInicio;
		
	private:
		FEstadoIntro();
	
	public:
		void NaAtivacao();
		void NaDesativacao();
		void NoLaco();
		void NaRenderizacao(SDL_Surface * planoExibicao);
		
		void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
		void OnLButtonDown(int mX, int mY);

	public:
		static FEstadoIntro * GetInstancia();
};

#endif
