#include "FracFly.h"

void FracFly::NaLimpeza() {
	SDL_FreeSurface(Surf_Test);
	SDL_FreeSurface(Surf_bg);
	SDL_FreeSurface(Plano_Exibicao);
	SDL_Quit();
}
