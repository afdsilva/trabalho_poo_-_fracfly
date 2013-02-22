#include "FracFly.h"

/**
 * Metodo de limpeza de memoria, libera as superficies e vetores gerados durante o programa;
 **/
void FracFly::NaLimpeza() {

	FArea::controleArea.NaLimpeza();
	
	for(int i = 0;i < (int) FEntidade::listaEntidades.size();i++) {
		if(!FEntidade::listaEntidades[i]) continue;
		FEntidade::listaEntidades[i]->NaLimpeza();
	}
	FEntidade::listaEntidades.clear();
	/**
	for(int i = 0;i < (int) FEntidade_Tiro::ListaTiros.size();i++) {
		if(!FEntidade_Tiro::ListaTiros[i]) continue;
		FEntidade_Tiro::ListaTiros[i]->NaLimpeza();
	}
	FEntidade_Tiro::ListaTiros.clear();
	**/

	SDL_FreeSurface(planoExibicao);
	SDL_Quit();
}
