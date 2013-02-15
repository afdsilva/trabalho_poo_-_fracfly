#ifndef _FENTIDADE_TIRO_H
  #define _FENTIDADE_TIRO_H

#include "FEntidade.h"

class FEntidade_Tiro : public FEntidade {
	public:
		static vector<FEntidade_Tiro*> ListaTiros;

	public:
		FEntidade_Tiro();
		virtual void NoLaco();
		
		int X2;
		int Y2;
		
		int AceleracaoX;
		int AceleracaoY;

		int Velocidade;
};

#endif
