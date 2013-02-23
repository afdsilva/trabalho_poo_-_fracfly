#ifndef _FESTADO_H_
	#define _FESTADO_H_
	
#include "FEvento.h"

class FEstado : public FEvento {
	public:
		FEstado();

	public:
		virtual void NaAtivacao() = 0;
		virtual void NaDesativacao() = 0;
		virtual void NoLaco() = 0;
		virtual void NaRenderizacao(SDL_Surface * planoExibicao) = 0;
};

#endif
