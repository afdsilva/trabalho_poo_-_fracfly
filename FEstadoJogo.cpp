#include "FEstadoJogo.h"
#include "FGerenciadorEstados.h"

FEstadoJogo FEstadoJogo::instancia;

FEstadoJogo::FEstadoJogo() {
}

void FEstadoJogo::NaAtivacao() {
	//carrega fundo
	try {
		char fundoArquivo[] = "res/ai-star-about-to-be-ripped-apart.jpg";
		if (fundo.NoCarregar(fundoArquivo,4945,3672,0) == false)
			throw 1;

		//fundo.x = FCamera::controleCamera.GetX();
		fundo.x = (WWIDTH / 2) - (fundo.width / 2);
		//fundo.y = FCamera::controleCamera.GetY();
		fundo.y = (WHEIGHT / 2) - (fundo.height / 2);
		fundoZoom = 1;

		//carrega a cabine da nave
		char naveArquivo[] = "res/modelo_cabine_novo_720p.png";
		if (jogador.NoCarregar(naveArquivo, WWIDTH, WHEIGHT, 0) == false) {
			throw 1;
		}
		//jogador.Escalonar(-10);

		char armaArquivo[] =  "res/canhao.png";
		if (arma1.NoCarregar(armaArquivo,197,411,0) == false) {
			throw 1;
		}
		if (arma2.NoCarregar(armaArquivo,197,411,0) == false) {
			throw 1;
		}

		char fonteArq[] = "res/lazy.ttf";
		try {
			TTF_Font * lazyFontTitulo;
			if ((lazyFontTitulo = FFonte::NoCarregar(fonteArq, 82)) == NULL)
				throw 1;
			TTF_Font * lazyFontItens;
			if ((lazyFontItens = FFonte::NoCarregar(fonteArq, 18)) == NULL)
				throw 1;
			SDL_Color branco = {255,255,255};

			if (escore.NoCarregar(lazyFontItens,"Escore: 0",branco)) {
				escore.x = 10;
				escore.y = 10;
				escore.z += 500;
				FEntidade::listaEntidades.push_back(&escore);
			}
		} catch(int e) {
			debug("Error");
		}

		arma1.oX = 30;
		arma1.oY = WHEIGHT - (arma1.height /2);
		arma1.x = arma1.oX;
		arma1.y = arma1.oY;
		arma1.z+= 50;

		arma2.oX = WWIDTH - (arma1.oX + arma2.width);
		arma2.oY = WHEIGHT - (arma2.height /2);
		arma2.x = arma1.oX;
		arma2.y = arma2.oY;
		arma2.z+= 50;

		arma1.flags = ENTIDADE_FLAG_ESPACO;
		arma2.flags = ENTIDADE_FLAG_ESPACO;
		jogador.flags = ENTIDADE_FLAG_ESPACO;
		jogador.z+= 100;

		cursor.z+= 1000;
		fundo.z =0;
		FEntidade::listaEntidades.push_back(&fundo);

		FEntidade::listaEntidades.push_back(&jogador);

		FEntidade::listaEntidades.push_back(&arma1);
		FEntidade::listaEntidades.push_back(&arma2);


		FCamera::controleCamera.modoAlvo = MODO_ALVO_NORMAL;
		FCamera::controleCamera.SetAlvo(&(jogador.x), &jogador.y);

	} catch (int e) {
		debug("Erro");
	}

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
	string escoreStr = "Escore: ";
	escoreStr.append(itoa(jogador.GetEscore() ) );
	escore.MudaTexto(escoreStr);

	//movimentacao do fundo (meio pog)
	if (jogador.moveEsquerda && fundo.x <= 0)
		fundo.x += 100 * FFPS::FPSControle.GetFatorVelocidade();
		//fundo.x += jogador.GetAcelX() * FFPS::FPSControle.GetFatorVelocidade();
	while( fundo.x >= 0)
		fundo.x -= 1;
	if (jogador.moveDireita && fundo.x >= -(fundo.width - WWIDTH))
		fundo.x -= 100 * FFPS::FPSControle.GetFatorVelocidade();
		//fundo.x -= jogador.GetAcelX() * FFPS::FPSControle.GetFatorVelocidade();
	while( fundo.x <= -(fundo.width - WWIDTH))
		fundo.x += 1;



	if (jogador.moveCima && fundo.y <= 0)
		fundo.y += 100 * FFPS::FPSControle.GetFatorVelocidade();
		//fundo.y -= jogador.GetAcelY() * FFPS::FPSControle.GetFatorVelocidade();
	while( fundo.y >= 0)
		fundo.y -= 1;
	if (jogador.moveBaixo && fundo.y >= -(fundo.height - WHEIGHT))
		fundo.y -= 100 * FFPS::FPSControle.GetFatorVelocidade();
		//fundo.y += jogador.GetAcelY() * FFPS::FPSControle.GetFatorVelocidade();
	while( fundo.y <= -(fundo.height- WHEIGHT))
		fundo.y += 1;



	//chama cada entidade na lista de entidades, utilizando o metodo apropriado para as entidades no FEntidade.cpp
	for (int i = 0; i < (int) FEntidade::listaEntidades.size(); i++) {
		if(!FEntidade::listaEntidades[i]) continue;
		if (FEntidade::listaEntidades[i]->morto && (int)FEntidade::listaEntidades.size() == i+1) {
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
	if (arma1.angulo > 360) arma1.angulo -= 360;
	if (arma1.angulo < -360) arma1.angulo += 360;
	/** for invertido para renderizar o cockpit na frente, nao sera mais utilizado, pq foi implementado o z
	for(int i = (int) FEntidade::listaEntidades.size()-1;i >= 0;i--) {
		if(FEntidade::listaEntidades[i]->morto) continue;
		FEntidade::listaEntidades[i]->NaRenderizacao(planoExibicao);
	}
	**/
	for(int i = 0;i < (int) FEntidade::listaEntidades.size();i++) {
		if(FEntidade::listaEntidades[i]->morto) continue;
		FEntidade::listaEntidades[i]->NaRenderizacao(planoExibicao);
	}

	FArea::controleArea.NaRenderizacao(planoExibicao, -FCamera::controleCamera.GetX(), -FCamera::controleCamera.GetY());

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
		case SDLK_f:
			fundoZoom-= 0.01;
			fundo.RotaZoom((double)0,fundoZoom,0,0,0);
			break;
		case SDLK_v:
			fundoZoom+= 0.01;
			fundo.RotaZoom((double)0,fundoZoom,0,0,0);
			break;

		default:
			break;
	}
}

//Evento de movimentação do mouse e cliques enquanto se move
void FEstadoJogo::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
	double dist1 = sqrt(pow(mX - ((arma1.x+arma1.width)/2) ,2) + pow(mY - ((arma1.y+arma1.height)/2),2));
	double dist2 = sqrt(pow(mX - ((arma1.x+arma1.width)/2),2) + pow(mY - ((arma1.y+arma1.height)/2),2));

	double dy1 = (double) ((arma1.y + arma1.height) / 2) - mY;
	double dy2 = (double) ((arma2.y + arma2.height) / 2) - mY;

	double ang1 = -(double)( 45 * (dy1/dist1));
	double ang2 = (double)( 45 * (dy2/dist2));
	if (arma1.angulo != ang1)
		arma1.Rotacionar(ang1, 0, 0);
	//arma2.Rotacionar(ang2, (arma2.x+arma2.width) / 2, arma2.y+arma2.height);
	if (arma2.angulo != ang2)
		arma2.Rotacionar(ang2, 0, 0);

	arma1.angulo = ang1;
	arma2.angulo = ang2;

}
//Evento de pressionar o botao esquerdo do mouse
void FEstadoJogo::OnLButtonDown(int mX, int mY) {
	//Arma1.Atirar(mX,mY);

	jogador.Atirar(&arma1, arma1.x+(arma1.width / 2), arma1.y + (arma1.height / 2), mX, mY);
	int setScore = jogador.GetEscore();
	jogador.SetEscore(setScore+1);
}
//Evento de soltar o botao esquerdo do mouse
void FEstadoJogo::OnLButtonUp(int mX, int mY) {
	
}
//Evento de pressionar o botao direito do mouse
void FEstadoJogo::OnRButtonDown(int mX, int mY) {
	jogador.Atirar(&arma2, arma2.x+(arma2.width / 2), arma2.y + (arma2.height / 2), mX, mY);
	int setScore = jogador.GetEscore();
	jogador.SetEscore(setScore+1);
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
