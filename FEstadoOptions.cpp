/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/

#include "FEstadoOptions.h"
#include "FGerenciadorEstados.h"

FEstadoOptions FEstadoOptions::instancia;

FEstadoOptions::FEstadoOptions() {
}

void FEstadoOptions::NaAtivacao() {
	Excecoes::linhaErro = 9;
	Excecoes::classErro = "FEstadoOptions::NaAtivacao";
	Excecoes::msgErro.clear();
	estadoSelecionado = 1;
	

	try {
		// Carrega fundo
		char fundoArquivo[] = "res/ai-star-about-to-be-ripped-apart.jpg";

		if (fundo.NoCarregar(fundoArquivo,6000,3000,0) == false) throw Excecoes::TratamentoExcecao();

		fundo.x = (WWIDTH / 2) - (fundo.width / 2);
		fundo.y = (WHEIGHT / 2) - (fundo.height / 2);
		FEntidade::listaEntidades.push_back(&fundo);
		
		//carrega o arquivo da fonte que sera usada pelos itens do menu
		char fonteArq[] = "res/fonts/ShadowsAroundUs.ttf";
		TTF_Font * lazyFontTitulo = NULL;
		TTF_Font * lazyFontItens = NULL;
		if ((lazyFontTitulo = FFonte::NoCarregar(fonteArq, 82)) == NULL) throw Excecoes::TratamentoExcecao();
		if ((lazyFontItens = FFonte::NoCarregar(fonteArq, 40)) == NULL) throw Excecoes::TratamentoExcecao();

		//carregou com sucesso a fonte cria entidades que serao os itens do menu
		SDL_Color vermelho = {255,0,0};
		SDL_Color branco = {255,255,255};

		titulo = new FEntidadeTexto();
		if (titulo->NoCarregar(lazyFontTitulo,"Options",branco) == false) throw Excecoes::TratamentoExcecao();
			titulo->x = 10;
			titulo->y = 150;
			FEntidade::listaEntidades.push_back(titulo);

		voltar = new FEntidadeBotao();
		if (voltar->NoCarregar(lazyFontItens,"Voltar",branco) == false) throw Excecoes::TratamentoExcecao();
			voltar->x = titulo->x + 20;
			voltar->y = titulo->y + titulo->height + 40;
			voltar->flags = ENTIDADE_FLAG_CURSOR ;
			voltar->AoPassarPorCima(vermelho,1,1);
			voltar->AoClicarDireito(ESTADO_MENU);
			voltar->AoClicarEsquerdo(ESTADO_MENU);
			FEntidade::listaEntidades.push_back(voltar);

	} catch (...) {
		FGerenciadorEstados::SetEstadoAtivo(ESTADO_NENHUM);
	}
}	

void FEstadoOptions::NaDesativacao() {
	for(int i = 0;i < (int) FEntidade::listaEntidades.size();i++) {
		if(!FEntidade::listaEntidades[i]) continue;
		FEntidade::listaEntidades[i]->NaLimpeza();
	}
	FEntidade::listaEntidades.clear();
}

void FEstadoOptions::NoLaco() {
	//~ fundo.ExecutarFractal();
	for (int i = 0; i < (int) FEntidade::listaEntidades.size(); i++) {
		if(!FEntidade::listaEntidades[i]) continue;
		if (FEntidade::listaEntidades[i]->morto && (int) FEntidade::listaEntidades.size() == i+1) {
			FEntidade::listaEntidades.pop_back();
		}
		FEntidade::listaEntidades[i]->NoLaco();
	}

	for (int i = 0; i < (int) FEntidadeColisao::listaEntidadesColisoes.size(); i++) {
		FEntidade * entidadeA = FEntidadeColisao::listaEntidadesColisoes[i].entidadeA;
		FEntidade * entidadeB = FEntidadeColisao::listaEntidadesColisoes[i].entidadeB;
		
		if (entidadeA == NULL || entidadeB == NULL) continue;
		
		if (entidadeA->NaColisao(entidadeB)) {
			entidadeB->NaColisao(entidadeA);
		}
	}

	switch(estadoSelecionado) {
		case 1:
			voltar->MudaCor();
			break;
	}

	FEntidadeColisao::listaEntidadesColisoes.clear();

	//fundo.ExecutarFractal();
}

void FEstadoOptions::NaRenderizacao(SDL_Surface * planoExibicao) {
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

FEstadoOptions * FEstadoOptions::GetInstancia() {
	return &instancia;
}

void FEstadoOptions::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
		case SDLK_ESCAPE: //Esc
			OnExit();
			FGerenciadorEstados::SetEstadoAtivo(ESTADO_MENU);
			break;
		case SDLK_w:
		case SDLK_UP:
			if (estadoSelecionado > 1)
				estadoSelecionado--;
			break;
		case SDLK_s:
		case SDLK_DOWN:
			if (estadoSelecionado < 1)
				estadoSelecionado++;
			break;
		case SDLK_RETURN:
			switch(estadoSelecionado) {
				case 1:
					FGerenciadorEstados::SetEstadoAtivo(ESTADO_MENU);
					break;
			}
			break;
		default:
			break;
	}
}

//Evento de movimentação do mouse e cliques enquanto se move
void FEstadoOptions::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
	estadoSelecionado = 0;
}

//Evento de pressionar o botao esquerdo do mouse
void FEstadoOptions::OnLButtonDown(int mX, int mY) {
}
//Evento de soltar o botao esquerdo do mouse
void FEstadoOptions::OnLButtonUp(int mX, int mY) {
}
