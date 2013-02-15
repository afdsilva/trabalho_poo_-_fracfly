#include "FEntidade_Tiro.h"

using namespace std;

std::vector<FEntidade_Tiro*> FEntidade_Tiro::ListaTiros;

FEntidade_Tiro::FEntidade_Tiro() {

	AceleracaoX = 0.0;
	AceleracaoY = 0.0;
	X = Y = X2 = Y2 = 0;
	
	Velocidade = 0;
	Ativo = true;
}
FEntidade_Tiro::~FEntidade_Tiro() {
}

void FEntidade_Tiro::NoLaco() {
	Anim_Control.NaAnimacao();

	X += (AceleracaoX);
	Y += (AceleracaoY);
	//cout << "AceleracaoX: " << AceleracaoX << " AceleracaoY" << AceleracaoY << endl;
/**
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
**/
	//cout << "X: " << X << " Velocidade: " << Velocidade << endl;
	//cout << "Y: " << Y << " Velocidade: " << Velocidade << endl;
	
	if (X >= abs(X2) || Y <= abs(Y2)){ 
		this->NaLimpeza();
		Ativo = false;
	}
}
