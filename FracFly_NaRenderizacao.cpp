#include "FracFly.h"

void FracFly::NaRenderizacao() {
	FSuperficie::NoDesenhar(Plano_Exibicao, Surf_bg, 0, 0);

	for(int i = 0;i < (int) FEntidade::ListaEntidades.size();i++) {
		if(!FEntidade::ListaEntidades[i]) continue;
		FEntidade::ListaEntidades[i]->NaRenderizacao(Plano_Exibicao);
	}

	SDL_Flip(Plano_Exibicao);
}
