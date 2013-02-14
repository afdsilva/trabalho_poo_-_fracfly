#include "FracFly.h"

#define FPS 60
Uint16 waittime = 1000.0f/FPS;
Uint16 framestarttime = 0;
Sint16 delaytime;

void FracFly::NoLaco() {
	
	for(int i = 0;i < (int) FEntidade::ListaEntidades.size();i++) {
		if(!FEntidade::ListaEntidades[i]) continue;
		FEntidade::ListaEntidades[i]->NoLaco();
	}
	/**
	for(int i = 0;i < (int) FEntidade_Arma::ListaTiros.size();i++) {
		if(!FEntidade_Arma::ListaTiros[i]) continue;
		FEntidade_Arma::ListaTiros[i]->NaRenderizacao(Plano_Exibicao);
	}
	**/
	//Reduz o consumo de CPU adicionando um delay
	delaytime = waittime - (SDL_GetTicks() - framestarttime);
    if(delaytime > 0)
        SDL_Delay((Uint16)delaytime);
    framestarttime = SDL_GetTicks();
}
