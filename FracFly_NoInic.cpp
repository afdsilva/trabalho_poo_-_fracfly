/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/

#include "FracFly.h"
/**
 * Metodo de Inicializacao de variaveis, configurações e de carregar recursos
 **/
bool FracFly::NoInic() {
	Excecoes::linhaErro = 6;
	Excecoes::classErro = "FracFly::NoInic";
	Excecoes::msgErro.clear();
	bool retorno = true;

	try {
		//inicializa todos recursos do SDL
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
			Excecoes::msgErro += "Erro SDL_Init ";
			Excecoes::msgErro += SDL_GetError();
			throw Excecoes::TratamentoExcecao();
		}
		//inicializa recurso de fonte
		if( TTF_Init() == -1 ) {
			Excecoes::msgErro += "Erro TTF_Init ";
			Excecoes::msgErro += SDL_GetError();
			throw Excecoes::TratamentoExcecao();
		}
		//* Resolucao da tela
		//const SDL_VideoInfo* myPointer = SDL_GetVideoInfo();
	
		// Print out some information
		// WARNING: myPointer is not NULL here
		//std::cout << "Current video resolution is " << myPointer->current_w << "x" << myPointer->current_h << " pixels" << std::endl;

		SDL_ShowCursor(SDL_DISABLE);

		//inicializa um plano de exibicao, todas outras superficies são criadas em cima dela
		if ((planoExibicao = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
			Excecoes::msgErro += "Não foi possivel criar Plano Exibição ";
			Excecoes::msgErro += SDL_GetError();
			throw Excecoes::TratamentoExcecao();
		}

	
		//SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

		FGerenciadorEstados::SetEstadoAtivo(ESTADO_INTRO);
	
		char cursorArquivo[] =  "res/mira1.png";
		if (cursor.NoCarregar(cursorArquivo,48,48,0) == false) {
			Excecoes::msgErro += "Nao foi possivel carregar imagem do cursor ";
			throw Excecoes::TratamentoExcecao();
		}
		cursor.x = (cursor.width / 2);
		cursor.y = (cursor.height / 2);
		cursor.colBox(cursor.width / 2, cursor.height / 2, cursor.width - 1, cursor.height - 1);
		cursor.flags = ENTIDADE_FLAG_CURSOR | ENTIDADE_FLAG_FANTASMA;
		cursor.tipo = TIPO_ENTIDADE_CURSOR;
	} catch (...) {
		retorno = false;
	}
	
	return retorno;
}
