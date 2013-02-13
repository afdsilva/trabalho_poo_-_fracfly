#include "FracFly.h"

void FracFly::NaRenderizacao() {
	FSuperficie::NoDesenhar(Plano_Exibicao, Surf_Test, 0, 0);

	SDL_Flip(Plano_Exibicao);
}
