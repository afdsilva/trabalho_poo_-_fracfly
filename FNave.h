#ifndef _FNAVE_H_
	#define _FNAVE_H_

#include "FEntidade.h"

class FNave: public FEntidade {
	public:
		FNave();
		bool NoCarregar(char * arquivo, int width, int height, int maxFrames);
		bool NoCarregar(char * arquivo, int width, int height, int x, int y);
		void NoLaco();
		void NaRenderizacao(SDL_Surface * planoExibicao);
		void NaLimpeza();
		void NaAnimacao();
		bool NaColisao(FEntidade * entidade);
		
	public:
		bool Atirar(FEntidade * entidade, int aX, int aY);
};


#endif
