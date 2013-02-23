#include "FEstadoIntro.h"
#include "FGerenciadorEstados.h"

FEstadoIntro FEstadoIntro::instancia;

FEstadoIntro::FEstadoIntro() {
	logo = NULL;
}

void FEstadoIntro::NaAtivacao() {
	//carrega a logo do estudio :3
	char logoArquivo[] = "res/logo.png";
	logo = FSuperficie::NoCarregar(logoArquivo);
	tempoInicio = SDL_GetTicks();
}

void FEstadoIntro::NaDesativacao() {
	if (logo) {
		SDL_FreeSurface(logo);
		logo = NULL;
	}
}

void FEstadoIntro::NoLaco() {
	if (tempoInicio + 1500 < (int) SDL_GetTicks()) {
		FGerenciadorEstados::SetEstadoAtivo(ESTADO_JOGO);
	}
}

void FEstadoIntro::NaRenderizacao(SDL_Surface * planoExibicao) {
	if (logo) {
		FSuperficie::NoDesenhar(planoExibicao, logo, ((1024 / 2) - (640 / 2)), ((768 / 2) - (480 / 2)));
	}
}

FEstadoIntro * FEstadoIntro::GetInstancia() {
	return &instancia;
}
