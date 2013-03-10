#include "FNave.h"

FNave::FNave() {
	tipo = TIPO_ENTIDADE_JOGADOR;
	vida = 100;
	escudo = 100;
	escore = 0;
	forca = 10;

	atirandoEsquerda = false;
	atirandoDireita = false;
}

bool FNave::NoCarregar(char * arquivo, int width, int height, int maxFrames) {
	if (FEntidade::NoCarregar(arquivo,width,height,maxFrames) == false) {
		return false;
	}
	return true;
}
void FNave::NoLaco() {
	FEntidade::NoLaco();
}
void FNave::NaRenderizacao(SDL_Surface * planoExibicao) {
	FEntidade::NaRenderizacao(planoExibicao);
}
void FNave::NaLimpeza() {
	FEntidade::NaLimpeza();
}
void FNave::NaAnimacao() {
	//por enquanto a nave na tem animação nenhuma
	controleAnimacao.maxFrames = 0;
	//FEntidade::NaAnimacao();
	FEntidade::controleAnimacao.NaAnimacao();

}
bool FNave::NaColisao(FEntidade * entidade) {
	return true;
}

bool FNave::Atirar(FEntidade * entidade, float x, float y, int aX, int aY) {
	if (entidade == NULL) {
		return false;
	}
	FEntidade * tiro = new FEntidade();
	char tiroArquivo[] = "res/tiro_1.png";
	if (tiro->NoCarregar(tiroArquivo,109,109,0) == false) {
		return false;
	}

	tiro->tipo = TIPO_ENTIDADE_TIRO;
	tiro->flags = ENTIDADE_FLAG_FANTASMA;
	tiro->x = x;
	tiro->y = y;
	tiro->movePraX = aX;
	tiro->movePraY = aY;
	tiro->velMaxX = 100;
	tiro->velMaxY = 100;

	this->atirandoEsquerda = true;
	this->atirandoDireita = true;

	float distancia = sqrt((float)pow( (x < aX ? aX - x : -aX + x) ,2) + (float)pow((y > aY ? aY - y : -aY + y),2));

	float acelX = (x > aX ? -1 : 1) * ((float)(x > aX ? x - aX : (-x + aX)) / (float) distancia);
	float acelY = (y < aY ? -1 : 1) * ((float)(y < aY ? y - aY : (-y + aY)) / (float) distancia);
	tiro->SetAcel(acelX, acelY);

	FEntidade::listaEntidades.push_back(tiro);
	return true;
}

int FNave::GetEscore() {
	return this->escore;
}
void FNave::SetEscore(int escore) {
	this->escore = escore;
}
