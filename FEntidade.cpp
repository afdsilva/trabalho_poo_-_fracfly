#include "FGerenciadorEstados.h"

#include "FEntidade.h"

/**
 * Inicializacao das Listas de Entidades
 **/
std::vector<FEntidade*> FEntidade::listaEntidades;

/**
 * Inicializa uma entidade
 **/
FEntidade::FEntidade() {

	superficieEntidade = NULL;
	superficieEntidade_Original = NULL;
	x = 0;
	y = 0;
	z = 1000;
	oX = 0;
	oY = 0;
	angulo = 0;
	
	movePraX = 0;
	movePraY = 0;
	
	width = 0;
	height = 0;
	
	moveCima = false;
	moveBaixo = false;
	moveDireita = false;
	moveEsquerda = false;
	
	tipo = TIPO_ENTIDADE_GENERICO;
	
	clique = false;
	morto = false;
	flags = ENTIDADE_FLAG_NONE;
	
	velX = 0;
	velY = 0;
	
	acelX = 0;
	acelY = 0;
	
	velMaxX = 5;
	velMaxY = 5;
	
	frameAtualCol = 0;
	frameAtualLinha = 0;
	
	colX = 0;
	colY = 0;
	colWidth = 0;
	colHeight = 0;

}

/**
 * Destrutor de uma entidade
 **/
FEntidade::~FEntidade() {
	this->NaLimpeza();
}

/**
 * Carrega um recurso na entidade (uma imagem)
 **/
bool FEntidade::NoCarregar (char * arquivo, int width, int height, int maxFrames) {
	Excecoes::linhaErro = 70;
	Excecoes::classErro = "FEntidade::NoCarregar";
	Excecoes::msgErro.clear();
	bool retorno = true;
	try {
		if ((superficieEntidade = FSuperficie::NoCarregar(arquivo)) == NULL) throw Excecoes::TratamentoExcecao();
		if ((superficieEntidade_Original = FSuperficie::NoCarregar(arquivo)) == NULL) throw Excecoes::TratamentoExcecao();

		//FSuperficie::Transparencia(superficieEntidade, 255, 0, 255);
		//FSuperficie::Transparencia(superficieEntidade_Original, 255, 0, 255);

		this->width = width;
		this->height = height;
	
		controleAnimacao.maxFrames = maxFrames;
	} catch (...) {
		retorno = false;
	}
	
	return retorno;
}


/**
 * Controla o fluxo de dados da entidade durante o Laço
 **/
void FEntidade::NoLaco() {
	//PararMovimento();
	switch(tipo) {
		case TIPO_ENTIDADE_GENERICO:
			if (flags & ENTIDADE_FLAG_GRAVIDADE) {
				acelY = 0.75f;
			}
		
			break;
		case TIPO_ENTIDADE_JOGADOR:
			break;
		case TIPO_ENTIDADE_TEXTO:
			break;
		case TIPO_ENTIDADE_CURSOR:
			break;
		case TIPO_ENTIDADE_TIRO:
			float distancia = 0;
			
			distancia = sqrt((float)pow( (this->x < movePraX ? movePraX - this->x : -movePraX + this->x) ,2) + (float)pow((this->y > movePraY ? movePraY - this->y : -movePraY + this->y),2));

			//printf("distancia: %f\n", distancia);
			acelX = (this->x < movePraX ? 1 : -1) * ((float)(x > movePraX ? x - movePraX : (-x + movePraX)) / (float) distancia);
			//acelX = (x - movePraX) / distancia;
			acelY = (this->y > movePraY ? 1 : -1) * ((float)(y < movePraY ? y - movePraY : (-y + movePraY)) / (float) distancia);

			if (velX > 0) {
				if (x >= movePraX) morto = true;
			} else if (velX < 0) {
				if (x <= movePraX) morto = true;
			}
			if (velY > 0) {
				if (y >= movePraY) morto = true;
			} else if (velY < 0) {
				if (y <= movePraY) morto = true;
			}
			break;
	}

	velX += acelX * FFPS::FPSControle.GetFatorVelocidade();
	velY += acelY * FFPS::FPSControle.GetFatorVelocidade();

	if (velX > velMaxX) 	velX = velMaxX;
	if (velX < -velMaxX) 	velX = -velMaxX;
	if (velY > velMaxY)		velY = velMaxY;
	if (velY < -velMaxY)	velY = -velMaxY;
	
	NaAnimacao();
	NoMovimento(velX, velY);

	if (morto)
		NaLimpeza();
}

/** 
 * Método para ordenar as entidades pelo parâmetro z
 **/ 
void FEntidade::OrdenaProfundidade(int esquerda, int direita) {
	int r;
	int i, j;
	FEntidade * entidadeAux;

	if (direita > esquerda) {

		i = esquerda;
		//Reordena as entidades pelo atributo Z
		for (j = esquerda + 1; j <= direita; ++j) {
			if ( FEntidade::listaEntidades[j]->z < FEntidade::listaEntidades[esquerda]->z ) {
				++i;
				entidadeAux = FEntidade::listaEntidades[i];
				FEntidade::listaEntidades[i] = FEntidade::listaEntidades[j];
				FEntidade::listaEntidades[j] = entidadeAux;  
			}
		}
		
		entidadeAux = FEntidade::listaEntidades[esquerda];
		FEntidade::listaEntidades[esquerda] = FEntidade::listaEntidades[i];
		FEntidade::listaEntidades[i] = entidadeAux;
		r = i;
		
		OrdenaProfundidade(esquerda, r - 1);
		OrdenaProfundidade(r + 1, direita);
	}
}

/**
 * Controla a renderização na tela da entidade
 **/
void FEntidade::NaRenderizacao(SDL_Surface * planoExibicao) {
	Excecoes::linhaErro = 184;
	Excecoes::classErro = "FEntidade::NaRenderizacao";
	Excecoes::msgErro.clear();
	try {
		if (planoExibicao == NULL) throw Excecoes::TratamentoExcecao();
		if (superficieEntidade != NULL) {
			if ((FSuperficie::NoDesenhar(planoExibicao,
			superficieEntidade, x - FCamera::controleCamera.GetX(),
			y - FCamera::controleCamera.GetY(),
			frameAtualCol * width,
			(frameAtualLinha + controleAnimacao.GetFrameAtual()) * height, width, height)
			) == false) throw Excecoes::TratamentoExcecao();
		}
	} catch (int e) {
		return;
	}
	return;
}
/**
 * Coletor de Lixo da entidade
 **/
void FEntidade::NaLimpeza() {
	if(superficieEntidade)
		SDL_FreeSurface(superficieEntidade);
	if(superficieEntidade_Original)
		SDL_FreeSurface(superficieEntidade_Original);
	superficieEntidade = NULL;
	superficieEntidade_Original = NULL;
}

/**
 * Controle de Animação da entidade
 **/
void FEntidade::NaAnimacao() {
	if (moveEsquerda) {
		frameAtualCol = 0;
	} else if (moveDireita) {
		frameAtualCol = 1;
	}
	controleAnimacao.NaAnimacao();
}

/**
 * Controle de Colisão da entidade
 **/
bool FEntidade::NaColisao(FEntidade * entidade) {
	return true;
}

/**
 * Metodo para movimentar a entidade na tela
 **/
void FEntidade::NoMovimento(float moveX, float moveY) {
	//Com excecao do mouse, que eventualmente podera estar parado e ainda e preciso manter o registro de
	//colisao ou posicao, o TIPO_ENTIDADE_CURSOR passa a checagem dessa funcao
	if (moveX == 0 && moveY == 0 && tipo != TIPO_ENTIDADE_CURSOR) return;
	
	double novoX = 0;
	double novoY = 0;

	moveX *= FFPS::FPSControle.GetFatorVelocidade();
	moveY *= FFPS::FPSControle.GetFatorVelocidade();
	
	if (moveX != 0) {
		if (moveX >= 0) novoX = FFPS::FPSControle.GetFatorVelocidade();
		else novoX = -FFPS::FPSControle.GetFatorVelocidade();
	}
	
	if (moveY != 0) {
		if (moveY >= 0) novoY = FFPS::FPSControle.GetFatorVelocidade();
		else novoY = -FFPS::FPSControle.GetFatorVelocidade();
	}
	while(true) {
		if (flags & ENTIDADE_FLAG_FANTASMA) {
			PosValido( (int)(x + novoX), (int)(y + novoY)); //se for fantasma nao importa a colisao, mas precisa enviar eventos para outras entidades
			x += novoX;
			y += novoY;
		} else {
			if(PosValido((int)(x + novoX), (int)(y))) {
				x += novoX;
			} else {
				velX = 0;
			}
			
			if(PosValido((int)(x), (int)(y + novoY))) {
				y += novoY;
			} else {
				velY = 0;
			}
		}
		
		moveX += -novoX;
		moveY += -novoY;
		
		if (novoX > 0 && moveX <= 0) novoX = 0;
		if (novoX < 0 && moveX >= 0) novoX = 0;

		if (novoY > 0 && moveY <= 0) novoY = 0;
		if (novoY < 0 && moveY >= 0) novoY = 0;
		
		if (moveX == 0) novoX = 0;
		if (moveY == 0) novoY = 0;
		
		if (moveX == 0 && moveY == 0) break;
		if (novoX == 0 && novoY == 0) break;
		
	}
	
}
/**
 * Para o movimento de uma entidade gradualmente, reduzindo a aceleracao
 **/
void FEntidade::PararMovimento() {
	if (velX > 0) {
		acelX = -1;
	}
	if (velX < 0) {
		acelX = 1;
	}
	if (velY < 0) {
		acelY = -1;
	}
	if (velY > 0) {
		acelY = 1;
	}
	
	if(velX < 2.0f && velX > -2.0f) {
		acelX = 1;
		velX = 1;
	}
	if(velY < 2.0f && velY > -2.0f) {
		acelY = 1;
		velY = 1;
	}
}


void FEntidade::SetAcel(float acelX, float acelY) {
		this->acelX = acelX;
		this->acelY = acelY;
}
float FEntidade::GetAcelX() {
	return this->acelX;
}
float FEntidade::GetAcelY() {
	return this->acelY;
}

/**
 * Verifica se há colisao entre a entidade com os argumentos passados (x,y,w,h)
 **/
bool FEntidade::Colisoes(int oX, int oY, int oW, int oH) {
	int esquerda1, esquerda2;
	int direita1, direita2;
	int topo1, topo2;
	int base1, base2;
	
	int tX = (int) x + colX;
	int tY = (int) y + colY;
	esquerda1 = tX;
	esquerda2 = oX;
	direita1 = esquerda1 + width - 1 - colWidth;
	direita2 = oX + oW - 1;
	
	topo1 = tY;
	topo2 = oY;
	
	base1 = topo1 + height - 1 - colHeight;
	base2 = oY + oH - 1;
	
	if (base1 < topo2) return false;
	if (topo1 > base2) return false;
	
	if (direita1 < esquerda2) return false;
	if (esquerda1 > direita2) return false;
	
	return true;
	
}
/**
 * Modifica a area de colisao de uma entidade, por padrao a area de colisao eh igual a area
 * da Entidade, mas há casos onde eh necessario alterar apenas a area de colisao
 */
void FEntidade::colBox(int x, int y, int width, int height) {
	this->colX = x;
	this->colY = y;
	this->colWidth = width;
	this->colHeight = height;
}

/**
 * Verifica a validade da nova posicao
 * Se eh possivel se mover para proxima posicao
 **/
bool FEntidade::PosValido(int novoX, int novoY) {
	bool retorno = true;

	if (flags & ENTIDADE_FLAG_SOMENTEMAPA) {
	} else {
		for (int i = 0;i < (int)listaEntidades.size();i++) {
			if (PosValidoEntidade(listaEntidades[i], novoX, novoY) == false) {
				retorno = false;
			}
		}
	}
	
	return retorno;
}


/**
 * Verifica se a posicao valida com outra entidade, caso nao seja cria uma colisao na lista
 **/
bool FEntidade::PosValidoEntidade(FEntidade * entidade, int novoX, int novoY) {
	bool retorno = true;
	if (this != entidade && entidade != NULL && entidade->morto == false
		&& (entidade->flags ^ ENTIDADE_FLAG_SOMENTEMAPA)
		&& entidade->Colisoes(novoX + colX, novoY + colY, width - colWidth - 1, height - colHeight - 1) == true) {
			FEntidadeColisao entidadeColisao;

			entidadeColisao.entidadeA = this;
			entidadeColisao.entidadeB = entidade;

			FEntidadeColisao::listaEntidadesColisoes.push_back(entidadeColisao);
			retorno = false;
	}

	return retorno;
}


/**
 * Metodos para rotacionar e escalonar a entidade
 **/
bool FEntidade::RotaZoom(double angulo, double zoom, int smooth, int centerX, int centerY) {
	Excecoes::linhaErro = 425;
	Excecoes::classErro = "FEntidade::RotaZoom";
	Excecoes::msgErro.clear();
	bool retorno = true;

	SDL_Surface * _sup = NULL;
	SDL_Surface * _temp_sup = NULL;

	try {
		if (superficieEntidade == NULL) throw Excecoes::TratamentoExcecao();
		if (superficieEntidade_Original == NULL) throw Excecoes::TratamentoExcecao();

		//libera superficie antiga
		SDL_FreeSurface(superficieEntidade);
		if ((_sup = rotozoomSurface( superficieEntidade_Original, angulo, zoom, smooth)) == NULL) {
			Excecoes::msgErro = "Nao foi possivel aplicar rotozoomSurface";
			throw Excecoes::TratamentoExcecao();
		}

		if (( superficieEntidade = SDL_DisplayFormatAlpha(_sup)) == NULL) throw Excecoes::TratamentoExcecao();

		this->width = superficieEntidade->w;
		this->height = superficieEntidade->h;
		this->x = this->oX;
		this->y = this->oY;
		this->x-=  (_sup->w / 2) - (superficieEntidade_Original->w / 2) + centerX;
		this->y-= (_sup->h / 2) - (superficieEntidade_Original->h / 2) + centerY;

	} catch (int e) {
		retorno = false;
	}
	SDL_FreeSurface(_sup);
	SDL_FreeSurface(_temp_sup);
	return retorno;
}

bool FEntidade::Rotacionar(double angulo, int centerX, int centerY) {
	return RotaZoom(angulo, 1,0,centerX, centerY);
}

bool FEntidade::Escalonar(double zoom, int centerX, int centerY) {
	return RotaZoom(0,zoom,0,centerX, centerY);
}


/**
 * Implementacao do FEntidadeTexto
 **/
FEntidadeTexto::FEntidadeTexto() : FEntidade() {
	fonteEntidade = NULL;
}
/**
 * Carrega um recurso na entidade (uma fonte)
 **/
bool FEntidadeTexto::NoCarregar (char * arquivo, string texto, int tam, SDL_Color corTexto) {
	Excecoes::linhaErro = 474;
	Excecoes::classErro = "FEntidadeTexto::NoCarregar";
	Excecoes::msgErro.clear();
	bool retorno = true;
	try {
		if ((fonteEntidade = FFonte::NoCarregar(arquivo, tam)) == NULL) throw Excecoes::TratamentoExcecao();
		if (FEntidadeTexto::NoCarregar(fonteEntidade,texto,corTexto) == false) throw Excecoes::TratamentoExcecao();
	} catch (...) {
		retorno = false;
	}
	return retorno;
}
bool FEntidadeTexto::NoCarregar (TTF_Font * fonte, string texto, SDL_Color corTexto) {
	Excecoes::linhaErro = 487;
	Excecoes::classErro = "FEntidadeTexto::NoCarregar";
	Excecoes::msgErro.clear();
	bool retorno = true;
	try {
		if ((fonteEntidade = fonte) == NULL) throw Excecoes::TratamentoExcecao();
		if (TTF_SizeText(fonteEntidade, texto.c_str(), &this->width, &this->height) == -1) {
			Excecoes::msgErro+="Nao foi possivel aplicar TTF_SizeText "
			Excecoes::msgErro+= SDL_GetError();
			throw Excecoes::TratamentoExcecao();
		}

		this->tipo = TIPO_ENTIDADE_TEXTO;
	    this->texto = texto;
		this->corTexto = corTexto;

	} catch(...) {
		retorno = false;
	}
	return retorno;
}
void FEntidadeTexto::NaRenderizacao(SDL_Surface * planoExibicao) {
	Excecoes::linhaErro = 509;
	Excecoes::classErro = "FEntidadeTexto::NaRenderizacao";
	Excecoes::msgErro.clear();

	FEntidade::NaRenderizacao(planoExibicao);
	try {
		if (planoExibicao == NULL) throw Excecoes::TratamentoExcecao();
		if (fonteEntidade == NULL) throw Excecoes::TratamentoExcecao();
		if ((FFonte::NoEscrever(planoExibicao,fonteEntidade,texto,x,y,corTexto)) == false) throw Excecoes::TratamentoExcecao();
	} catch (...) {
		return;
	}
	return;
}
void FEntidadeTexto::NaLimpeza() {
	FEntidade::NaLimpeza();
	//essa eh a funcao para fechar o recurso de uma fonte, mas ela ta causando erro no programa
	//if (fonteEntidade)
	//	TTF_CloseFont(fonteEntidade);
	fonteEntidade = NULL;
}
void FEntidadeTexto::MudaTexto(string texto) {
	this->texto = texto;
}


/**
 * Implementacao do FEntidadeBotao
 **/
FEntidadeBotao::FEntidadeBotao() : FEntidadeTexto() {
	this->corTextoAlterada.r = 0;
	this->corTextoAlterada.g = 0;
	this->corTextoAlterada.b = 0;
	this->cursorSobre = false;
	
	this->deslocamentoX = 0;
	this->deslocamentoY = 0;

	this->acao = 0;
	this->cliqueDireito = 0;
	this->cliqueEsquerdo = 0;
}
void FEntidadeBotao::NoLaco() {
	//forca a alteracao de cor sempre ser falsa
	this->cursorSobre = false;
}
void FEntidadeBotao::NaRenderizacao(SDL_Surface * planoExibicao) {
	Excecoes::linhaErro = 557;
	Excecoes::classErro = "FEntidadeBotao::NaRenderizacao";
	Excecoes::msgErro.clear();

	FEntidade::NaRenderizacao(planoExibicao);
	try {
		if (planoExibicao == NULL) throw Excecoes::TratamentoExcecao();
		if (fonteEntidade == NULL) throw Excecoes::TratamentoExcecao();

		if ((FFonte::NoEscrever(planoExibicao,fonteEntidade,texto,x + (this->cursorSobre ? this->deslocamentoX : 0),y + (this->cursorSobre ? this->deslocamentoY : 0),(this->cursorSobre ? this->corTextoAlterada : this->corTexto ))) == false) throw Excecoes::TratamentoExcecao();

	} catch (...) {
		return;
	}
	return;
}
bool FEntidadeBotao::NaColisao(FEntidade * entidade) {
	switch(entidade->tipo) {
		case TIPO_ENTIDADE_CURSOR:
			this->MudaCor();
			if (entidade->clique) {
					FGerenciadorEstados::SetEstadoAtivo(this->cliqueDireito);
					entidade->clique = false;
			}
			break;
	}
	return true;
}


void FEntidadeBotao::MudaCor() {
	this->cursorSobre = true;
}
void FEntidadeBotao::AoPassarPorCima(SDL_Color corTexto, int deslocaX, int deslocaY) {
	this->corTextoAlterada = corTexto;
	this->deslocamentoX = deslocaX;
	this->deslocamentoY = deslocaY;
}
void FEntidadeBotao::AoClicarDireito(int acao) {
	this->cliqueDireito = acao;
}
void FEntidadeBotao::AoClicarEsquerdo(int acao) {
	this->cliqueEsquerdo = acao;
}
