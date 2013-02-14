#include "FracFly.h"

void FracFly::NaLimpeza() {

	for(int i = 0;i < (int) FEntidade::ListaEntidades.size();i++) {
		if(!FEntidade::ListaEntidades[i]) continue;
		FEntidade::ListaEntidades[i]->NaLimpeza();
	}
	FEntidade::ListaEntidades.clear();
/**
	for(int i = 0;i < (int) FEntidade_Arma::ListaTiros.size();i++) {
		if(!FEntidade_Arma::ListaTiros[i]) continue;
		FEntidade_Arma::ListaTiros[i]->NaRenderizacao(Plano_Exibicao);
	}
	FEntidade_Arma::ListaTiros.clear();
**/	
	SDL_FreeSurface(Surf_bg);
	SDL_FreeSurface(Plano_Exibicao);
	SDL_Quit();
}
