#include "FEntidade_Arma.h"
#include "FEntidade_Tiro.h"

FEntidade_Arma::FEntidade_Arma() {

	Tiro = false;

	FinalX = 0;
	FinalY = 0;
	printf("Criou Arma\n");
	
}

void FEntidade_Arma::Atirar(int X, int Y) {
	FEntidade_Tiro * Tiro = new FEntidade_Tiro();

	char Arquivo3[] = "res/ovo.png";
	if((Tiro->NoCarregar(Arquivo3, 100, 120, 1)) == false) {
        return;
	}
	Tiro->X2 = X;
	Tiro->Y2 = Y;
	Tiro->X = this->X;
	Tiro->Y = this->Y;

	printf("Atirou\n");
	FEntidade_Tiro::ListaTiros.push_back(Tiro);
	//if (!FEntidade_Tiro::ListaTiros.size())
	//printf("Punheta mal batida...\n");
	
}
