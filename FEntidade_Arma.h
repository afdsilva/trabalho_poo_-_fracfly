#ifndef _FENTIDADE_ARMA_H
  #define _FENTIDADE_ARMA_H

#include "FEntidade.h"

class FEntidade_Arma : public FEntidade {
	public:
		static vector<FEntidade_Arma*> ListaTiros;
	
	public:
		FEntidade_Arma();
		
		bool Tiro;
		
		int FinalX;
		int FinalY;
		
		void Atirar(int X, int Y);
};

#endif
