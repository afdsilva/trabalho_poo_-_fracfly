#include "FracFly.h"

void FracFly::NaRenderizacao() {
	FSuperficie::NoDesenhar(Plano_Exibicao, Surf_bg, 0, 0);

	for(int i = 0;i < (int) FEntidade::ListaEntidades.size();i++) {
		if(!FEntidade::ListaEntidades[i]) continue;
		FEntidade::ListaEntidades[i]->NaRenderizacao(Plano_Exibicao);
	}
	printf("Tiros: %d\n", FEntidade_Arma::ListaTiros.size());
	/**
	for(int i = 0;i < (int) FEntidade_Arma::ListaTiros.size();i++) {
		if(!FEntidade_Arma::ListaTiros[i]) continue;
		FEntidade_Arma::ListaTiros[i]->NaRenderizacao(Plano_Exibicao);
	}
	**/
	SDL_Flip(Plano_Exibicao);
}
