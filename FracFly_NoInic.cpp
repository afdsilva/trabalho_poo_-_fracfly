#include "FracFly.h"
/**
 * Metodo de Inicializacao de variaveis, configurações e de carregar recursos
 **/
bool FracFly::NoInic() {
	//inicializa todos recursos do SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("NoInic: Não foi possivel Inicializar SDL\n");
		return false;
	}
	//* Resolucao da tela
	//const SDL_VideoInfo* myPointer = SDL_GetVideoInfo();

	// Print out some information
	// WARNING: myPointer is not NULL here
	//std::cout << "Current video resolution is " << myPointer->current_w << "x" << myPointer->current_h << " pixels" << std::endl;
	
	SDL_ShowCursor(SDL_DISABLE);
	
	//inicializa um plano de exibicao, todas outras superficies são criadas em cima dela
	if ((planoExibicao = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		printf("NoInic: Não foi possivel criar Plano Exibição\n");
		return false;
	}

    if( TTF_Init() == -1 ) {
		cout << "Erro TTF_Init " << SDL_GetError() << endl;
        return false;
    }
	
	//SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);
	
	FGerenciadorEstados::SetEstadoAtivo(ESTADO_INTRO);

	return true;
}
