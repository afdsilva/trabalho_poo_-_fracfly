#include "FracFly.h"

/**
 * Metodo de limpeza de memoria, libera as superficies e vetores gerados durante o programa;
 **/
void FracFly::NaLimpeza() {

	FGerenciadorEstados::SetEstadoAtivo(ESTADO_NENHUM);
	
	SDL_FreeSurface(planoExibicao);
	SDL_Quit();
}
