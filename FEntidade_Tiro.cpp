#include "FEntidade_Tiro.h"
#include <iostream>
using namespace std;

std::vector<FEntidade_Tiro*> FEntidade_Tiro::ListaTiros;

FEntidade_Tiro::FEntidade_Tiro() {

	AceleracaoX = 0;
	AceleracaoY = 0;
	X = Y = X2 = Y2 = 0;
	
	Velocidade = 1;
}


void FEntidade_Tiro::NoLaco() {
	if (X != X2) {
		if (X > X2)
			X--;
		else if (X < X2)
			X++;
	}
	if (Y != Y2) {
		if (Y > Y2)
			Y--;
		else if (Y < Y2)
			Y++;
	}
	if (X == X2 && Y == Y2) this->NaLimpeza();
}
