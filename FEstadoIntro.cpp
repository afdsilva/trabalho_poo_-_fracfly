#include "FEstadoIntro.h"
#include "FGerenciadorEstados.h"

FEstadoIntro FEstadoIntro::instancia;

FEstadoIntro::FEstadoIntro() {
	logo = NULL;
}

void FEstadoIntro::NaAtivacao() {
	Excecoes::msgErro = "FEstadoIntro::NaAtivacao:";
	try {
	//carrega a logo do estudio :3
	char logoArquivo[] = "res/logo.png";
	if ((logo = FSuperficie::NoCarregar(logoArquivo)) == NULL)  {
		Excecoes::msgErro+= " Nao foi possivel carregar arquivo do logotipo ";
		Excecoes::msgErro+= logoArquivo;
	}
	} catch (...) {

	}
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
		FGerenciadorEstados::SetEstadoAtivo(ESTADO_MENU);
	}
}

void FEstadoIntro::NaRenderizacao(SDL_Surface * planoExibicao) {
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = WWIDTH;
	rect.h = WHEIGHT;
	
	//limpa a tela
	SDL_FillRect(planoExibicao, &rect, 0);


	if (logo) {
		FSuperficie::NoDesenhar(planoExibicao, logo, ((WWIDTH / 2) - (640 / 2)), ((WHEIGHT / 2) - (480 / 2)));
	}
}

FEstadoIntro * FEstadoIntro::GetInstancia() {
	return &instancia;
}
