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
	
	x = 0;
	y = 0;
	
	width = 0;
	height = 0;
	
	moveCima = false;
	moveBaixo = false;
	moveDireita = false;
	moveEsquerda = false;
	
	tipo = TIPO_ENTIDADE_GENERICO;
	
	morto = false;
	flags = ENTIDADE_FLAG_GRAVIDADE;
	
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
}

/**
 * retorna a superficie de uma entidade
 * criado para o metodo rotate, porem agora sem um uso especifico
 **/
SDL_Surface * FEntidade::GetSuperficie(){
	return superficieEntidade;
	}

/**
 * Seta uma superficie de uma entidade
 * criado para o metodo rotate, porem agora sem um uso especifico
 **/
void FEntidade::SetSuperficie(SDL_Surface * novaSuperficie){
	superficieEntidade = novaSuperficie;
}	

/**
 * Carrega um recurso na entidade (a princio imagem)
 **/
bool FEntidade::NoCarregar (char * arquivo, int width, int height, int maxFrames) {
	if ((superficieEntidade = FSuperficie::NoCarregar(arquivo)) == NULL) {
		return false;
	}
	FSuperficie::Transparencia(superficieEntidade, 255, 0, 255);
	
	this->width = width;
	this->height = height;
	
	controleAnimacao.maxFrames = maxFrames;
	
	return true;
}

/**
 * Controla o fluxo de dados da entidade durante o Laço
 **/
void FEntidade::NoLaco() {
	if (moveEsquerda == false && moveDireita == false) {
		PararMovimento();
	}
	
	if (moveEsquerda) {
		acelX = -0.5;
	}
	else if (moveDireita) {
		acelX = 0.5;
	}
	if (flags & ENTIDADE_FLAG_GRAVIDADE) {
		acelY = 0.75f;
	}
	
	velX += acelX * FFPS::FPSControle.GetFatorVelocidade();
	velY += acelY * FFPS::FPSControle.GetFatorVelocidade();

	if (velX > velMaxX) velX = velMaxX;
	if (velX < -velMaxX) velX = -velMaxX;
	if (velY > velMaxY) velY = velMaxY;
	if (velY < -velMaxY) velY = -velMaxY;
	NaAnimacao();
	NoMovimento(velX, velY);
}

/**
 * Controla a renderização na tela da entidade
 **/
void FEntidade::NaRenderizacao(SDL_Surface * planoExibicao) {
	if (superficieEntidade == NULL || planoExibicao == NULL) return;
	
	FSuperficie::NoDesenhar(	planoExibicao, 	superficieEntidade, 	x - FCamera::controleCamera.GetX(), 	y - FCamera::controleCamera.GetY(), 	frameAtualCol * width, 		(frameAtualLinha + controleAnimacao.GetFrameAtual()) * height, 	width, 	height);
}
/**
 * Coletor de Lixo da entidade
 **/
void FEntidade::NaLimpeza() {
	if(superficieEntidade) {
		SDL_FreeSurface(superficieEntidade);
	}
	superficieEntidade = NULL;
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
	if (moveX == 0 && moveY == 0) return;
	
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
	
	if(velX < 2.0f && velX > -2.0f) {
		acelX = 0;
		velX = 0;
	}
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
 * Verifica a validade da nova posicao
 * Se eh possivel se mover para proxima posicao
 **/
bool FEntidade::PosValido(int novoX, int novoY) {
	bool retorno = true;
	int inicioX = (novoX + colX) / TAMANHO_AZULEJO;
	int inicioY = (novoY + colY) / TAMANHO_AZULEJO;
	
	int fimX = ((novoX + colX) + width - colWidth - 1) / TAMANHO_AZULEJO;
	int fimY = ((novoY + colY) + height - colHeight - 1) / TAMANHO_AZULEJO;
	
	for (int iY = inicioY; iY <= fimY; iY++) {
		for (int iX = inicioX; iX <= fimX; iX++) {
			FAzulejo * azulejo = FArea::controleArea.GetAzulejo(iX * TAMANHO_AZULEJO, iY * TAMANHO_AZULEJO);
			if (PosValidoAzulejo(azulejo) == false) {
				retorno = false;
			}
		}
	}
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
 * Verifica a validade de um Azulejo (tile)
 **/
bool FEntidade::PosValidoAzulejo(FAzulejo * azulejo) {
	if (azulejo == NULL) {
		return true;
	}
	if (azulejo->tipoId == AZULEJO_TIPO_BLOCO) {
		return false;
	}
	
	return true;
}

/**
 * Verifica se a posicao valida com outra entidade, caso nao seja cria uma colisao na lista
 **/
bool FEntidade::PosValidoEntidade(FEntidade * entidade, int novoX, int novoY) {
	if (this != entidade && entidade != NULL && entidade->morto == false
		&& entidade->flags ^ ENTIDADE_FLAG_SOMENTEMAPA 
		&& entidade->Colisoes(novoX + colX, novoY + colY, width - colWidth - 1, height - colHeight - 1) == true) {
			FEntidadeColisao entidadeColisao;
			
			entidadeColisao.entidadeA = this;
			entidadeColisao.entidadeB = entidade;
			
			FEntidadeColisao::listaEntidadesColisoes.push_back(entidadeColisao);
			return false;
	}
	
	return true;
}


/**
 * Metodo para rotacionar a entidade, nao utilizado mais (por enquanto)
 ** /
bool FEntidade::Rotacionar(double angulo, double zoom, int smooth) {
	if(superficieEntidade == NULL) {
		return false;
	}
	FSuperficie::Rotacionar(superficieEntidade, angulo, zoom, smooth);
	return true;
}
**/
