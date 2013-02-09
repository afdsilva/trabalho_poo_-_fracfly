#include "FracFly.h"

bool FracFly::NoInic() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}
	if ((Plano_Exibicao = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		return false;
	}
	return true;
}
