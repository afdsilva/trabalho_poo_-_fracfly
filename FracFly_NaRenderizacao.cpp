#include "FracFly.h"

void FracFly::NaRenderizacao() {
	FSuperficie::NoDesenhar(Plano_Exibicao, Surf_bg, 0, 0);
	
	FArea::ControleArea.NaRenderizacao(Plano_Exibicao, FCamera::ControleCamera.GetX(), FCamera::ControleCamera.GetY());
	
	for(int i = 0;i < (int) FEntidade::ListaEntidades.size();i++) {
		if(!FEntidade::ListaEntidades[i]) continue;
		FEntidade::ListaEntidades[i]->NaRenderizacao(Plano_Exibicao);
	}
	for(int i = 0;i < (int) FEntidade_Tiro::ListaTiros.size();i++) {
		if(!FEntidade_Tiro::ListaTiros[i]) continue;
		FEntidade_Tiro::ListaTiros[i]->NaRenderizacao(Plano_Exibicao);
	}

	SDL_Flip(Plano_Exibicao);
}
