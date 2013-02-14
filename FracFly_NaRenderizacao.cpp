#include "FracFly.h"

void FracFly::NaRenderizacao() {
	FSuperficie::NoDesenhar(Plano_Exibicao, Surf_bg, 0, 0);
	FSuperficie::NoDesenhar(Plano_Exibicao, Surf_Test, 290, 220, 0, Anim_Yoshi.GetFrameAtual() * 64, 64, 64);

	SDL_Flip(Plano_Exibicao);
}
