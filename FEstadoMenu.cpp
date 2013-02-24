#include "FEstadoMenu.h"
#include "FGerenciadorEstados.h"

FEstadoMenu FEstadoMenu::instancia;

FEstadoMenu::FEstadoMenu() {
}

void FEstadoMenu::NaAtivacao() {

	//carrega o arquivo da fonte que sera usada pelos itens do menu
	char fonteArq[] = "res/lazy.ttf";
	try {
		TTF_Font * lazyFontTitulo;
		if ((lazyFontTitulo = FFonte::NoCarregar(fonteArq, 82)) == NULL)
			throw 1;
		TTF_Font * lazyFontItens;
		if ((lazyFontItens = FFonte::NoCarregar(fonteArq, 40)) == NULL)
			throw 1;
			
		//carregou com sucesso a fonte cria entidades que serao os itens do menu

		SDL_Color branco = {255,255,255};
		FEntidade * titulo = new FEntidade();
		if (titulo->NoCarregar(lazyFontTitulo,"Menu",branco)) {
			titulo->x = 10;
			titulo->y = 300;
			FEntidade::listaEntidades.push_back(titulo);
		}
		FEntidade * iniciar = new FEntidade();
		if (iniciar->NoCarregar(lazyFontItens,"Iniciar",branco)) {
			iniciar->x = titulo->x + 20;
			iniciar->y = titulo->y + titulo->height + 10;
			FEntidade::listaEntidades.push_back(iniciar);
		}
		FEntidade * options = new FEntidade();
		if (options->NoCarregar(lazyFontItens,"Opcoes",branco)) {
			options->x = titulo->x + 20;
			options->y = iniciar->y + iniciar->height + 10;
			FEntidade::listaEntidades.push_back(options);
		}
		FEntidade * sair = new FEntidade();
		if (sair->NoCarregar(lazyFontItens,"Sair",branco)) {
			sair->x = titulo->x + 20;
			sair->y = options->y + options->height + 10;
			FEntidade::listaEntidades.push_back(sair);
		}



	} catch (int e) {
		switch(e) {
			case 1:
				debug("FEstadoMenu::Não foi possivel carregar fonte");
				break;
			default:
				break;
		}
		return;
	}
	
	char cursorArquivo[] =  "res/mira1.png";
	if (cursor.NoCarregar(cursorArquivo,48,48,0) == false) {
		return;
	}
	cursor.flags = ENTIDADE_FLAG_ESPACO;
	FEntidade::listaEntidades.push_back(&cursor);


}	

void FEstadoMenu::NaDesativacao() {
	for(int i = 0;i < (int) FEntidade::listaEntidades.size();i++) {
		if(!FEntidade::listaEntidades[i]) continue;
		FEntidade::listaEntidades[i]->NaLimpeza();
	}
	FEntidade::listaEntidades.clear();
}

void FEstadoMenu::NoLaco() {
	for (int i = 0; i < (int) FEntidade::listaEntidades.size(); i++) {
		if(!FEntidade::listaEntidades[i]) continue;
		if (FEntidade::listaEntidades[i]->morto && (int) FEntidade::listaEntidades.size() == i+1) {
			FEntidade::listaEntidades.pop_back();
		}
		FEntidade::listaEntidades[i]->NoLaco();
	}
}

void FEstadoMenu::NaRenderizacao(SDL_Surface * planoExibicao) {
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = WWIDTH;
	rect.h = WHEIGHT;
	
	SDL_FillRect(planoExibicao, &rect, 0);

	for(int i = 0;i < (int) FEntidade::listaEntidades.size();i++) {
		if(!FEntidade::listaEntidades[i]) continue;
		FEntidade::listaEntidades[i]->NaRenderizacao(planoExibicao);
	}
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

//Evento de movimentação do mouse e cliques enquanto se move
void FEstadoMenu::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
	if (mX) {
		cursor.x = mX;
	}
	if (mY) {
		cursor.y = mY;
	}
}

//Evento de pressionar o botao esquerdo do mouse
void FEstadoMenu::OnLButtonDown(int mX, int mY) {
	
	
}
//Evento de soltar o botao esquerdo do mouse
void FEstadoMenu::OnLButtonUp(int mX, int mY) {
	
}
