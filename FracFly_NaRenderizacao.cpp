#include "FracFly.h"
/**
 * Metodo que faz a magica de desenhar as superficies na tela
 **/
void FracFly::NaRenderizacao() {
	
	//FSuperficie::NoDesenhar(planoExibicao, Surf_bg, 0, 0);
	
	FArea::controleArea.NaRenderizacao(planoExibicao, FCamera::controleCamera.GetX(), FCamera::controleCamera.GetY());
	
	//~ FundoFractal :: Exibir();
	
	for(int i = 0;i < (int) FEntidade::listaEntidades.size();i++) {
		if(!FEntidade::listaEntidades[i]) continue;
		FEntidade::listaEntidades[i]->NaRenderizacao(planoExibicao);
	}
	/**
	for(int i = 0;i < (int) FEntidade_Tiro::listaEntidades.size();i++) {
		if(!FEntidade_Tiro::listaEntidades[i]) continue;
		FEntidade_Tiro::listaEntidades[i]->NaRenderizacao(planoExibicao);
	}
	**/
	
	
	SDL_Flip(planoExibicao);
}
