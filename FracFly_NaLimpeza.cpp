#include "FracFly.h"

/**
 * Metodo de limpeza de memoria, libera as superficies e vetores gerados durante o programa;
 **/
void FracFly::NaLimpeza() {

	FGerenciadorEstados::SetEstadoAtivo(ESTADO_NENHUM);
	
	cursor.NaLimpeza();
	
	SDL_FreeSurface(planoExibicao);
	TTF_Quit();
	SDL_Quit();
}
