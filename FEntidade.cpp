#include "FEntidade.h"

std::vector<FEntidade*> FEntidade::listaEntidades;
std::vector<FEntidadeColisao> FEntidadeColisao::listaEntidadesColisoes;

FEntidadeColisao::FEntidadeColisao() {
		entidadeA = NULL;
		entidadeB = NULL;
}

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

FEntidade::~FEntidade() {
}

SDL_Surface *FEntidade::getSurface(){
	return superficieEntidade;
	}

void FEntidade::setSurface(SDL_Surface * novaSuperficie){
	superficieEntidade = novaSuperficie;
}	
bool FEntidade::NoCarregar (char * arquivo, int width, int height, int maxFrames) {
	if ((superficieEntidade = FSuperficie::NoCarregar(Arquivo)) == NULL) {
		return false;
	}
	FSuperficie::Transparencia(superficieEntidade, 255, 0, 255);
	
	this->width = width;
	this->height = height;
	
	controleAnimacao.maxFrames = maxFrames;
	
	return true;
}

void FEntidade::NoLaco() {
	if (moveEsquerda == false && moveDireita == false) {
		PararMovimento();
	}
	if (moveEsquerda)
		acelX = -0.5;
	else if (moveDireita)
		acel = 0.5;
	
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

void FEntidade::NaRenderizacao(SDL_Surface * planoExibicao) {
	if (superficieEntidade == NULL || planoExibicao == NULL) return;
	
	FSuperficie::NoDesenhar(planoExibicao, superficieEntidade, X - FCamera::ControleCamera.GetX(), Y - FCamera::ControleCamera.GetY(), frameAtualCol * width, (frameAtualLinha + controleAnimacao.GetFrameAtual() * height, width, height);
}

void FEntidade::NaLimpeza() {
	if(superficieEntidade) {
		SDL_FreeSurface(superficieEntidade);
	}
	superficieEntidade = NULL;
}

void FEntidade::NaAnimacao() {
	if (moveEsquerda) {
		frameAtualCol = 0;
	} else if (moveDireita) {
		frameAtualCol = 1;
	}
	controleAnimacao.NaAnimacao();
}

void FEntidade::NaColisao(FEntidade * entidade) {
	
}

void NoMovimento(float moveX, float moveY) {
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
void FEntidade::Colisoes(int oX, int oY, int oW, int oH) {
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

bool FEntidade::PosValido(int novoX, int novoY) {
	bool retorno = true;
	int inicioX = (novoX + colX) / TAMANHO_AZULEJO;
	int inicioY = (novoY + colY) / TAMANHO_AZULEJO;
	
	int fimX = (novoX + colX) + width - colWidth - 1) / TAMANHO_AZULEJO;
	int fimY = (novoY + colY) + height - colHeight - 1) / TAMANHO_AZULEJO;
	
	for (int iY = inicioY; iY <= endY; iY++) {
		for (int iX = inicioX; iX <= fimX; iX++) {
			FAzulejo * Azulejo = FArea::ControleArea.GetAzulejo(iX * TAMANHO_AZULEJO, iY * TAMANHO_AZULEJO);
			if (PosValidoAzulejo(Azulejo) == false) {
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

bool FEntidade::PosValidoAzulejo(FAzulejo * azulejo) {
	if (azulejo == NULL) {
		return true;
	}
	if (azulejo->tipoId == AZULEJO_TIPO_BLOCO) {
		return false;
	}
	
	return true;
}

bool FEntidade::Rotacionar(double angulo, double zoom, int smooth) {
	if(superficieEntidade == NULL) {
		return false;
	}
	FSuperficie::Rotacionar(superficieEntidade, angulo, zoom, smooth);
	return true;
}
