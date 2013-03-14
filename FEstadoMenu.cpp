/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/

#include "FEstadoMenu.h"
#include "FGerenciadorEstados.h"

FEstadoMenu FEstadoMenu::instancia;

FEstadoMenu::FEstadoMenu() {
}

void FEstadoMenu::NaAtivacao() {
	Excecoes::linhaErro = 9;
	Excecoes::classErro = "FEstadoMenu::NaAtivacao";
	Excecoes::msgErro.clear();
	estadoSelecionado = 1;
	//carrega o arquivo da fonte que sera usada pelos itens do menu
	try {
		char fundoArquivo[] = "res/ai-star-about-to-be-ripped-apart.jpg";

		if (fundo.NoCarregar(fundoArquivo,1280,720,0) == false) throw Excecoes::TratamentoExcecao();

		fundo.x = (WWIDTH / 2) - (fundo.width / 2);
		fundo.y = (WHEIGHT / 2) - (fundo.height / 2);
		FEntidade::listaEntidades.push_back(&fundo);
		
		
		
		char fonteArq[] = "res/fonts/ShadowsAroundUs.ttf";
		TTF_Font * lazyFontTitulo = NULL;
		TTF_Font * lazyFontItens = NULL;
		if ((lazyFontTitulo = FFonte::NoCarregar(fonteArq, 82)) == NULL) throw Excecoes::TratamentoExcecao();
		if ((lazyFontItens = FFonte::NoCarregar(fonteArq, 40)) == NULL) throw Excecoes::TratamentoExcecao();
			
		//carregou com sucesso a fonte cria entidades que serao os itens do menu
		SDL_Color vermelho = {255,0,0};
		SDL_Color branco = {255,255,255};

		titulo = new FEntidadeTexto();
		if (titulo->NoCarregar(lazyFontTitulo,"Menu",branco) == false) throw Excecoes::TratamentoExcecao();
			titulo->x = 10;
			titulo->y = 150;
			FEntidade::listaEntidades.push_back(titulo);

		iniciar = new FEntidadeBotao();
		if (iniciar->NoCarregar(lazyFontItens,"Iniciar",branco) == false) throw Excecoes::TratamentoExcecao();
			iniciar->x = titulo->x + 20;
			iniciar->y = titulo->y + titulo->height + 40;
			iniciar->flags = ENTIDADE_FLAG_CURSOR ;
			iniciar->AoPassarPorCima(vermelho,1,1);
			iniciar->AoClicarDireito(ESTADO_JOGO);
			iniciar->AoClicarEsquerdo(ESTADO_JOGO);
			FEntidade::listaEntidades.push_back(iniciar);

		options = new FEntidadeBotao();
		if (options->NoCarregar(lazyFontItens,"Opcoes",branco) == false) throw Excecoes::TratamentoExcecao();
			options->x = titulo->x + 20;
			options->y = iniciar->y + iniciar->height + 30;
			options->flags = ENTIDADE_FLAG_CURSOR;
			options->AoPassarPorCima(vermelho,1,1);
			options->AoClicarDireito(ESTADO_OPTIONS);
			options->AoClicarEsquerdo(ESTADO_OPTIONS);
			FEntidade::listaEntidades.push_back(options);

		sair = new FEntidadeBotao();
		if (sair->NoCarregar(lazyFontItens,"Sair",branco) == false) throw Excecoes::TratamentoExcecao();
			sair->x = titulo->x + 20;
			sair->y = options->y + options->height + 30;
			sair->flags = ENTIDADE_FLAG_CURSOR;
			sair->AoPassarPorCima(vermelho,1,1);
			sair->AoClicarDireito(ESTADO_NENHUM);
			sair->AoClicarEsquerdo(ESTADO_NENHUM);
			FEntidade::listaEntidades.push_back(sair);

	} catch (...) {
		FGerenciadorEstados::SetEstadoAtivo(ESTADO_NENHUM);
	}
	
	//srand((int)time(NULL));
	//fundo.NoInic();	
}	

void FEstadoMenu::NaDesativacao() {
	for(int i = 0;i < (int) FEntidade::listaEntidades.size();i++) {
		if(!FEntidade::listaEntidades[i]) continue;
		FEntidade::listaEntidades[i]->NaLimpeza();
	}
	FEntidade::listaEntidades.clear();
}

void FEstadoMenu::NoLaco() {
	//~ fundo.ExecutarFractal();
	for (int i = 0; i < (int) FEntidade::listaEntidades.size(); i++) {
		if(!FEntidade::listaEntidades[i]) continue;
		if (FEntidade::listaEntidades[i]->morto && (int) FEntidade::listaEntidades.size() == i+1) {
			FEntidade::listaEntidades.pop_back();
		}
		FEntidade::listaEntidades[i]->NoLaco();
	}

	switch(estadoSelecionado) {
		case 1:
			iniciar->MudaCor();
			break;
		case 2:
			options->MudaCor();
			break;
		case 3:
			sair->MudaCor();
			break;
	}

	for (int i = 0; i < (int) FEntidadeColisao::listaEntidadesColisoes.size(); i++) {
		FEntidade * entidadeA = FEntidadeColisao::listaEntidadesColisoes[i].entidadeA;
		FEntidade * entidadeB = FEntidadeColisao::listaEntidadesColisoes[i].entidadeB;
		
		if (entidadeA == NULL || entidadeB == NULL) continue;
		
		if (entidadeA->NaColisao(entidadeB)) {
			entidadeB->NaColisao(entidadeA);
		}
	}
	FEntidadeColisao::listaEntidadesColisoes.clear();

	//fundo.ExecutarFractal();
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
		case SDLK_w:
		case SDLK_UP:
			if (estadoSelecionado > 1)
				estadoSelecionado--;
			break;
		case SDLK_s:
		case SDLK_DOWN:
			if (estadoSelecionado < 3)
				estadoSelecionado++;
			break;
		case SDLK_RETURN:
			switch(estadoSelecionado) {
				case 1:
					FGerenciadorEstados::SetEstadoAtivo(ESTADO_JOGO);
					break;
				case 2:
					FGerenciadorEstados::SetEstadoAtivo(ESTADO_OPTIONS);
					break;
				case 3:
					OnExit();
					FGerenciadorEstados::SetEstadoAtivo(ESTADO_NENHUM);
					break;
			}
			break;
		default:
			break;
	}
}

//Evento de movimentação do mouse e cliques enquanto se move
void FEstadoMenu::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
	estadoSelecionado = 0;
}

//Evento de pressionar o botao esquerdo do mouse
void FEstadoMenu::OnLButtonDown(int mX, int mY) {
}
//Evento de soltar o botao esquerdo do mouse
void FEstadoMenu::OnLButtonUp(int mX, int mY) {
}
