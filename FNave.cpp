#include "FNave.h"

FNave::FNave() {
	tipo = TIPO_ENTIDADE_JOGADOR;
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

bool FNave::Atirar(FEntidade * entidade, int aX, int aY) {
	if (entidade == NULL) {
		return false;
	}
	FEntidade * tiro = new FEntidade();
	char tiroArquivo[] = "res/tiro1.png";
	if (tiro->NoCarregar(tiroArquivo,16,59,0) == false) {
		return false;
	}

	float x = entidade->x + (entidade->width / 2);
	float y = entidade->y;

	tiro->tipo = TIPO_ENTIDADE_TIRO;
	tiro->flags = ENTIDADE_FLAG_FANTASMA;
	tiro->x = x;
	tiro->y = y;
	tiro->movePraX = aX;
	tiro->movePraY = aY;

	float distancia = sqrt((float)pow( (x < aX ? aX - x : -aX + x) ,2) + (float)pow((y > aY ? aY - y : -aY + y),2));

	float acelX = (x > aX ? -1 : 1) * ((float)(x > aX ? x - aX : (-x + aX)) / (float) distancia);
	float acelY = (y < aY ? -1 : 1) * ((float)(y < aY ? y - aY : (-y + aY)) / (float) distancia);
	tiro->SetAcel(acelX, acelY);

	FEntidade::listaEntidades.push_back(tiro);
	return true;
}
