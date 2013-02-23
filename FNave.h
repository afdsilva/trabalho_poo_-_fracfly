#ifndef _FNAVE_H_
	#define _FNAVE_H_

#include "FEntidade.h"

class FNave: public FEntidade {
	public:
		FNave();
		bool NoCarregar(char * arquivo, int width, int height, int maxFrames);
		void NoLaco();
		void NaRenderizacao(SDL_Surface * planoExibicao);
		void NaLimpeza();
		void NaAnimacao();
		bool NaColisao(FEntidade * entidade);
};


#endif
