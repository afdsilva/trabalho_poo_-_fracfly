#include "FEstadoJogo.h"
#include "FGerenciadorEstados.h"

FEstadoJogo FEstadoJogo::instancia;

FEstadoJogo::FEstadoJogo() {
}

void FEstadoJogo::NaAtivacao() {
	//carrega a cabine da nave
	char naveArquivo[] = "res/cabine1024x768.png";
	if (jogador.NoCarregar(naveArquivo, 1024, 768, 0) == false) {
		return;
	}
	char cursorArquivo[] =  "res/mira1.png";
	if (cursor.NoCarregar(cursorArquivo,48,48,0) == false) {
		return;
	}

	char armaArquivo[] =  "res/arma.png";
	if (arma1.NoCarregar(armaArquivo,80,537,0) == false) {
		return;
	}
	if (arma2.NoCarregar(armaArquivo,80,537,0) == false) {
		return;
	}
	arma1.x = 90;
	arma1.y = WHEIGHT - (arma1.height / 2);

	arma2.x = WWIDTH - 170;
	arma2.y = WHEIGHT - (arma2.height / 2);

	cursor.flags = ENTIDADE_FLAG_ESPACO;
	arma1.flags = ENTIDADE_FLAG_ESPACO;
	arma2.flags = ENTIDADE_FLAG_ESPACO;
	jogador.flags = ENTIDADE_FLAG_ESPACO;


	//Coloca o cursor na lista de entidades, mas ele sera tratado de forma independente
	FEntidade::listaEntidades.push_back(&cursor);

	FEntidade::listaEntidades.push_back(&arma1);
	FEntidade::listaEntidades.push_back(&arma2);
	FEntidade::listaEntidades.push_back(&jogador);
	//jogador.x = jogador.x + (1024 / 2);
	FCamera::controleCamera.modoAlvo = MODO_ALVO_NORMAL;
	FCamera::controleCamera.SetAlvo(&(jogador.x), &jogador.y);

}

void FEstadoJogo::NaDesativacao() {
	
	//FArea::controleArea.NaLimpeza();

	for(int i = 0;i < (int) FEntidade::listaEntidades.size();i++) {
		if(!FEntidade::listaEntidades[i]) continue;
		FEntidade::listaEntidades[i]->NaLimpeza();
	}
	FEntidade::listaEntidades.clear();
	
}

void FEstadoJogo::NoLaco() {
	//Controla o cursor do mouse

	//chama cada entidade na lista de entidades, utilizando o metodo apropriado para as entidades no FEntidade.cpp
	for (int i = 0; i < (int) FEntidade::listaEntidades.size(); i++) {
		//como a lista de entidades é um vetor, esse vetor pode ter buracos
		//o if abaixo impede que seja feitas chamadas desnecessarias quando nao existe mais o objeto no vetor
		if(!FEntidade::listaEntidades[i]) continue;
		//reduz o tamanho do vetor se verifica que o ultimo estado da lista é morto, ajuda (espero) na limpeza de objetos
		if (FEntidade::listaEntidades[i]->morto && (int) FEntidade::listaEntidades.size() == i+1) {
			FEntidade::listaEntidades.pop_back();
		}
		//chama o metodo NoLaco() do objeto, definido no FEntidade.cpp
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
	FEntidadeColisao::listaEntidadesColisoes.clear();
	
}

void FEstadoJogo::NaRenderizacao(SDL_Surface * planoExibicao) {
	//FSuperficie::NoDesenhar(planoExibicao, Surf_bg, 0, 0);
	//~ FundoFractal :: Exibir();
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = WWIDTH;
	rect.h = WHEIGHT;
	
	SDL_FillRect(planoExibicao, &rect, 0);
	
	FArea::controleArea.NaRenderizacao(planoExibicao, -FCamera::controleCamera.GetX(), -FCamera::controleCamera.GetY());
	
	for(int i = 0;i < (int) FEntidade::listaEntidades.size();i++) {
		if(!FEntidade::listaEntidades[i]) continue;
		FEntidade::listaEntidades[i]->NaRenderizacao(planoExibicao);
	}
}

FEstadoJogo * FEstadoJogo::GetInstancia() {
	return &instancia;
}


//Evento de tecla pressionada
void FEstadoJogo::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
		case SDLK_ESCAPE: //Esc
			FGerenciadorEstados::SetEstadoAtivo(ESTADO_MENU);
			break;
		case SDLK_a:
			jogador.moveEsquerda = true;
			break;
		case SDLK_d:
			jogador.moveDireita = true;
			break;
		case SDLK_w:
			jogador.moveCima = true;
			break;
		case SDLK_s:
			jogador.moveBaixo = true;
			break;
		default:
			break;
	}
}
//Evento de soltar a tecla pressionada
void FEstadoJogo::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
		case SDLK_a:
			jogador.moveEsquerda = false;
			break;
		case SDLK_d:
			jogador.moveDireita = false;
			break;
		case SDLK_w:
			jogador.moveCima = false;
			break;
		case SDLK_s:
			jogador.moveBaixo = false;
			break;
		default:
			break;
	}
}

//Evento de movimentação do mouse e cliques enquanto se move
void FEstadoJogo::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
	if (mX) {
		cursor.x = mX;
	}
	if (mY) {
		cursor.y = mY;
	}
}
//Evento de pressionar o botao esquerdo do mouse
void FEstadoJogo::OnLButtonDown(int mX, int mY) {
	//Arma1.Atirar(mX,mY);
	jogador.Atirar(&arma1, mX, mY);
}
//Evento de soltar o botao esquerdo do mouse
void FEstadoJogo::OnLButtonUp(int mX, int mY) {
	
}
//Evento de pressionar o botao direito do mouse
void FEstadoJogo::OnRButtonDown(int mX, int mY) {
	jogador.Atirar(&arma2, mX, mY);
}
//Evento de soltar o botao direito do mouse
void FEstadoJogo::OnRButtonUp(int mX, int mY) {
	
}
//Evento de pressionar o botao do meio do mouse
void FEstadoJogo::OnMButtonDown(int mX, int mY) {
	
}
//Evento de soltar o botao do meio do mouse
void FEstadoJogo::OnMButtonUp(int mX, int mY) {
	
}
