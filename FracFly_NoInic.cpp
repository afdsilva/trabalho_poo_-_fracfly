#include "FracFly.h"

bool FracFly::NoInic() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}
	
	if ((Plano_Exibicao = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		return false;
	}
	
	char bg[] = "res/teste.bmp";
	if ((Surf_bg = FSuperficie::NoCarregar(bg)) == NULL) {
		return false;
	}

	char Arquivo[] = "res/yoshi.png";
	char Arquivo2[] = "res/yoshi.png";

	if((Arma1.NoCarregar(Arquivo, 64, 64, 8)) == false) {
        return false;
    }
	if((Arma2.NoCarregar(Arquivo2, 64, 64, 8)) == false) {
        return false;
    }

	Arma1.X = 0;
	Arma2.X = 640 - (Arma2.Width);
	Arma1.Y = 480 - (Arma1.Height);
	Arma2.Y = 480 - (Arma2.Height);
	FEntidade::ListaEntidades.push_back(&Arma1);
	FEntidade::ListaEntidades.push_back(&Arma2);

	return true;
}
