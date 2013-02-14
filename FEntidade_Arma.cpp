#include "FEntidade_Arma.h"

std::vector<FEntidade_Arma*> FEntidade_Arma::ListaTiros;

FEntidade_Arma::FEntidade_Arma() {

	Tiro = false;

	FinalX = 0;
	FinalY = 0;
	printf("Criou Arma\n");
	
}

void FEntidade_Arma::Atirar(int X, int Y) {
	FEntidade_Arma Ovo;

	char Arquivo3[] = "res/ovo.png";
	if((Ovo.NoCarregar(Arquivo3, 200, 240, 1)) == false) {
        return;
	}

	Ovo.X = X;
	Ovo.Y = Y;
	
	printf("Atirou\n");
	FEntidade_Arma::ListaTiros.push_back(&Ovo);

	FinalX = X;
	FinalY = Y;
	
}
