#include "FracFly.h"
/**
 * Metodo de Inicializacao de variaveis, configurações e de carregar recursos
 **/
bool FracFly::NoInic() {
	//inicializa todos recursos do SDL
	try {
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
			throw;
	} catch (...) {
		string msgErro = "FracFly::NoInic: Erro SDL_Init ";
		msgErro += SDL_GetError();
		debug(msgErro);
		return false;
	}
	try {
		if( TTF_Init() == -1 )
			throw;
	} catch (...) {
		string msgErro = "FracFly::NoInic: Erro TTF_Init ";
		msgErro += SDL_GetError();
		debug(msgErro);
		return false;
	}
	//* Resolucao da tela
	//const SDL_VideoInfo* myPointer = SDL_GetVideoInfo();

	// Print out some information
	// WARNING: myPointer is not NULL here
	//std::cout << "Current video resolution is " << myPointer->current_w << "x" << myPointer->current_h << " pixels" << std::endl;
	
	SDL_ShowCursor(SDL_DISABLE);
	
	//inicializa um plano de exibicao, todas outras superficies são criadas em cima dela
	try {
		if ((planoExibicao = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
			throw;
	} catch (...) {
		string msgErro = "FracFly::NoInic: Não foi possivel criar Plano Exibição ";
		msgErro += SDL_GetError();
		debug(msgErro);
		return false;
	}

	
	//SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);
	
	FGerenciadorEstados::SetEstadoAtivo(ESTADO_INTRO);

	char cursorArquivo[] =  "res/mira1.png";
	try {
		if (cursor.NoCarregar(cursorArquivo,48,48,0) == false)
			throw;
		cursor.x = (cursor.width / 2);
		cursor.y = (cursor.height / 2);
		cursor.colBox(cursor.width / 2, cursor.height / 2, cursor.width - 1, cursor.height - 1);
		cursor.flags = ENTIDADE_FLAG_CURSOR | ENTIDADE_FLAG_FANTASMA;
		cursor.tipo = TIPO_ENTIDADE_CURSOR;
	} catch (...) {
		debug("FracFly::NoInic: Nao foi possivel carregar cursor",39);
	}
	
	return true;
}
