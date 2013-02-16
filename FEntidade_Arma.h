#ifndef _FENTIDADE_ARMA_H
  #define _FENTIDADE_ARMA_H

#include "FEntidade.h"

class FEntidade_Arma : public FEntidade {
	public:
		FEntidade_Arma();
		
		bool Tiro;
		
		int FinalX;
		int FinalY;
		
		void Atirar(int X, int Y);
		void Rotacionar();
};

#endif
