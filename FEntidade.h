#ifndef _FENTIDADE_H
  #define _FENTIDADE_H

#include <vector>

#include "FAnimacao.h"
#include "FSuperficie.h"

using namespace std;

class FEntidade {
	public:
		static vector<FEntidade*> ListaEntidades;
		
	protected:
		FAnimacao Anim_Control;
		SDL_Surface * Surf_Entidade;
		
	public:
		float X;
		float Y;

		bool moveCima;
		bool moveBaixo;
		bool moveDireita;
		bool moveEsquerda;
		
		int Aceleracao;
		
		int Width; //nomes da variavel em ingles
		int Height; //pra facilitar o entendimento Width = largura, Height = altura
		
		int AnimEstado;
		
	public:
		FEntidade();
		virtual ~FEntidade();
		
	public:
		virtual bool NoCarregar (char * Arquivo, int Width, int Height, int MaxFrames);
		virtual void NoLaco();
		virtual void NaRenderizacao(SDL_Surface * Plano_Exibicao);
		virtual void NaLimpeza();
		
};

#endif
