#include "FGerenciadorEstados.h"

//Referencia aos outros estados do jogo
#include "FEstadoIntro.h"
#include "FEstadoMenu.h"
#include "FEstadoJogo.h"

FEstado * FGerenciadorEstados::estadoAtivo = 0;

void FGerenciadorEstados::NoEvento(SDL_Event * mantedorEvento) {
	if(estadoAtivo) estadoAtivo->NoEvento(mantedorEvento);
}

void FGerenciadorEstados::NoLaco() {
	if(estadoAtivo) estadoAtivo->NoLaco();
}

void FGerenciadorEstados::NaRenderizacao(SDL_Surface * planoExibicao) {
	if(estadoAtivo) estadoAtivo->NaRenderizacao(planoExibicao);
}

void FGerenciadorEstados::SetEstadoAtivo(int estadoId) {
	if (estadoAtivo) estadoAtivo->NaDesativacao();
	
	//Adicionar os outros estados no switch
	switch(estadoId) {
		case ESTADO_NENHUM:
			estadoAtivo = 0;
			break;
		case ESTADO_INTRO:
			estadoAtivo = FEstadoIntro::GetInstancia();
			break;
		case ESTADO_MENU:
			estadoAtivo = FEstadoMenu::GetInstancia();
			break;
/**
		case ESTADO_OPTIONS:
			estadoAtivo = FEstadoOptions::GetInstancia();
			break;
**/
		case ESTADO_JOGO:
			estadoAtivo = FEstadoJogo::GetInstancia();
			break;
	}
	
	if (estadoAtivo) estadoAtivo->NaAtivacao();
}

FEstado * FGerenciadorEstados::GetEstadoAtivo() {
	return estadoAtivo;
}

int FGerenciadorEstados::GetEstadoAtivoId() {
	if (estadoAtivo == FEstadoIntro::GetInstancia()) {
		return ESTADO_INTRO;
	}
	else if (estadoAtivo == FEstadoMenu::GetInstancia()) {
		return ESTADO_MENU;
	}
	else if (estadoAtivo == FEstadoJogo::GetInstancia()) {
		return ESTADO_JOGO;
	}
	else {
		return ESTADO_NENHUM;
	}
}
