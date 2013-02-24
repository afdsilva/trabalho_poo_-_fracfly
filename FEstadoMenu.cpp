#include "FEstadoMenu.h"
#include "FGerenciadorEstados.h"

FEstadoMenu FEstadoMenu::instancia;

FEstadoMenu::FEstadoMenu() {
}

void FEstadoMenu::NaAtivacao() {

	char fonteArq[] = "res/lazy.ttf";
	if ((fonte = FFonte::NoCarregar(fonteArq, 100)) == NULL) {
		return;
	}
}	

void FEstadoMenu::NaDesativacao() {
}

void FEstadoMenu::NoLaco() {
}

void FEstadoMenu::NaRenderizacao(SDL_Surface * planoExibicao) {

	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = WWIDTH;
	rect.h = WHEIGHT;
	
	SDL_FillRect(planoExibicao, &rect, 0);
	
	SDL_Color cor = {255,255,255};
	char mensagem[] = "Menu";
	int widthFont, heightFont;
    
    if (TTF_SizeText(fonte, mensagem, &widthFont, & heightFont) == -1) {
		//cout << "Erro SizeText " << SDL_GetError() << endl;
	}

	FFonte::NoEscrever(planoExibicao, fonte, mensagem, (WWIDTH / 2) - (widthFont / 2), 0, cor);
	
}

FEstadoMenu * FEstadoMenu::GetInstancia() {
	return &instancia;
}

void FEstadoMenu::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
		case SDLK_ESCAPE: //Esc
			OnExit();
			FGerenciadorEstados::SetEstadoAtivo(ESTADO_NENHUM);
			break;
		case SDLK_RETURN:
			FGerenciadorEstados::SetEstadoAtivo(ESTADO_JOGO);
			break;
		default:
			break;
	}
}
