/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/

#ifndef _FGERENCIADORESTADOS_H_
	#define _FGERENCIADORESTADOS_H_

#include "FEstado.h"
#include "Definicoes.h"

enum {
	ESTADO_NENHUM = 0,
	ESTADO_INTRO,
	ESTADO_MENU,
	ESTADO_OPTIONS,
	ESTADO_JOGO
};

class FGerenciadorEstados {
	private:
		static FEstado * estadoAtivo;
		
	public:
		static void NoEvento(SDL_Event * evento);
		static void NoLaco();
		static void NaRenderizacao(SDL_Surface * planoExibicao);
	
	public:
		void OnExit();
	
	public:
		static void SetEstadoAtivo(int estadoId);
		static FEstado * GetEstadoAtivo();
		static int GetEstadoAtivoId();
};

#endif
