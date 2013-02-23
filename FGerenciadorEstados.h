#ifndef _FGERENCIADORESTADOS_H_
	#define _FGERENCIADORESTADOS_H_

#include "FEstado.h"

enum {
	ESTADO_NENHUM,
	ESTADO_INTRO,
	ESTADO_MENU,
	ESTADO_MENU_OPTIONS,
	ESTADO_JOGO,
};

class FGerenciadorEstados {
	private:
		static FEstado * estadoAtivo;
		
	public:
		static void NoEvento(SDL_Event * evento);
		static void NoLaco();
		static void NaRenderizacao(SDL_Surface * planoExibicao);
	
	public:
		static void SetEstadoAtivo(int estadoId);
		static FEstado * GetEstadoAtivo();
};

#endif
