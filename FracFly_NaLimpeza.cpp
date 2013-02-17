#include "FracFly.h"

void FracFly::NaLimpeza() {

	FArea::ControleArea.NaLimpeza();
	
	for(int i = 0;i < (int) FEntidade::ListaEntidades.size();i++) {
		if(!FEntidade::ListaEntidades[i]) continue;
		FEntidade::ListaEntidades[i]->NaLimpeza();
	}
	FEntidade::ListaEntidades.clear();

	for(int i = 0;i < (int) FEntidade_Tiro::ListaTiros.size();i++) {
		if(!FEntidade_Tiro::ListaTiros[i]) continue;
		FEntidade_Tiro::ListaTiros[i]->NaLimpeza();
	}
	FEntidade_Tiro::ListaTiros.clear();

	SDL_FreeSurface(Surf_bg);
	SDL_FreeSurface(Plano_Exibicao);
	SDL_Quit();
}
