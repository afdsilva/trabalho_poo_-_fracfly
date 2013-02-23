#include "FNave.h"

FNave::FNave() {
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
	//por emquanto a nave na tem animação nenhuma
	controleAnimacao.maxFrames = 0;
	//FEntidade::NaAnimacao();
	FEntidade::controleAnimacao.NaAnimacao();

}
bool FNave::NaColisao(FEntidade * entidade) {
	return true;
}
