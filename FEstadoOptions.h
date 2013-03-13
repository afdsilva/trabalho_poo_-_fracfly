/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/

#ifndef _FESTADOOPTIONS_H_
	#define _FESTADOOPTIONS_H_

#include "Definicoes.h"

#include "FEstado.h"

#include "FCamera.h"
#include "FEntidade.h"
#include "FSuperficie.h"
#include "FFonte.h"

class FEstadoOptions: public FEstado {
	private:
		static FEstadoOptions instancia;
		FEntidadeTexto * titulo;
		FEntidadeBotao * voltar;
		int estadoSelecionado;
		
	private:
		TTF_Font * fonte;
		
	private:
		FEstadoOptions();
	
	public:
		void NaAtivacao();
		void NaDesativacao();
		void NoLaco();
		void NaRenderizacao(SDL_Surface * planoExibicao);
	
	public:
		void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
		//void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
		void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);
		void OnLButtonDown(int mX, int mY);
		void OnLButtonUp(int mX, int mY);
		//void OnRButtonDown(int mX, int mY);
		//void OnRButtonUp(int mX, int mY);
		
	public:
		static FEstadoOptions * GetInstancia();
};

#endif
