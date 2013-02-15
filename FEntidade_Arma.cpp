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
	if((Tiro->NoCarregar(Arquivo3, 200, 240, 1)) == false) {
        return;
	}
	Tiro->Velocidade = 3;
	Tiro->Distancia = sqrt(pow(X - this->X,2) + pow(Y - this->Y,2));
	Tiro->AceleracaoX = Tiro->Velocidade * ((float)(X > this->X ? X - this->X : (-X + this->X) ) / (float) Tiro->Distancia);
	Tiro->AceleracaoY = Tiro->Velocidade * ((float)(Y < this->Y ? Y - this->Y : (-Y + this->Y) ) / (float) Tiro->Distancia);
	Tiro->X2 = X;
	Tiro->Y2 = Y;
	Tiro->X = this->X;
	Tiro->Y = this->Y;

	printf("Atirou\n");
	FEntidade_Tiro::ListaTiros.push_back(Tiro);

}
