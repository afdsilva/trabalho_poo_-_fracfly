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

	char Arquivo[] = "res/yoshi.bmp";

	if((Entity1.NoCarregar(Arquivo, 64, 64, 8)) == false) {
        return false;
    }
	if((Entity2.NoCarregar(Arquivo, 64, 64, 8)) == false) {
        return false;
    }
	Entity2.X = 100;
	FEntidade::ListaEntidades.push_back(&Entity1);
	FEntidade::ListaEntidades.push_back(&Entity2);
	return true;
}
