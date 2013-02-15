#ifndef _FENTIDADE_TIRO_H
  #define _FENTIDADE_TIRO_H

#include "FEntidade.h"
#include <iostream>
#include <cmath>

class FEntidade_Tiro : public FEntidade {
	public:
		static vector<FEntidade_Tiro*> ListaTiros;

	public:
		FEntidade_Tiro();
		~FEntidade_Tiro();
		virtual void NoLaco();
		
		bool Ativo;
		
		int X2;
		int Y2;
		
		float AceleracaoX;
		float AceleracaoY;

		int Velocidade;
		int Distancia;
};

#endif
